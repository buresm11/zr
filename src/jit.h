
#pragma once

#include <iostream>

#include "llvm.h"
#include "opt/dead_inst.h"
#include "opt/const_propag.h"
#include "opt/tail_call.h"
#include "opt/func_inlining.h"
#include "opt/dead_code.h"

extern "C" int scan_() {
    int result;
    std::cout << "Enter integer: " ;
    std::cin >> result;
    return result;
}

extern "C" void print_(int what) {
    std::cout << what << std::endl;
}

extern "C" void printb_(int what) {

    if(what) 
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

class MemoryManager : public llvm::SectionMemoryManager {
public:
#define NAME_IS(name) if (Name == #name) return reinterpret_cast<uint64_t>(::name)
    uint64_t getSymbolAddress(const std::string & Name) override 
    {
        uint64_t addr = SectionMemoryManager::getSymbolAddress(Name);
        if (addr != 0) return addr;
        NAME_IS(scan_);
        NAME_IS(print_);
        NAME_IS(printb_);
        llvm::report_fatal_error("Extern function '" + Name + "' couldn't be resolved!");
    }
};

class JIT {
public:

    typedef int (*MainPtr)();

    static MainPtr run(llvm::Function * main, bool optimaze, bool verbose) {
        
        llvm::Module * m = main->getParent();

        if(optimaze)
        {
            func_inliningT * func_inlining = new func_inliningT();
            func_inlining->inline_F(m);

            if(verbose)
            {
                m->dump();
                std::cout << std::endl;
                std::cout << std::endl;
            }

            auto pm = llvm::legacy::FunctionPassManager(m);

            pm.add(new analysis());
            pm.add(new const_propag());
            pm.add(new dead_inst());
            pm.add(new tail_call_analysis());
            pm.add(new tail_call());
            pm.add(new dead_code());

            for (llvm::Function & f : *m) 
            {
                while (pm.run(f)) {  }
            }

            if(verbose)
            {
                m->dump();
                std::cout << std::endl;
                std::cout << std::endl;
            }
        }

        std::string err;
        llvm::TargetOptions opts;
        llvm::ExecutionEngine* engine =
            llvm::EngineBuilder(std::unique_ptr<llvm::Module>(m))
                .setErrorStr(&err)
                .setMCJITMemoryManager(std::unique_ptr<llvm::RTDyldMemoryManager>(new MemoryManager()))
                .setEngineKind(llvm::EngineKind::JIT)
                .setTargetOptions(opts)
                .create();
        if (engine == nullptr)
            throw CompileException("Cannot run");

        engine->finalizeObject();

        return reinterpret_cast<MainPtr>(engine->getPointerToFunction(main));
    }
};

