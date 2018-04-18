
#pragma once

#include <iostream>

#include "llvm.h"
#include "Compiler.h"
#include "opt/tail_call.h"

class func_inlining_analysis : public llvm::FunctionPass
{
	std::map<llvm::Function *, bool> cool_to_inline;
	std::map<llvm::Function *, int> function_called;
	int instruction_count;
	int branch_instruction_count;

public:
	static char ID;

	func_inlining_analysis() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "FunctionCallInlineAnalysis";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const
    {
    	//Info.addRequired<tail_call_analysis>();
    }

    bool is_function_cool_to_inline(llvm::Function * function)
    {
    	return cool_to_inline.find(function) != cool_to_inline.end();
    }

	bool runOnFunction(llvm::Function & F)
    {
    	for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
            	instruction_count++;

            	if(llvm::BranchInst * inst = llvm::dyn_cast<llvm::BranchInst>(i))
        		{
        			branch_instruction_count++;
        		}

        		++i;
            }
        }

        cool_to_inline[&F] = true;

        return false;
    }
};

class func_inlining : public llvm::FunctionPass
{

public:
	static char ID;

	func_inlining() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "FunctionCallInline";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const override
    {
    	Info.addRequired<func_inlining_analysis>();
    }

	bool runOnFunction(llvm::Function & F) override
    {
    	bool changed = false;

    	func_inlining_analysis & a = getAnalysis<func_inlining_analysis>();

    	if(!a.is_function_cool_to_inline(&F)) return false;

    	llvm::Module * module = F.getParent();

    	auto function_iter = module->begin();
    	while(function_iter != module->end())
    	{
    		llvm::Function * f = function_iter;
    		if(f == &F)
    		{
    			++function_iter;
    			continue;
    		}

    		auto basic_block_iter = function_iter->begin();

    		while(basic_block_iter != function_iter->end())
    		{
    			auto instruction_iter = basic_block_iter->begin();
    			while(instruction_iter != basic_block_iter->end())
    			{
    				std::cout << "i" << std::endl;
    				if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(instruction_iter))
        			{
        				std::cout << "ckonej" << std::endl;

        				 llvm::Function * called_func = inst->getCalledFunction();

        				 if(called_func != &F)
        				 {
        				 	++instruction_iter; continue;
        				 }

        				 std::cout << "konej" << std::endl;

        				 changed =  replace_call(function_iter, inst, called_func);
        			}
    				++instruction_iter;
    			}
    			++basic_block_iter;
    		}
    		++function_iter;
    	}

    	return changed;
    }

    bool replace_call(llvm::Function * caller_func, llvm::CallInst * call_inst, llvm::Function * callee_func)
    {
    	std::map<llvm::Value *, llvm::Value *> val_to_val;
    	std::vector<llvm::BasicBlock *> new_bb;
    	   	
    	int bb_first = true;;

    	auto basic_block_iter = callee_func->begin(); 
    	while(basic_block_iter != callee_func->end())
    	{
    		llvm::BasicBlock * bb = llvm::BasicBlock::Create(Compiler::llvm_context, "copied", caller_func);
    		new_bb.push_back(bb);
    		val_to_val[basic_block_iter] = bb; 

    		auto instruction_iter = basic_block_iter->begin();
    		if(bb_first) //func header
    		{
    			int args_size = callee_func->arg_size();
		    	
		    	for(int i=0;i < args_size * 2; i++)
		    	{
		    		if(i % 2 == 0)
		    		{
		    			llvm::Instruction * copy = instruction_iter->clone();
		    			bb->getInstList().push_back(copy);
		    			val_to_val[instruction_iter] = copy;
		    		}
		    		else
		    		{

		    			//llvm::StoreInst * si = new llvm::StoreInst(call_inst->getArgOperand(i/2), args.at(i), false, prev);
		    		} 

		    		++instruction_iter;
		    	}
    		}

    		while(instruction_iter != basic_block_iter->end())
    		{
    			llvm::Instruction * copy = instruction_iter->clone();
		    	bb->getInstList().push_back(copy);
		    	val_to_val[instruction_iter] = copy;

    			++instruction_iter;
    		}

    		++basic_block_iter;
    		bb_first = false;
    	}
    	
    	for(int i=0; i < new_bb.size() ; i++)
    	{
    		std::cout << "coolSS:" << new_bb.size() << std::endl;

    		auto instruction_iter = new_bb.at(i)->begin();
    		while(instruction_iter != new_bb.at(i)->end())
    		{
    			auto operand_iter = instruction_iter->op_begin();
    			while (operand_iter != instruction_iter->op_end())
				{
					llvm::Value * val = operand_iter->get();
					
					if(val_to_val.find(val) == val_to_val.end())
					{
						++operand_iter;
						continue;
					} 
					*operand_iter = val_to_val[val];

					++operand_iter;
				}
				++instruction_iter;
    		}
    	}

    	return false;
    }
};