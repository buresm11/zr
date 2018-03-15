
#pragma once

#include "llvm.h"

class Variable
{
	llvm::Value * value;
	bool global;
	bool constant;

public:

	Variable(llvm::Value * v, bool glob) : value(v), global(glob), constant(true)  { }

	llvm::Value * get_value()
	{
		return value;
	}

	bool is_global()
	{
		return global;
	}

	bool is_constant()
	{
		return constant;
	}
};