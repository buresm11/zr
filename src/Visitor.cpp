
#include "Visitor.h"

llvm::Type * Visitor::t_int = llvm::IntegerType::get(llvm::getGlobalContext(), 32);

llvm::Type * Visitor::t_void = llvm::Type::getVoidTy(llvm::getGlobalContext());