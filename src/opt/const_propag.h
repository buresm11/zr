
#pragma once

#include <iostream>

#include "llvm.h"
#include ""

enum class TypeContent 
{
    Top,
    Bottom,
    Const
};

class IntValueContent : public ValueContent
{
public:
	int value;

	int get_value() const
	{
		return value;
	}
};

class BoolValueContent : public ValueContent
{
public:
	bool value;

	bool get_value() const
	{
		return value;
	}
};
class ValueContent
{
	Type type;
	TypeContent type_content;

public:

	ValueContent(Type type, TypeContent type_content) { type_content = TypeContent::Top; }

	bool is_bottom() const
	{
		return type_content == TypeContent::Bottom;
	}

	bool is_top() const
	{
		return type_content == TypeContent::Top;
	}

	bool is_const() const
	{
		return type_content == TypeContent::Const;
	}

	TypeContent get_type() const
	{
		return type_content;
	}

	bool merge(ValueContent const & other)
	{
		if(is_top()) return false;

		if(is_bottom())
		{
			if(other.is_bottom()) return false;

			*this = other;
			return true;
		}

		if(is_const())
		{
			if(other.is_const() && value == other.get_value()) return false;
			if(other.is_const() || other.is_top()) { type_content = TypeContent::Top; return true; }
			if(other.is_bottom()) return false;
		}

		return false;
	}

	void print()
	{
		if(is_bottom()) std::cout << "bottom";
		else if(is_top())std::cout << "Top";
		else if(is_const())std::cout << "const::" << value;
	} 
};

class State
{
	std::map<llvm::Value *, ValueContent> state;

public:
	State() { }

	void add(llvm::Value * val, ValueContent content)
	{
		state[val] = content;
	}

	ValueContent get(llvm::Value * val)
	{
		return state[val];
	}

	bool has(llvm::Value * val)
	{
		return state.find(val) != state.end();
	}

	int size()
	{
		return state.size();
	}

	void print()
	{
		std::cout << "/------------------/" << size() << std::endl;
		for ( auto it = state.begin(); it != state.end(); ++it  )
		{
		   //std::cout << print_inst_type(it->first) << "   ";
		   std::cout << it->first->getName().lower() << " ";
		   it->second.print();
		   std::cout << std::endl;
		} 
		std::cout << "/------------------/" << std::endl;
	}

	/*std::string print_inst_type(llvm::Value * val)
	{
		if (llvm::LoadInst * inst = llvm::dyn_cast<llvm::LoadInst>(ins))
		{
			std::cout << "load" << std::endl;
		} 
		else if (llvm::StoreInst * inst = llvm::dyn_cast<llvm::StoreInst>(ins)) 
		{
			std::cout << "store" << std::endl;

			if(state->has(inst))
			{
				std::cout << "store1" << std::endl;
			}
			else
			{
				std::cout << "store2" << std::endl;

				state->add(inst, ValueContent());
			}
        } 
        else if (llvm::AllocaInst * inst = llvm::dyn_cast<llvm::AllocaInst>(ins)) 
		{
			
        } 
        else if (llvm::BinaryOperator * inst = llvm::dyn_cast<llvm::BinaryOperator>(ins)) 
        {
        	std::cout << "bin" << std::endl;
        }
	}*/
};


class analysis : public llvm::FunctionPass
{
	std::deque<llvm::BasicBlock *> bb_queue;
	std::map<llvm::BasicBlock *, State *> bb_value;

public:
	static char ID;

	analysis() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "Analysis";
    }

	bool runOnFunction(llvm::Function &F)
	{
		bb_queue.clear();
		bb_value.clear();

		llvm::BasicBlock * first = F.begin();
		bb_queue.push_back(first);
		bb_value[first] = init_function(F);
		
		while(!bb_queue.empty())
		{
			llvm::BasicBlock * bb = bb_queue.front();
			bb_queue.pop_front();
			State * state = bb_value[bb];

            for (auto i = bb->begin(), e = bb->end(); i != e; ++i)
                process_instruction(i, state);

            state->print();

			break;
		}

		return false;
	}

	void process_instruction(llvm::Instruction * ins, State * state)
	{
		if (llvm::LoadInst * inst = llvm::dyn_cast<llvm::LoadInst>(ins))
		{
			//state->add(store->getOperand(1)) = currentState_[store->getOperand(0)];
		} 
		else if (llvm::StoreInst * inst = llvm::dyn_cast<llvm::StoreInst>(ins)) 
		{
			std::cout << "store" << std::endl;

			if (llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0))) 
			{
				state->add(inst->getOperand(1), ValueContent(TypeContent::Const, ci->getSExtValue()));
			}
			else state->add(inst->getOperand(1), ValueContent());
			
        } 
        else if (llvm::AllocaInst * inst = llvm::dyn_cast<llvm::AllocaInst>(ins)) 
		{
			
        } 
        else if (llvm::BinaryOperator * inst = llvm::dyn_cast<llvm::BinaryOperator>(ins)) 
        {
        	ValueContent lv;
            ValueContent rv;

            if(state->has(inst->getOperand(0))) lv = state->get(inst->getOperand(0));
            else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0)))
           	{
           		ValueContent v(TypeContent::Const, ci->getSExtValue());
           		lv = v;
           	}

           	if(state->has(inst->getOperand(1))) rv = state->get(inst->getOperand(1));
            else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(1)))
           	{
           		ValueContent v(TypeContent::Const, ci->getSExtValue());
           		rv = v;
           	}

            if (lv.is_const() && rv.is_const()) 
            {
            	switch (inst->getOpcode()) 
             	{
	                case llvm::Instruction::Add:
	                    state->add(inst, ValueContent(TypeContent::Const, lv.get_value() + rv.get_value()));
	                    break;
	                case llvm::Instruction::Sub:
	                    state->add(inst, ValueContent(TypeContent::Const, lv.get_value() - rv.get_value()));
	                    break;
	                case llvm::Instruction::Mul:
	                    state->add(inst, ValueContent(TypeContent::Const, lv.get_value() * rv.get_value()));
	                    break;
	                case llvm::Instruction::SDiv:
	                    state->add(inst, ValueContent(TypeContent::Const, lv.get_value() / rv.get_value()));
	                    break;
	                case llvm::Instruction::And:
	                    state->add(inst, ValueContent(TypeContent::Const, lv.get_value() / rv.get_value()));
	                    break;
	                case llvm::Instruction::Or:
	                    state->add(inst, ValueContent(TypeContent::Const, lv.get_value() / rv.get_value()));
	                    break;
	                default:
                    	break;
	            }
            }
        }
        else if (llvm::ICmpInst * cmp = llvm::dyn_cast<llvm::ICmpInst>(ins)) 
        {
        	ValueContent lv;
            ValueContent rv;

            if(state->has(inst->getOperand(0))) lv = state->get(inst->getOperand(0));
            else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0)))
           	{
           		ValueContent v(TypeContent::Const, ci->getSExtValue());
           		lv = v;
           	}

           	if(state->has(inst->getOperand(1))) rv = state->get(inst->getOperand(1));
            else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(1)))
           	{
           		ValueContent v(TypeContent::Const, ci->getSExtValue());
           		rv = v;
           	}

            if (lv.is_const() && rv.is_const()) 
            {
            	switch (cmp->getSignedPredicate()) 
            	{
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;
	                case llvm::ICmpInst::ICMP_EQ:
	                    break;

	                default:
	                    break;
                }
            }
        }

	}

	State * init_function(llvm::Function & F)
	{
        State * state = new State();
        for (auto i = F.arg_begin(), e = F.arg_end(); i != e; ++i)
        	state->add(i, ValueContent(TypeContent::Top));
        return state;
	}
};

class const_propag : public llvm::FunctionPass
{	
	bool changed;

public:
	static char ID;

	const_propag() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "DeadInstructionRemovalOptimization";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const
    {
    	Info.addRequired<analysis>();
    }

	bool runOnFunction(llvm::Function &F)
	{
		changed = false;
        for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
            	analysis & a = getAnalysis<analysis>();

            	++i;
            }
        }

		return changed;
	}
};