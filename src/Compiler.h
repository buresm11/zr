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

class FuncArg
{
	std::string name;
	Type type;

public:
	FuncArg(std::string n, Type t) : name(n), type(t) { }

	std::string get_name()
	{
		return name;
	}

	Type get_type()
	{
		return type;
	}
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
		m = new llvm::Module("zr", llvm_context);
		create_scope();

		llvm::Function::Create(t_scan, llvm::GlobalValue::ExternalLinkage, "scan_", m)->setCallingConv(llvm::CallingConv::C);
        llvm::Function::Create(t_print, llvm::GlobalValue::ExternalLinkage, "print_", m)->setCallingConv(llvm::CallingConv::C);

		visit(tree);

		llvm::raw_os_ostream err(std::cerr);
		if (llvm::verifyModule(*m, & err)) 
    	{
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
    		visit(ctx->function_decl().at(i));
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

    	if(scope->has_variable(name))
    	{
    		throw CompileException("Redefinition of global variable " + name);
    	}

    	llvm::GlobalVariable * gv;

    	if(type == Type::IntType)
    	{
    		gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, NULL, name);
  		    gv->setAlignment(4);
  		    gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)));
    	}
    	else if(type == Type::BoolType)
    	{
    		gv = new llvm::GlobalVariable(*m, t_bool, false, llvm::GlobalValue::CommonLinkage, NULL, name);
  		    gv->setAlignment(4);
  		    gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0)));
    	}

    	Variable * variable = new Variable(gv, true);
		scope->add_variable(name, variable);

    	return NULL;
    }

    antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *ctx) override
    {
    	std::string func_name = ctx->Identifier()->getText();
    	Type func_type = get_type_from_string(ctx->Type_identifier()->getText());

    	if (m->getFunction(func_name) != NULL)
            throw CompileException("Function " + func_name + " already exists");

        std::vector<std::string> arg_names;
        std::vector<llvm::Type * > args_types;

    	if(ctx->func_decl_arg_list() != NULL)
    	{
    		std::vector<FuncArg *> args = visit(ctx->func_decl_arg_list());
    		
    		for (int i = 0; i < args.size(); i++)
    		{
    			arg_names.push_back(args.at(i)->get_name());

    			if(args.at(i)->get_type() == Type::IntType) args_types.push_back(t_int);
    			else if(args.at(i)->get_type() == Type::BoolType) args_types.push_back(t_bool);
            	

            	delete args.at(i);
    		}
    	}  

    	llvm::FunctionType * ft;

    	if(func_type == Type::IntType)
    	{
    		 ft = llvm::FunctionType::get(t_int, args_types, false);
    	}   
    	else if(func_type == Type::BoolType)
    	{
    		 ft = llvm::FunctionType::get(t_bool, args_types, false);
    	}  

        f = llvm::Function::Create(ft, llvm::GlobalValue::ExternalLinkage, func_name, m);
        f->setCallingConv(llvm::CallingConv::C);

		create_scope();
        bb = llvm::BasicBlock::Create(llvm_context, "entry_" + func_name, this->f);

        llvm::Function::arg_iterator f_args = f->arg_begin();

        for(int i=0;i < args_types.size(); i++)
        {
        	std::string name = arg_names.at(i);
        	llvm::Value* arg = f_args++;

        	if(scope->has_variable(name))
        	{
        		throw CompileException("Redefinition of variable " + name);
        	}

        	llvm::AllocaInst * loc = new llvm::AllocaInst(arg->getType(), name, bb);

        	Variable * variable = new Variable(loc, false);
			scope->add_variable(name, variable);

		    new llvm::StoreInst(arg, loc, false, bb);

		    arg->setName(name);
		   	loc->setName(name);
        }

        bool block_returns = visit(ctx->block());
        /*if(!block_returns)
        {
    		llvm::ReturnInst * ret = llvm::ReturnInst::Create(llvm_context, llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)), bb);
        }*/

        remove_scope();

    	return NULL;
    }

    antlrcpp::Any visitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *ctx) override
    {
    	Debug(": func decl arg list" << std::endl);

    	std::vector<FuncArg *> args;

    	for(int i=0;i<ctx->func_decl_arg().size();i++)
    	{
    		args.push_back(visit(ctx->func_decl_arg().at(i)));
    	}

    	return args;
    }

    antlrcpp::Any visitFunc_decl_arg(zrParser::Func_decl_argContext *ctx) override
    {
    	std::string arg_name = ctx->Identifier()->getText();
    	Type arg_type = get_type_from_string(ctx->Type_identifier()->getText());

    	return new FuncArg(arg_name, arg_type);
    }

    antlrcpp::Any visitBlock(zrParser::BlockContext *context) override
    {
    	Debug(": block" << std::endl);

    	bool ret = false;
    	for(int i=0;i<context->statement().size();i++)
    	{
    		ret = visit(context->statement().at(i));
    		if(ret) break;
    	}

    	return ret;
    }

    antlrcpp::Any visitStatement(zrParser::StatementContext *context) override
    {
    	Debug(": statement" << std::endl);

    	if(context->variable_def() != NULL)
    	{
    		visit(context->variable_def());
    	}
    	else if(context->assignment() != NULL)
    	{
    		visit(context->assignment());
    	}
    	else if(context->if_statement() != NULL)
    	{
    		//visit(context->if_statement());
    	}
    	else if(context->while_statement() != NULL)
    	{
    		//visit(context->while_statement());
    	}
    	else if(context->function_call() != NULL)
    	{
    		//visit(context->function_call());
    	}
    	else if(context->return_statement() != NULL)
    	{
    		//visit(context->return_statement());
    		return true;
    	}

    	return false;
    }

    antlrcpp::Any visitVariable_def(zrParser::Variable_defContext *ctx) override
    {
    	Debug(": variable def" << std::endl);

    	std::string name = ctx->Identifier()->getText();
    	Type type = get_type_from_string(ctx->Type_identifier()->getText());

    	if(scope->has_variable(name))
    	{
    		throw CompileException("Redefinition of variable " + name);
    	}

    	Variable * variable;

    	if(type == Type::IntType)
    	{
    		 variable = new Variable(new llvm::AllocaInst(t_int, name, bb), false);
    	}   
    	else if(type == Type::BoolType)
    	{
    		 variable = new Variable(new llvm::AllocaInst(t_bool, name, bb), false);
    	}  

    	scope->add_variable(name, variable);

    	return NULL;
    }

    antlrcpp::Any visitAssignment(zrParser::AssignmentContext *context)
    {
    	Debug(": assigment" << std::endl);

    	std::string name = context->Identifier()->getText();

    	if(!scope->has_variable(name))
    	{
    		throw CompileException("Variable " + name + " does not exist");
    	}

    	llvm::Value * val = visit(context->expression());
    	llvm::Value * address = scope->get_variable(name)->get_value();

    	new llvm::StoreInst(val, address, false, bb);

    	return NULL;
    }

    virtual antlrcpp::Any visitBinaryExpression(zrParser::BinaryExpressionContext *ctx) override 
    {
    	Debug(": binary" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(ctx->binOp()->Or() != NULL)
    	{

    	}
    	else if(ctx->binOp()->And() != NULL)
    	{

    	}
    	else if(ctx->binOp()->Equals() != NULL)
    	{

    	}
    	else if(ctx->binOp()->NEquals() != NULL)
    	{

    	}
    	else if(ctx->binOp()->GTEquals() != NULL)
    	{

    	}
    	else if(ctx->binOp()->LTEquals() != NULL)
    	{

    	}
    	else if(ctx->binOp()->Gt() != NULL)
    	{

    	}
    	else if(ctx->binOp()->Lt() != NULL)
    	{

    	}
    	else if(ctx->binOp()->Add() != NULL)
    	{
    		if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
				 val = llvm::BinaryOperator::Create(llvm::Instruction::Add, exp_lv , exp_rv, "", bb);
			else
				throw CompileException("Operation not supported");
    	}
    	else if(ctx->binOp()->Minus() != NULL)
    	{
    		if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
				 val = llvm::BinaryOperator::Create(llvm::Instruction::Sub, exp_lv , exp_rv, "", bb);
			else
				throw CompileException("Operation not supported");
    	}
    	else if(ctx->binOp()->Multiply() != NULL)
    	{
    		if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
				 val = llvm::BinaryOperator::Create(llvm::Instruction::Mul, exp_lv , exp_rv, "", bb);
			else
				throw CompileException("Operation not supported");
    	}
    	else if(ctx->binOp()->Divide() != NULL)
    	{
    		if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
				 val = llvm::BinaryOperator::Create(llvm::Instruction::UDiv, exp_lv , exp_rv, "", bb);
			else
				throw CompileException("Operation not supported");
    	}

    	return val;
  	}

    antlrcpp::Any visitUnaryExpression(zrParser::UnaryExpressionContext *ctx) override 
    {
    	Debug(": unary" << std::endl);

    	llvm::Value * exp_val = visit(ctx->expression());
    	llvm::Value * val;

    	if(ctx->unOp()->Excl() != NULL)
    	{
    		if(exp_val->getType() == t_bool)
				val = llvm::BinaryOperator::Create(llvm::Instruction::Xor,
				 				llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0)), exp_val, "", bb);
			else
				throw CompileException("Operation not supported");
    	}
    	else if(ctx->unOp()->Minus() != NULL)
    	{
    		if(exp_val->getType() == t_int)
				val = llvm::BinaryOperator::Create(llvm::Instruction::Sub,
				 				llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)), exp_val, "", bb);
			else
				throw CompileException("Operation not supported");
    	}

    	return val;
  	}

	antlrcpp::Any visitLiteralExpression(zrParser::LiteralExpressionContext *ctx) override 
    {
    	Debug(": literal" << std::endl);

    	llvm::Value * val;

    	if(ctx->number() != NULL)
    	{
    		val = llvm::ConstantInt::get(llvm_context, llvm::APInt(32, parse_int(ctx->number()->Integer()->getText())));
    	}
    	else if(ctx->bool_lit() != NULL)
    	{
    		if(ctx->bool_lit()->True() != NULL)
    			val = llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 1));
    		else if (ctx->bool_lit()->False() != NULL)
    			val =  llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0));
    	}
    	return val;
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