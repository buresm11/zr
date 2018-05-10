#pragma once

#include <iostream>

#include "llvm.h"

class dead_code : public llvm::FunctionPass
{
public:
	static char ID;

	dead_code() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "RemoveDeadCode";
    }

	bool runOnFunction(llvm::Function & F) override
    {
        bool changed = false;

        auto basic_block_iter = F.begin();
        while(basic_block_iter != F.end())
        {
            auto instruction_iter = basic_block_iter->begin();
            while(instruction_iter != basic_block_iter->end())
            {
                if(llvm::BranchInst * br_inst = llvm::dyn_cast<llvm::BranchInst>(instruction_iter))
                {
                    if(!br_inst->isConditional())
                    {
                        ++instruction_iter;
                        continue;
                    }

                    if(llvm::ConstantInt * ci = llvm::dyn_cast<llvm::ConstantInt>(br_inst->getOperand(0)))
                    {
                        changed = true;
                        if(ci->getSExtValue() == 0)
                        {
                            llvm::BranchInst::Create(br_inst->getSuccessor(1), br_inst);
                        }
                        else
                        {
                            llvm::BranchInst::Create(br_inst->getSuccessor(0), br_inst);
                        }

                        instruction_iter = br_inst->eraseFromParent();
                        continue;
                    }
                }
                ++instruction_iter;
            }
            ++basic_block_iter;
        }

    	std::vector<llvm::BasicBlock *> bb_to_remove;

    	auto basic_block_iter_r = F.begin();
    	while(basic_block_iter_r != F.end())
    	{
    		llvm::BasicBlock * bb = basic_block_iter_r;

			llvm::TerminatorInst * t_inst = bb->getTerminator();

			int pred_num = 0;
			for (llvm::BasicBlock *Pred : llvm::predecessors(bb))
				pred_num++;

			if(pred_num == 0 && &(F.getEntryBlock()) != bb)
				bb_to_remove.push_back(bb);

			++basic_block_iter_r;
        }

        for(int i=0;i<bb_to_remove.size();i++)
        {
        	bb_to_remove.at(i)->eraseFromParent();
        	changed = true;
        }

        return changed;
    }
};