
#pragma once

#include <iostream>

#include "llvm.h"

enum class TypeX 
{
    Top,
    Bottom,
    Const
};

class ValueContent
{
	int value;
	TypeX type;

public:
	ValueContent(TypeX t, int v) : type(t), value(v) { } 

	ValueContent(TypeX t) : type(t) { }

	bool is_bottom() const
	{
		return type == TypeX::Bottom;
	}

	bool is_top() const
	{
		return type == TypeX::Top;
	}

	bool is_const() const
	{
		return type == TypeX::Const;
	}

	int get_value() const
	{
		return value;
	}

	TypeX get_type() const
	{
		return type;
	}

	bool merge(ValueContent const & other)
	{
		if(is_top()) return false;

		if(is_bottom())
		{
			if(other.is_bottom()) return false;

			*this = other;
			return true;
		}

		if(is_const())
		{
			if(other.is_const() && value == other.get_value()) return false;
			if(other.is_const() || other.is_top()) { type = TypeX::Top; return true; }
			if(other.is_bottom()) return false;
		}

		return false;
	}
};

class State
{

};

class analysis : public llvm::FunctionPass
{
	static char ID;

public:
	analysis() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "Analysis";
    }

	bool runOnFunction(llvm::Function &F)
	{
        for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {

            }
        }

		return false;
	}

};

class const_propag : public llvm::FunctionPass
{
	static char ID;
	bool changed;

public:
	const_propag() : FunctionPass(ID) { }

	char const * getPassName() const override 
	{
        return "DeadInstructionRemovalOptimization";
    }

	bool runOnFunction(llvm::Function &F)
	{
		changed = false;
        for (llvm::BasicBlock & b : F) 
        {
            auto i = b.begin();
            while (i != b.end()) 
            {
            	i->dump();
            	std::cout << " " << i ->getNumUses() << std::endl;

            	++i;
            }
        }

		return changed;
	}
};