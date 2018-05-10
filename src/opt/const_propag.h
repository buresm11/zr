
#pragma once

#include <iostream>

#include "llvm.h"
#include "Compiler.h"

enum class TypeContent 
{
    Top,
    Bottom,
    Const
};

class ValueContent
{

protected:
	llvm::Type * type;
	TypeContent type_content;

public:

	ValueContent(llvm::Type * t, TypeContent tc) : type(t), type_content(tc) {  }

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

	TypeContent get_content_type()
	{
		return type_content;
	}

	llvm::Type * get_type()
	{
		return type;
	}

	virtual void print() =  0;

	virtual ValueContent * copy() = 0;
};

class IntValueContent : public ValueContent
{
	int value;
public:

	IntValueContent(TypeContent tc) : ValueContent(Compiler::t_int, tc) { }
	IntValueContent(TypeContent tc, int v) : ValueContent(Compiler::t_int, tc), value(v) { }

	bool merge(IntValueContent * other)
	{
		if(is_top()) return false;

		if(is_bottom())
		{
			if(other->is_bottom()) return false;

			type_content = other->get_content_type();
			value = other->get_value();

			return true;
		}

		if(is_const())
		{
			if(other->is_const() && value == other->get_value()) return false;
			if(other->is_const() || other->is_top()) { type_content = TypeContent::Top; return true; }
			if(other->is_bottom()) return false;
		}

		return false;
	}

	int get_value()
	{
		return value;
	}

	void print() override
	{
		if(is_bottom()) std::cout << "Bottom::";
		else if(is_top())std::cout << "Top::";
		else if(is_const())std::cout << "Const::" << value;
	} 

	ValueContent * copy() override
	{
		return new IntValueContent(get_content_type(), get_value());
	}
};

class BoolValueContent : public ValueContent
{
	bool value;
public:
	
	BoolValueContent(TypeContent tc) : ValueContent(Compiler::t_bool, tc) { }
	BoolValueContent(TypeContent tc, bool v) : ValueContent(Compiler::t_bool, tc), value(v) { }

	bool merge(BoolValueContent * other)
	{
		if(is_top()) return false;

		if(is_bottom())
		{
			if(other->is_bottom()) return false;

			type_content = other->get_content_type();
			value = other->get_value();

			return true;
		}

		if(is_const())
		{
			if(other->is_const() && value == other->get_value()) return false;
			if(other->is_const() || other->is_top()) { type_content = TypeContent::Top; return true; }
			if(other->is_bottom()) return false;
		}

		return false;
	}

	bool get_value() const
	{
		return value;
	}

	void print()
	{
		if(is_bottom()) std::cout << "Bottom::";
		else if(is_top())std::cout << "Top::";
		else if(is_const())std::cout << "Const::" << value;
	}

	ValueContent * copy() override
	{
		return new BoolValueContent(get_content_type(), get_value());
	} 
};

class State
{
	std::map<llvm::Value *, ValueContent *> state;
	std::string name;

public:
	State(std::string name) { this->name = name; }

	void add(llvm::Value * val, ValueContent * content)
	{
		state[val] = content;
	}

	ValueContent * get(llvm::Value * val)
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

	bool merge(State * other)
	{
		bool changed = false;

		std::map<llvm::Value *, ValueContent *>::iterator other_it = other->state.begin();
		while(other_it != other->state.end())
		{
			std::map<llvm::Value *, ValueContent *>::iterator my_it = state.find(other_it->first);

			if(my_it == state.end())
			{
				state[other_it->first] = other_it->second->copy();
				changed = true;
			}
			else
			{
				bool c;
				if(my_it->second->get_type() == Compiler::t_int) 
					c = ((IntValueContent*)my_it->second)->merge((IntValueContent*)(other_it->second));
            	else if(my_it->second->get_type() == Compiler::t_bool) 
            		c = ((BoolValueContent*)my_it->second)->merge((BoolValueContent*)(other_it->second));

            	if(c) changed = true;
			}
			++other_it;
		}
		return changed;
	}

	void print() // DEBUG
	{
		std::cout << "/------------------/ " << name << size() << std::endl;
		for ( auto it = state.begin(); it != state.end(); ++it  )
		{
		   std::cout << it->first->getName().lower() << " ";
		   it->second->print();
		   std::cout << std::endl;
		} 
		std::cout << "/------------------/" << std::endl;
	}
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
        return "AnalysisConstantPropagation";
    }

    State * get_state(llvm::BasicBlock * basic_block)
    {
    	if(bb_value.find(basic_block) == bb_value.end()) return NULL;
    	else return bb_value[basic_block];
    }

	bool doFinalization(llvm::Module &M) override
    {
    	auto it = bb_value.begin();

		while(it != bb_value.end())
		{
		    delete it->second;
		    ++it;
		}
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

			auto instruction_iter = bb->begin();
			while(instruction_iter != bb->end())
			{
				process_instruction(instruction_iter, state);
				++instruction_iter;
			}

            std::vector<llvm::BasicBlock *> sucessors;
            if(llvm::BranchInst * br_inst = llvm::dyn_cast<llvm::BranchInst>(&bb->back()))
            {
            	if(!br_inst->isConditional())
            	{
            		sucessors.push_back(br_inst->getSuccessor(0));
            	}
            	else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(br_inst->getOperand(0)))
            	{
            		if(ci->getSExtValue() == 0)
            			sucessors.push_back(br_inst->getSuccessor(1));
            		else
            			sucessors.push_back(br_inst->getSuccessor(0));
            	}
            	else if(state->has(br_inst->getOperand(0)))
            	{
            		BoolValueContent * bool_value_content = ((BoolValueContent *) (state->get(br_inst->getOperand(0))));

            		if(!bool_value_content->is_const())
            		{
            			sucessors.push_back(br_inst->getSuccessor(0));
            			sucessors.push_back(br_inst->getSuccessor(1));
            		}
            		else
            		{
	            		if(bool_value_content->get_value() == false)
	            			sucessors.push_back(br_inst->getSuccessor(1));
	            		else
	            			sucessors.push_back(br_inst->getSuccessor(0));
	            	}
            	}
            	else
            	{
            		sucessors.push_back(br_inst->getSuccessor(0));
            		sucessors.push_back(br_inst->getSuccessor(1));
            	}

            	for(int i=0; i < sucessors.size(); i++)
            	{
            		llvm::BasicBlock * succ = sucessors.at(i);

            		if(bb_value.find(succ) == bb_value.end())
            		{
            			bb_value[succ] = new State(succ->getName().lower());
            			bb_value[succ]->merge(state);
            			bb_queue.push_back(succ);
            		}
            		else
            		{
            			if (bb_value[succ]->merge(state))
	                	{
	                    	bb_queue.push_back(succ);
	                	}
            		}
            	}
            }
		}
		return false;
	}

	void process_instruction(llvm::Instruction * ins, State * state)
	{
		if (llvm::LoadInst * inst = llvm::dyn_cast<llvm::LoadInst>(ins))
		{
			if(state->has(inst->getOperand(0)))
			{
				ValueContent * value_content = state->get(inst->getOperand(0));

				state->add(inst, value_content->copy());
			}
			else 
			{
				if(inst->getType() == Compiler::t_int)
					state->add(inst, new IntValueContent(TypeContent::Top));
				else if(inst->getType() == Compiler::t_bool)
					state->add(inst, new BoolValueContent(TypeContent::Top));
			} 
			
		} 
		else if (llvm::StoreInst * inst = llvm::dyn_cast<llvm::StoreInst>(ins)) 
		{
			if(state->has(inst->getOperand(1)))
			{
				if(state->get(inst->getOperand(1))->is_top()) return;
			}

			if (llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0))) 
			{
				if(inst->getOperand(0)->getType() == Compiler::t_int)
					state->add(inst->getOperand(1), new IntValueContent(TypeContent::Const, ci->getSExtValue()));
				else if(inst->getOperand(0)->getType() == Compiler::t_bool)
					state->add(inst->getOperand(1), new BoolValueContent(TypeContent::Const, ci->getSExtValue()));
			}
			else
			{
				ValueContent * value_content = state->get(inst->getOperand(0));

				state->add(inst->getOperand(1), value_content->copy());
			}
        }
        else if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(ins))
        {
        	if(inst->getType() == Compiler::t_int)
				state->add(inst, new IntValueContent(TypeContent::Top));
			else if(inst->getType() == Compiler::t_bool)
				state->add(inst, new BoolValueContent(TypeContent::Top));
        }
        else if (llvm::BinaryOperator * inst = llvm::dyn_cast<llvm::BinaryOperator>(ins)) 
        {
        	if(inst->getOperand(0)->getType() == Compiler::t_int && inst->getOperand(1)->getType() == Compiler::t_int)
        		process_int_binary(inst, state);
        	else if(inst->getOperand(0)->getType() == Compiler::t_bool && inst->getOperand(1)->getType() == Compiler::t_bool)
        		process_bool_binary(inst, state);
        }
        else if (llvm::ICmpInst * inst = llvm::dyn_cast<llvm::ICmpInst>(ins)) 
        {
        	if(inst->getOperand(0)->getType() == Compiler::t_int && inst->getOperand(1)->getType() == Compiler::t_int)
        		process_int_cmp(inst, state);
        	else if(inst->getOperand(0)->getType() == Compiler::t_bool && inst->getOperand(1)->getType() == Compiler::t_bool)
        		process_bool_cmp(inst, state);
        }
	}

	void process_int_binary(llvm::BinaryOperator * inst, State * state)
	{
		IntValueContent * lv;
        IntValueContent * rv;

        if(state->has(inst->getOperand(0))) lv = (IntValueContent *) (state->get(inst->getOperand(0)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0)))
        {
        	IntValueContent * v = new IntValueContent(TypeContent::Const, ci->getSExtValue());
        	lv = v;
        }

        if(state->has(inst->getOperand(1))) rv = (IntValueContent *) (state->get(inst->getOperand(1)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(1)))
        {
        	IntValueContent * v = new IntValueContent(TypeContent::Const, ci->getSExtValue());
           	rv = v;
        }

        if (lv->is_const() && rv->is_const()) 
        {
            switch (inst->getOpcode()) 
            {
	            case llvm::Instruction::Add:
	                state->add(inst, new IntValueContent(TypeContent::Const, lv->get_value() + rv->get_value()));
	                break;
	            case llvm::Instruction::Sub:
	                state->add(inst, new IntValueContent(TypeContent::Const, lv->get_value() - rv->get_value()));
	                break;
	            case llvm::Instruction::Mul:
	                state->add(inst, new IntValueContent(TypeContent::Const, lv->get_value() * rv->get_value()));
	                break;
	            case llvm::Instruction::SDiv:
	                state->add(inst, new IntValueContent(TypeContent::Const, lv->get_value() / rv->get_value()));
	                break;
	            default:
                 	break;
	        }
        }
        else state->add(inst, new IntValueContent(TypeContent::Top));
	}

	void process_bool_binary(llvm::BinaryOperator * inst, State * state)
	{
		BoolValueContent * lv;
        BoolValueContent * rv;

        if(state->has(inst->getOperand(0))) lv = (BoolValueContent *) (state->get(inst->getOperand(0)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0)))
        {
        	BoolValueContent * v = new BoolValueContent(TypeContent::Const, ci->getSExtValue());
        	lv = v;
        }

        if(state->has(inst->getOperand(1))) rv = (BoolValueContent *) (state->get(inst->getOperand(1)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(1)))
        {
        	BoolValueContent * v = new BoolValueContent(TypeContent::Const, ci->getSExtValue());
           	rv = v;
        }

        if (lv->is_const() && rv->is_const()) 
        {
            switch (inst->getOpcode()) 
            {
	            case llvm::Instruction::And:
	                state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() && rv->get_value()));
	                break;
	            case llvm::Instruction::Or:
	                state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() || rv->get_value()));
	                break;
	            case llvm::Instruction::Xor:
	                state->add(inst, new BoolValueContent(TypeContent::Const, !rv->get_value()));
	                break;

	            default:
                 	break;
	        }
        }
        else state->add(inst, new BoolValueContent(TypeContent::Top));
	}

	void process_int_cmp(llvm::ICmpInst * inst, State * state)
	{
		IntValueContent * lv;
        IntValueContent * rv;

        if(state->has(inst->getOperand(0))) lv = (IntValueContent *) (state->get(inst->getOperand(0)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0)))
        {
        	IntValueContent * v = new IntValueContent(TypeContent::Const, ci->getSExtValue());
        	lv = v;
        }

        if(state->has(inst->getOperand(1))) rv = (IntValueContent *) (state->get(inst->getOperand(1)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(1)))
        {
        	IntValueContent * v = new IntValueContent(TypeContent::Const, ci->getSExtValue());
           	rv = v;
        }

        if (lv->is_const() && rv->is_const()) 
        {
            switch (inst->getSignedPredicate()) 
            {
                case llvm::ICmpInst::ICMP_EQ:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() == rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_NE:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() != rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SGE:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() >= rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SLE:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() <= rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SGT:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() > rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SLT:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() < rv->get_value()));
                    break;
                default:
                    break;
            }
        }
        else state->add(inst, new BoolValueContent(TypeContent::Top));
	}

	void process_bool_cmp(llvm::ICmpInst * inst, State * state)
	{
		BoolValueContent * lv;
        BoolValueContent * rv;

        if(state->has(inst->getOperand(0))) lv = (BoolValueContent *) (state->get(inst->getOperand(0)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0)))
        {
        	BoolValueContent * v = new BoolValueContent(TypeContent::Const, ci->getSExtValue());
        	lv = v;
        }

        if(state->has(inst->getOperand(1))) rv = (BoolValueContent *) (state->get(inst->getOperand(1)));
        else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(1)))
        {
        	BoolValueContent * v = new BoolValueContent(TypeContent::Const, ci->getSExtValue());
           	rv = v;
        }

        if (lv->is_const() && rv->is_const()) 
        {
            switch (inst->getSignedPredicate()) 
            {
                case llvm::ICmpInst::ICMP_EQ:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() == rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_NE:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() != rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SGE:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() >= rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SLE:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() <= rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SGT:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() > rv->get_value()));
                    break;
                case llvm::ICmpInst::ICMP_SLT:
                	state->add(inst, new BoolValueContent(TypeContent::Const, lv->get_value() < rv->get_value()));
                    break;
                default:
                    break;
            }
        }
        else state->add(inst, new BoolValueContent(TypeContent::Top));
	}

	State * init_function(llvm::Function & F)
	{
        State * state = new State("");
        for (auto i = F.arg_begin(), e = F.arg_end(); i != e; ++i)
        {
        	if(i->getType() == Compiler::t_int)
        	{
        		state->add(i, new IntValueContent(TypeContent::Top));
        	}
        	else if(i->getType() == Compiler::t_bool)
        	{
        		state->add(i, new BoolValueContent(TypeContent::Top));
        	}
        }
        return state;
	}
};

class const_propag : public llvm::FunctionPass
{	

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
		bool changed = false;
		analysis & a = getAnalysis<analysis>();

		auto basic_block_iter = F.begin(); 
        while(basic_block_iter != F.end()) 
        {
        	State * state = a.get_state(basic_block_iter);
        	if(state == NULL)
        	{
        		++basic_block_iter;
        		continue;
        	}

            auto instruction_iter = basic_block_iter->begin();
            while(instruction_iter != basic_block_iter->end())
            {
            	if(instruction_iter->getType()->isPointerTy())
            	{
            		++instruction_iter; continue;	
            	} 
            	if(!state->has(instruction_iter)) 
            	{
            		++instruction_iter; continue;
            	}

            	ValueContent * value_content = state->get(instruction_iter);

            	if(value_content->get_type() == Compiler::t_int)
            	{
            		IntValueContent * int_value_content = (IntValueContent*) value_content; 

            		if(int_value_content->is_const()) 
            		{
            			instruction_iter->replaceAllUsesWith(llvm::ConstantInt::get(llvm::getGlobalContext(), 
            					llvm::APInt(32, int_value_content->get_value())));
            			changed = true;
            		}
            	}	
            	else if(value_content->get_type() == Compiler::t_bool)
            	{
            		BoolValueContent * bool_value_content = (BoolValueContent*) value_content;

            		if(bool_value_content->is_const()) 
            		{
            			if(bool_value_content->get_value())
            				instruction_iter->replaceAllUsesWith(llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(1, 1))); 
            			else
            				instruction_iter->replaceAllUsesWith(llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(1, 0))); 

            			changed = true;
            		}
            	}
            	++instruction_iter;
            }
            ++basic_block_iter;
        }
		return changed;
	}
};