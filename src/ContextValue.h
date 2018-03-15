
#pragma once

#include "llvm.h"

class ContextValue
{
	llvm::Value * value;
	bool constant;

public:

	ContextValue(llvm::Value * val, bool c) : value(val), constant(c) { }

	llvm::Value * get_value()
	{
		return value;
	}

	bool is_constant()
	{
		return constant;
	}
};