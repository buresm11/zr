#pragma once

#include "Literal.h"
#include "Type.h"

class IntLiteral : public Literal 
{
	int value;

public:
	IntLiteral() : Literal(IntType), value(0) { }
	IntLiteral(int i) : Literal(IntType), value(i) { }

	int get_value()
	{
		return value;
	}

	void set_value(int value)
	{
		this->value = value;
	}
};