#pragma once

#include "Type.h"

class Literal
{
	Type type;

public:

	Literal(Type t) : type(t) {}

	Type get_type()
	{
		return type;
	}
};