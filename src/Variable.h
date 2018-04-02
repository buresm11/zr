
#pragma once

#include "llvm.h"

class Variable
{
	llvm::Value * value;
	bool global;

public:

	Variable(llvm::Value * v, bool glob) : value(v), global(glob)  { }

	llvm::Value * get_value()
	{
		return value;
	}

	bool is_global()
	{
		return global;
	}
};