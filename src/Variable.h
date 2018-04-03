
#pragma once

#include "llvm.h"

class Variable
{
	llvm::Type * type;
	llvm::Value * value;
	bool global;

public:

	Variable(llvm::Value * v, bool glob, llvm::Type * t) : value(v), global(glob), type(t)  { }

	llvm::Value * get_value()
	{
		return value;
	}

	bool is_global()
	{
		return global;
	}

	llvm::Type * get_type()
	{
		return type;
	}
};