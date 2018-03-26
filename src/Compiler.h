
#pragma once

#include <iostream>
#include <vector>

#include "antlr4-runtime.h"
#include "llvm.h"
#include "zrBaseVisitor.h"
#include "ContextValue.h"
#include "Scope.h"
#include "CompileException.h"

#define DEBUG_ENABLED

#ifdef DEBUG_ENABLED
#define Debug(x) std::cout << x;
#else
#define Debug(x) 
#endif 

class Compiler : public zrBaseVisitor
{

};