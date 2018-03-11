
#pragma once

#include "Variable.h"

class Scope
{
	std::map<std::string, Variable *> variables;
	Scope * parent;

public:

	Scope() : parent(NULL) { }

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

		//TODO NOT FOUND
	}

	void add_variable(std::string name, Variable * variable)
	{
		variables[name] = variable;
	}
};