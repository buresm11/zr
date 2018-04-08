
#pragma once

#include <iostream>

#include "llvm.h"
#include "opt/dead_inst.h"
#include "opt/const_propag.h"

extern "C" int scan_() {
    int result;
    std::cout << "Zadejte cislo: " ;
    std::cin >> result;
    return result;
}

extern "C" void print_(int what) {
    std::cout << "Vypis: " << what << std::endl;
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
        llvm::report_fatal_error("Extern function '" + Name + "' couldn't be resolved!");
    }
};

class JIT {
public:

    typedef int (*MainPtr)();

    static MainPtr run(llvm::Function * main) {
        
        llvm::Module * m = main->getParent();

        auto pm = llvm::legacy::FunctionPassManager(m);
        pm.add(new analysis());
        pm.add(new const_propag());

        for (llvm::Function & f : *m) 
        {
            while (pm.run(f)) 
            {

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
            int i;
            //throw CompilerError(STR("Could not create ExecutionEngine: " << err));

        engine->finalizeObject();

        return reinterpret_cast<MainPtr>(engine->getPointerToFunction(main));
    }
};

