
#pragma once

#include <iostream>

#include "llvm.h"

class dead_inst_pass : public llvm::FunctionPass
{
	static char ID;
	bool changed;

public:
	dead_inst_pass() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "DeadInstructionRemovalOptimization";
    }

	bool runOnFunction(llvm::Function &F)
	{
		changed = false;
        for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
            	i->dump();
            	std::cout << " " << i ->getNumUses() << std::endl;

            	++i;
            }
        }

		return changed;
	}
};