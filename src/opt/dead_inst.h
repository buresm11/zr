
#pragma once

#include <iostream>

#include "llvm.h"
#include "const_propag.h"

class dead_inst : public llvm::FunctionPass
{
	static char ID;

public:
	dead_inst() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "DeadInstructionRemovalOptimization";
    }

	bool runOnFunction(llvm::Function & F)
    {
        bool changed = false;


        auto basic_block_iter = F.begin(); 
        while(basic_block_iter != F.end())
        {
            auto instruction_iter = basic_block_iter->begin();
            while(instruction_iter != basic_block_iter->end())
            {
                if(instruction_iter->getNumUses() == 0 and not instruction_iter->isTerminator() and 
                    not llvm::dyn_cast<llvm::StoreInst>(instruction_iter) and not llvm::dyn_cast<llvm::CallInst>(instruction_iter))
                {
                    instruction_iter = instruction_iter->eraseFromParent();
                    changed = true;
                    continue;
                }
                ++instruction_iter;
            }
            ++basic_block_iter;
        }
        return changed;
    }
};