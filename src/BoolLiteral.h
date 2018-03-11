
#pragma once

#include "Type.h"
#include "Literal.h"

class BoolLiteral : public Literal
{
	bool value;

public:
	BoolLiteral() : Literal(BoolType), value(false) { }
	BoolLiteral(bool b) : Literal(BoolType), value(b) { }

	bool get_value()
	{
		return value;
	}

	void set_value(bool value)
	{
		this->value = value;
	}
};