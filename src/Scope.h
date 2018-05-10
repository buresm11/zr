
#pragma once

#include "CompileException.h"
#include "llvm.h"

class Variable
{
	llvm::Type * type;
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

class Scope
{
	std::map<std::string, Variable *> variables;
	Scope * parent;

public:

	Scope() : parent(NULL) { }
	Scope(Scope * scope) : parent(scope) { }

	~Scope()
	{
		auto it = variables.begin();

		while(it != variables.end())
		{
		    delete it->second;
		    ++it;
		}
	}

	bool has_variable(std::string name)
	{
		return variables.find(name) != variables.end();
	}

	Variable * get_variable(std::string name)
	{
		std::map<std::string, Variable *>::iterator it;
		it = variables.find(name);

		if(it != variables.end())
		{
			return it->second;
		}

		if (parent != NULL)
		{
			return parent->get_variable(name);
		}

		throw CompileException("Variable " + name + " does not exist");
	}

	void add_variable(std::string name, Variable * variable)
	{
		variables[name] = variable;
	}

	Scope * get_parent()
	{
		return parent;
	}
};