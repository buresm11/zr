
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
	Type type;
	TypeContent type_content;

public:

	ValueContent(Type t, TypeContent tc) : type(t), type_content(tc) {  }

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

	TypeContent get_content_type() const
	{
		return type_content;
	}

	Type get_type()
	{
		return type;
	}

	virtual void print()
	{
		if(is_bottom()) std::cout << "bottom";
		else if(is_top())std::cout << "Top";
		else if(is_const())std::cout << "const::";
	} 
};

class IntValueContent : public ValueContent
{
	int value;

public:

	IntValueContent(TypeContent tc) : ValueContent(Type::IntType, tc) { }

	IntValueContent(TypeContent tc, int v) : ValueContent(Type::IntType, tc), value(v) { }

	int get_value() const
	{
		return value;
	}

	bool merge(IntValueContent * other)
	{
		if(is_top()) return false;

		if(is_bottom())
		{
			if(other->is_bottom()) return false;

			type_content = other->get_content_type();
			value = other->get_value();
		}

		if(is_const())
		{
			if(other->is_const() && value == other->get_value()) return false;
			if(other->is_const() || other->is_top()) { type_content = TypeContent::Top; return true; }
			if(other->is_bottom()) return false;
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

class BoolValueContent : public ValueContent
{
	bool value;

public:
	
	BoolValueContent(TypeContent tc) : ValueContent(Type::BoolType, tc) { }

	BoolValueContent(TypeContent tc, bool v) : ValueContent(Type::BoolType, tc), value(v) { }

	bool get_value() const
	{
		return value;
	}

	bool merge(BoolValueContent * other)
	{
		if(is_top()) return false;

		if(is_bottom())
		{
			if(other->is_bottom()) return false;

			type_content = other->get_content_type();
			value = other->get_value();
		}

		if(is_const())
		{
			if(other->is_const() && value == other->get_value()) return false;
			if(other->is_const() || other->is_top()) { type_content = TypeContent::Top; return true; }
			if(other->is_bottom()) return false;
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
	std::map<llvm::Value *, ValueContent *> state;

public:
	State() { }

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
        for (auto i : other->state) 
        {
            auto j = state.find(i.first);
            if (j == state.end()) 
            {
                changed = true;
                state.insert(i);
            } 
            else 
            {
            	if(j->second->get_type() == Type::IntType) ((IntValueContent*)j->second)->merge((IntValueContent*)(i.second));
            	else if(j->second->get_type() == Type::BoolType) ((BoolValueContent*)j->second)->merge((BoolValueContent*)(i.second));
            }
        }
        return changed;
	}

	void print()
	{
		std::cout << "/------------------/" << size() << std::endl;
		for ( auto it = state.begin(); it != state.end(); ++it  )
		{
		   //std::cout << print_inst_type(it->first) << "   ";
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
        return "Analysis";
    }

    State * get_state(llvm::BasicBlock * basic_block)
    {
    	if(bb_value.find(basic_block) == bb_value.end()) return NULL;
    	else return bb_value[basic_block];
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

            llvm::Instruction * last_instr = &bb->back();
            std::vector<llvm::BasicBlock *> sucessors;

            if(llvm::BranchInst * br_inst = llvm::dyn_cast<llvm::BranchInst>(last_instr))
            {
            	if(!br_inst->isConditional())
            	{
            		sucessors.push_back(br_inst->getSuccessor(0));
            	}
            	else if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(br_inst->getOperand(0)))
            	{
            		if(ci->getSExtValue() == 0) 
            		{
            			sucessors.push_back(br_inst->getSuccessor(1));
            		}
            		else
            		{
            			sucessors.push_back(br_inst->getSuccessor(0));
            		}
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
	            		{
	            			sucessors.push_back(br_inst->getSuccessor(1));
	            		}
	            		else
	            		{
	            			sucessors.push_back(br_inst->getSuccessor(0));
	            		}
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
            		std::cout << "continue to" << succ->getName().lower() << std::endl;

            		if(bb_value.find(succ) == bb_value.end()) bb_value[succ] = new State();
	                if (bb_value[succ]->merge(state))
	                {
	                    bb_queue.push_back(succ);
	                }
            	}
            }
            else if (llvm::ReturnInst * ret_inst = llvm::dyn_cast<llvm::ReturnInst>(last_instr)) { }
		}

		return false;
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

	void process_instruction(llvm::Instruction * ins, State * state)
	{
		if (llvm::LoadInst * inst = llvm::dyn_cast<llvm::LoadInst>(ins))
		{
			std::cout << "load" << std::endl;

			if(state->has(inst->getOperand(0)))
			{
				std::cout << "load" << std::endl;
				state->add(inst, state->get(inst->getOperand(0)));
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
			std::cout << "store" << std::endl;

			if (llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(inst->getOperand(0))) 
			{
				if(inst->getOperand(0)->getType() == Compiler::t_int){
					state->add(inst->getOperand(1), new IntValueContent(TypeContent::Const, ci->getSExtValue()));}
				else if(inst->getOperand(0)->getType() == Compiler::t_bool)
					state->add(inst->getOperand(1), new BoolValueContent(TypeContent::Const, ci->getSExtValue()));
			}
			else
			{
				if(state->has(inst->getOperand(0))) state->add(inst->getOperand(1), state->get(inst->getOperand(0)));
				else
				{
					std::cout << "Should never happen 12" << inst->getName().lower() << std::endl;
				}
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
        	std::cout << "bin" << std::endl;

        	if(inst->getOperand(0)->getType() == Compiler::t_int && inst->getOperand(1)->getType() == Compiler::t_int)
        		process_int_binary(inst, state);
        	else if(inst->getOperand(0)->getType() == Compiler::t_bool && inst->getOperand(1)->getType() == Compiler::t_bool)
        		process_bool_binary(inst, state);
        }
        else if (llvm::ICmpInst * inst = llvm::dyn_cast<llvm::ICmpInst>(ins)) 
        {
        	std::cout << "cmp" << std::endl;

        	if(inst->getOperand(0)->getType() == Compiler::t_int && inst->getOperand(1)->getType() == Compiler::t_int)
        		process_int_cmp(inst, state);
        	else if(inst->getOperand(0)->getType() == Compiler::t_bool && inst->getOperand(1)->getType() == Compiler::t_bool)
        		process_bool_cmp(inst, state);
        }
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
        State * state = new State();
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

        for (llvm::BasicBlock & b : F) 
        {
        	State * state = a.get_state(&b);
        	if(state == NULL) continue;

            for (llvm::Instruction & i : b) 
            {
            	if(i.getType()->isPointerTy()) continue;
            	if(!state->has(&i)) continue;

            	ValueContent * value_content = state->get(&i);

            	if(value_content->get_type() == Type::IntType)
            	{
            		IntValueContent * int_value_content = (IntValueContent*) value_content; 

            		if(int_value_content->is_const()) 
            		{
            			i.replaceAllUsesWith(llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32, int_value_content->get_value())));
            			changed = true;
            		}
            	}	
            	else if(value_content->get_type() == Type::BoolType)
            	{
            		BoolValueContent * bool_value_content = (BoolValueContent*) value_content;

            		if(bool_value_content->is_const()) 
            		{
            			if(bool_value_content->get_value())
            				i.replaceAllUsesWith(llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(1, 1))); 
            			else
            				i.replaceAllUsesWith(llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(1, 0))); 

            			changed = true;
            		}
            	}

            }
        }

		return changed;
	}
};