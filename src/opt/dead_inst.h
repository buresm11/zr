
#pragma once

#include <iostream>

#include "llvm.h"
#include "const_propag.h"

class dead_inst : public llvm::FunctionPass
{
	static char ID;
	bool changed;

public:
	dead_inst() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "DeadInstructionRemovalOptimization";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const
    {
        Info.addRequired<const_propag>();
    }

	bool runOnFunction(llvm::Function & F)
    {
        bool changed = false;
        for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
                if(i->getNumUses() == 0 and not i->isTerminator() and not llvm::dyn_cast<llvm::StoreInst>(i) and not 
                    llvm::dyn_cast<llvm::CallInst>(i))
                {
                    i = i->eraseFromParent();
                    changed = true;
                }
                else ++i;
            }
        }
        return changed;
    }
};