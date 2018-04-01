
#pragma once

#include <iostream>
#include <vector>

#include "antlr4-runtime.h"
#include "llvm.h"
#include "zrBaseVisitor.h"
#include "ContextValue.h"
#include "Scope.h"
#include "CompileException.h"

#define DEBUG_ENABLED

#ifdef DEBUG_ENABLED
#define Debug(x) std::cout << x;
#else
#define Debug(x) 
#endif 

enum class Type
{
	IntType,
	BoolType
};

class Compiler : public zrBaseVisitor
{
	static llvm::LLVMContext & llvm_context;
	static llvm::Type * t_int;
	static llvm::Type * t_void;
	static llvm::Type * t_bool;
	static llvm::FunctionType * t_print;
    static llvm::FunctionType * t_scan;

	llvm::Module * m;
	llvm::Function * f;
	llvm::BasicBlock * bb;
	llvm::BasicBlock * next;
	Scope * scope;


public:

	llvm::Module * compile(antlr4::tree::ParseTree *tree)
	{
		Debug(": compilation started" << std::endl);

		m = new llvm::Module("zr", llvm_context);
		create_scope();

		llvm::Function::Create(t_scan, llvm::GlobalValue::ExternalLinkage, "scan_", m)->setCallingConv(llvm::CallingConv::C);
        llvm::Function::Create(t_print, llvm::GlobalValue::ExternalLinkage, "print_", m)->setCallingConv(llvm::CallingConv::C);

        		Debug(": compilation started1" << std::endl);

		visit(tree);
				Debug(": compilation started3" << std::endl);

		llvm::raw_os_ostream err(std::cerr);
		if (llvm::verifyModule(*m, & err)) {
            m->dump();
            throw CompileException("bad llvm ir");
        }

        remove_scope();
		return m;
	}

	antlrcpp::Any visitParse(zrParser::ParseContext *ctx) override
	{
		Debug(": parse" << std::endl);

		visit(ctx->top_block());

		return NULL;
  	}

  	antlrcpp::Any visitTop_block(zrParser::Top_blockContext *ctx) override
    {
    	Debug(": top_block" << std::endl);

    	for(int i=0;i<ctx->global_statement().size();i++)
    	{
    		visit(ctx->global_statement().at(i));	
    	}

    	for(int i=0;i<ctx->function_decl().size();i++)
    	{
    		//visit(ctx->function_decl().at(i));
    	}

    	return NULL;
    }

    antlrcpp::Any visitGlobal_statement(zrParser::Global_statementContext *ctx) override
   	{
   		Debug(": global_statement" << std::endl);

   		visit(ctx->global_variable_def());

   		return NULL;
   	}

    antlrcpp::Any visitGlobal_variable_def(zrParser::Global_variable_defContext *ctx) override
    {
    	Debug(": global_variable_def" << std::endl);

    	std::string name = ctx->Identifier()->getText();
    	Type type = get_type_from_string(ctx->Type_identifier()->getText());

    	if(type == Type::IntType)
    	{
    		llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, NULL, name);
  		    gv->setAlignment(4);

  		    if(ctx->number() != NULL)
  		    {
  		    	llvm::ConstantInt * constant = visit(ctx->number());
  		    	gv->setInitializer(constant);
  		    }
  		    else if(ctx->bool_lit() != NULL)
  		    {
  		    	//TODO compiler error
  		    }

  		    gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)));
    	}
    	else if(type == Type::BoolType)
    	{
    		llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_bool, false, llvm::GlobalValue::CommonLinkage, NULL, name);
  		    gv->setAlignment(4);

  		    if(ctx->number() != NULL)
  		    {
  		    	//TODO compiler error
  		    }
  		    else if(ctx->bool_lit() != NULL)
  		    {
  		    	llvm::ConstantInt * constant = visit(ctx->bool_lit());
  		    	gv->setInitializer(constant);
  		    }

  		    gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)));
    	}

    	return NULL;
    }

    antlrcpp::Any visitBool_lit(zrParser::Bool_litContext *ctx) override
    {
    	Debug(": bool lit" << std::endl);

    	if(ctx->True() != NULL)
    	{	
    		return llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 1));
    	}

    	if(ctx->False() != NULL)
    	{	
    		return llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0));
    	}
    }

    antlrcpp::Any visitNumber(zrParser::NumberContext *ctx) override
    {
    	Debug(": number" << std::endl);


    	int num = parse_int(ctx->Integer()->getText());

    	return llvm::ConstantInt::get(llvm_context, llvm::APInt(32, num));
    }

	void create_scope()
    {
    	scope = new Scope(scope);
    }

    void remove_scope()
    {
    	Scope * tmp = scope;
    	scope = scope->get_parent();
    	delete tmp;
    }

    int parse_int(std::string text)
    {
    	int number;

        try
        {
            number = std::stoi(text);
        }
        catch(std::invalid_argument & e)
        {
        	throw CompileException("Unknown number");
        }
        catch(std::out_of_range & e)
        {
        	throw CompileException("Integer out of range");
        }

        return number;
    }

    bool parse_bool(std::string text)
    {
    	if(text == "false")	return false;
    	else return true;
    }

    Type get_type_from_string(std::string type_s)
    {
    	if(type_s == "bool") return Type::BoolType;
    	else if(type_s == "int") return Type::IntType;
    }
};