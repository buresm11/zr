
#include "Compiler.h"

llvm::LLVMContext & Compiler::llvm_context = llvm::getGlobalContext();

llvm::Type * Compiler::t_int = llvm::IntegerType::get(llvm::getGlobalContext(), 32);

llvm::Type * Compiler::t_void = llvm::Type::getVoidTy(llvm::getGlobalContext());

llvm::Type * Compiler::t_bool = llvm::IntegerType::get(llvm::getGlobalContext(), 1);

llvm::FunctionType * Compiler::t_scan = llvm::FunctionType::get(t_int, false);

llvm::FunctionType * Compiler::t_print = llvm::FunctionType::get(t_void, { t_int }, false);

llvm::FunctionType * Compiler::t_printb = llvm::FunctionType::get(t_void, { t_bool } , false);