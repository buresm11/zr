
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
    	std::cout << "rffFFF" << std::endl;

    	func_inlining_analysis & a = getAnalysis<func_inlining_analysis>();

    	if(!a.is_function_cool_to_inline(&F)) return false;

    	llvm::Module * module = F.getParent();

    	auto function_iter = module->begin();
    	while(function_iter != module->end())
    	{
    		auto basic_block_iter = function_iter->begin();

    		while(basic_block_iter != function_iter->end())
    		{
    			auto instruction_iter = basic_block_iter->begin();
    			while(instruction_iter != basic_block_iter->end())
    			{
    				if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(instruction_iter))
        			{
        				 llvm::Function * called_func = inst->getCalledFunction();

        				 return replace_call(function_iter, inst, called_func);
        			}
    				++instruction_iter;
    			}
    			++basic_block_iter;
    		}
    		++function_iter;
    	}

    	return false;
    }

    bool replace_call(llvm::Function * caller_func, llvm::CallInst * call_inst, llvm::Function * callee_func)
    {
    	std::cout << "not" << caller_func->getName().lower() << callee_func->getName().lower() << std::endl;

    	std::map<llvm::BasicBlock *, llvm::BasicBlock *> bb_to_bb;

    	auto basic_block_iter = callee_func->begin();

    	while(basic_block_iter != callee_func->end())
    	{
    		llvm::BasicBlock * bb = llvm::BasicBlock::Create(Compiler::llvm_context, "copied", caller_func);
    		bb_to_bb[basic_block_iter] = bb; 

    		++basic_block_iter;
    	}

    	return false;
    }
};