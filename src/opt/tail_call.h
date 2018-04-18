
#pragma once

#include <iostream>

#include "llvm.h"
#include "Compiler.h"

class tail_call_analysis : public llvm::FunctionPass
{
	std::map<llvm::Function *, bool> is_tail;
	std::map<llvm::Function *, std::vector<llvm::Instruction *>> recursive_calls;

public:
	static char ID;

	tail_call_analysis() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "TailCallRemovalAnalysis";
    }

    bool is_function_tail(llvm::Function * function)
    {
    	return is_tail.find(function) != is_tail.end();
    }

    std::vector<llvm::Instruction *> get_recursive_calls(llvm::Function * function)
    {
    	return recursive_calls[function];
    }

	bool runOnFunction(llvm::Function & F)
    {
    	bool tail = true;
    	bool recursive = false;
    	std::vector<llvm::Instruction *> calls;

    	for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
            	if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(i))
        		{ 
        			if(inst->getCalledFunction() == &F) // self call
        			{
        				recursive = true;
        				calls.push_back(i);

        				auto prev_inst = i;
        				i++;

        				if(llvm::ReturnInst * inst = llvm::dyn_cast<llvm::ReturnInst>(i))
        				{
        					if(inst->getType() != Compiler::t_void)
        					{
        						if( inst->getReturnValue() != prev_inst) tail = false;
        					}
        				}
        				else tail = false;
        			}
        		}
            	i++;
            }
        }
        std::cout << F.getName().lower() << tail << recursive << std::endl;

        recursive_calls[&F] = calls;
        if(tail && recursive)
        {
        	is_tail[&F] = true;
        }
        return false;
    }
};

class tail_call : public llvm::FunctionPass
{
	
public:
	static char ID;

	tail_call() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "TailCallRemovalOptimization";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const
    {
    	Info.addRequired<tail_call_analysis>();
    }

	bool runOnFunction(llvm::Function & F)
    {
    	tail_call_analysis & a = getAnalysis<tail_call_analysis>();

    	if(!a.is_function_tail(&F)) return false;

    	llvm::BasicBlock & b =  F.getEntryBlock();
    	int args_size = F.arg_size();
    	std::vector<llvm::Value * > args;

    	auto iter = b.begin();
    	for(int i=0;i < args_size * 2; i++)
    	{
    		if(i % 2 == 0) args.push_back(iter);
    		++iter;
    	}

    	llvm::BasicBlock * x = b.splitBasicBlock(iter);
    	x->setName(b.getName() + "_tail");

    	std::vector<llvm::Instruction *> recursive_calls = a.get_recursive_calls(&F);

    	for(int i=0; i<recursive_calls.size(); i++)
    	{
    		if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(recursive_calls.at(i)))
        	{
        		llvm::Instruction * prev = inst;
        		for(int i = 0; i < inst->getNumArgOperands(); i++)
        		{
        			llvm::StoreInst * si = new llvm::StoreInst(inst->getArgOperand(i), args.at(i), false, prev);
        		}

        		llvm::BranchInst::Create(x, prev);

        		auto ret_after_call = inst->eraseFromParent();
        		ret_after_call->eraseFromParent();

        	} 
        	else { } //impossible
    	}
    	return true;
    }
};