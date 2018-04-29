
#pragma once

#include <iostream>

#include "llvm.h"

class useless_bb : public llvm::FunctionPass
{
public:
	static char ID;

	useless_bb() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "RemoveUselessBasicBlocks";
    }

	bool runOnFunction(llvm::Function & F) override
    {
    	bool changed = false;
    	std::vector<llvm::BasicBlock *> bb_to_remove;

    	auto basic_block_iter = F.begin();
    	while(basic_block_iter != F.end())
    	{
    		llvm::BasicBlock * bb = basic_block_iter;

			llvm::TerminatorInst * t_inst = bb->getTerminator();

			int pred_num = 0;
			for (llvm::BasicBlock *Pred : llvm::predecessors(bb))
				pred_num++;

			std::cout << bb->getName().lower() << pred_num << std::endl;

			if(pred_num == 0 && &(F.getEntryBlock()) != bb)
				bb_to_remove.push_back(bb);

			++basic_block_iter;
        }

        for(int i=0;i<bb_to_remove.size();i++)
        {
        	bb_to_remove.at(i)->eraseFromParent();
        	changed = true;
        }

        return changed;
    }
};