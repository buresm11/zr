
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
    	bool f =  is_tail.find(function) != is_tail.end();

        if(!f) return false;
        else return is_tail[function];
    }

    std::vector<llvm::Instruction *> get_recursive_calls(llvm::Function * function)
    {
    	return recursive_calls[function];
    }

	bool runOnFunction(llvm::Function & F)
    {
        std::cout << "TTTTT::1" <<F.getName().lower() << std::endl;

    	bool tail = true;
    	bool recursive = false;
    	std::vector<llvm::Instruction *> calls;

        auto basic_block_iter = F.begin(); 
        while(basic_block_iter != F.end()) 
        {
            auto instruction_iter = basic_block_iter->begin();
            while(instruction_iter != basic_block_iter->end())
            {
                if(llvm::CallInst * inst = llvm::dyn_cast<llvm::CallInst>(instruction_iter))
                {
                    if(inst->getCalledFunction() == &F) // self call
                    {
                        recursive = true;

                        calls.push_back(instruction_iter);

                        auto prev_inst = &(*instruction_iter);
                        ++instruction_iter;

                        if(llvm::ReturnInst * ret_inst = llvm::dyn_cast<llvm::ReturnInst>(instruction_iter))
                        {
                            if(ret_inst->getType() != Compiler::t_void)
                            {
                                if(ret_inst->getReturnValue() != prev_inst) tail = false;
                            }
                        }
                        else if(llvm::BranchInst * br_inst = llvm::dyn_cast<llvm::BranchInst>(instruction_iter))
                        {
                            if(br_inst->isConditional())
                            {
                                tail = false;
                                ++instruction_iter;
                                continue;
                            }

                            auto f_inst = br_inst->getSuccessor(0)->begin();
                            if(llvm::ReturnInst * ret_inst = llvm::dyn_cast<llvm::ReturnInst>(f_inst))
                            {
                                if(ret_inst->getType() != Compiler::t_void)
                                {
                                    if(ret_inst->getReturnValue() != prev_inst) tail = false;
                                }
                            }
                            else tail = false;
                        } 
                        else tail = false; 
                    }
                }
                ++instruction_iter;
            }
            ++basic_block_iter;
        }

        recursive_calls[&F] = calls;
        if(tail && recursive)
        {
            std::cout << "TTTTT::1" <<F.getName().lower() << std::endl;
        	is_tail[&F] = true;
        }
        else 
            {std::cout << "TTTTT::3" <<F.getName().lower() << std::endl;is_tail[&F] = false;}

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
        std::cout << "SDDDDDFFF::1" <<F.getName().lower() << std::endl;

    	tail_call_analysis & a = getAnalysis<tail_call_analysis>();

    	if(!a.is_function_tail(&F)) return false;

        std::cout << "SDDDDDFFF::2" << F.getName().lower() << std::endl;

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
    	x->setName(b.getName() + "_tail"); // DEBUG

    	std::vector<llvm::Instruction *> recursive_calls = a.get_recursive_calls(&F);

    	for(int i=0; i<recursive_calls.size(); i++)
    	{
    		if(llvm::CallInst * call_inst = llvm::dyn_cast<llvm::CallInst>(recursive_calls.at(i)))
        	{
        		for(int i = 0; i < call_inst->getNumArgOperands(); i++)
        		{
        			llvm::StoreInst * si = new llvm::StoreInst(call_inst->getArgOperand(i), args.at(i), false, call_inst);
        		}
        		llvm::BranchInst::Create(x, call_inst);

        		auto ret_after_call = call_inst->eraseFromParent();
        		ret_after_call->eraseFromParent();
        	} 
    	}
    	return true;
    }
};