
#pragma once

#include <exception>
#include <iostream>

class CompileException : public std::exception
{
	std::string msg;

public:
    CompileException(const std::string m="my custom exception") : msg(m) { }

    virtual const char* what() const throw()
	{
		return msg.c_str();
	}     
};