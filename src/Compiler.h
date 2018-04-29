#pragma once

#include <iostream>
#include <vector>
#include <stack>

#include "antlr4-runtime.h"
#include "llvm.h"
#include "zrBaseVisitor.h"
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
	BoolType,
	VoidType
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
	static llvm::FunctionType * t_print;
	static llvm::FunctionType * t_printb;
    static llvm::FunctionType * t_scan;

	llvm::Module * m;
	llvm::Function * f;
	llvm::BasicBlock * bb;
	llvm::BasicBlock * next;
	Scope * scope;
	int inside_while;
	std::stack<llvm::BasicBlock *> while_stack;

	std::map<std::string, llvm::FunctionType * > f_prototypes;
	std::map<std::string, std::vector<std::string>> f_args_names; //DEBUGGING

public:
	static llvm::LLVMContext & llvm_context;

	static llvm::Type * t_int;
	static llvm::Type * t_void;
	static llvm::Type * t_bool;

	llvm::Module * compile(antlr4::tree::ParseTree *tree)
	{
		inside_while = 0;
		m = new llvm::Module("zr", llvm_context);

		create_new_scope();

		llvm::Function::Create(t_scan, llvm::GlobalValue::ExternalLinkage, "scan_", m)->setCallingConv(llvm::CallingConv::C);
        llvm::Function::Create(t_print, llvm::GlobalValue::ExternalLinkage, "print_", m)->setCallingConv(llvm::CallingConv::C);
        llvm::Function::Create(t_printb, llvm::GlobalValue::ExternalLinkage, "printb_", m)->setCallingConv(llvm::CallingConv::C);

		visit(tree);

		llvm::raw_os_ostream err(std::cerr);
		if (llvm::verifyModule(*m, & err)) 
    	{
       		m->dump();
            throw CompileException("Bad llvm ir");
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
    		create_function_prototype(ctx->function_decl().at(i));
    	}

    	for(int i=0;i<ctx->function_decl().size();i++)
    	{
    		visit(ctx->function_decl().at(i));
    	}

    	return NULL;
    }

    void create_function_prototype(zrParser::Function_declContext *ctx)
    {
    	std::string func_name = ctx->Identifier()->getText();
    	Type func_type;

    	if(ctx->Void() != NULL) func_type = Type::VoidType;
    	else func_type = get_type_from_string(ctx->Type_identifier()->getText());

    	if (f_prototypes.find(func_name) != f_prototypes.end())
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
    	else if(func_type == Type::VoidType)
    	{
    		ft = llvm::FunctionType::get(t_void, args_types, false);
    	}

    	llvm::Function * function = llvm::Function::Create(ft, llvm::GlobalValue::ExternalLinkage, func_name, m);
        function->setCallingConv(llvm::CallingConv::C);

        llvm::Function::arg_iterator f_args = function->arg_begin();
        for(int i=0;i < arg_names.size(); i++)
        {
        	std::string name = arg_names.at(i);

		   	f_args->setName(name);
		   	++f_args;
        }
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
    	Variable * variable;

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
  		    variable = new Variable(gv, true);
    	}
    	else if(type == Type::BoolType)
    	{
    		gv = new llvm::GlobalVariable(*m, t_bool, false, llvm::GlobalValue::CommonLinkage, NULL, name);
  		    gv->setAlignment(4);
  		    gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0)));
  		    variable = new Variable(gv, true);
    	}
		scope->add_variable(name, variable);

    	return NULL;
    }

    antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *ctx) override
    {
    	std::string func_name = ctx->Identifier()->getText();

    	std::vector<std::string> arg_names = f_args_names[func_name];

        f = m->getFunction(func_name);

		create_scope();
        bb = llvm::BasicBlock::Create(llvm_context, "entry_" + func_name, this->f);

        llvm::Function::arg_iterator f_args = f->arg_begin();
        for(int i=0;i < arg_names.size(); i++)
        {
        	std::string name = arg_names.at(i);
        	llvm::Value* arg = f_args++;

        	if(scope->has_variable(name))
        		throw CompileException("Redefinition of variable " + name);

        	llvm::AllocaInst * alloc = new llvm::AllocaInst(t_int, "", bb);

        	Variable * variable = new Variable(alloc, false);
			scope->add_variable(name, variable);

		    llvm::StoreInst * si = new llvm::StoreInst(arg, alloc, false, bb);

		   	alloc->setName(name);
        }

        bool block_returns = visit(ctx->block());
        if(!block_returns)
        {
        	if(f->getReturnType() == t_int)
	    	{
	    		llvm::ReturnInst * ret = llvm::ReturnInst::Create(llvm_context, llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)), bb);
	    	}   
	    	else if(f->getReturnType() == t_bool)
	    	{
    			llvm::ReturnInst * ret = llvm::ReturnInst::Create(llvm_context, llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0)), bb);
	    	}  
	    	else if(f->getReturnType() == t_void)
	    	{
	    		llvm::ReturnInst * ret = llvm::ReturnInst::Create(llvm_context, NULL, bb);
	    	}    		
        }

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
    	Debug(": func decl arg" << std::endl);

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

    antlrcpp::Any visitStatement(zrParser::StatementContext *ctx) override
    {
    	Debug(": statement" << std::endl);

    	if(ctx->variable_def() != NULL)
    	{
    		visit(ctx->variable_def());
    	}
    	else if(ctx->assignment() != NULL)
    	{
    		visit(ctx->assignment());
    	}
    	else if(ctx->if_statement() != NULL)
    	{
    		visit(ctx->if_statement());
    	}
    	else if(ctx->while_statement() != NULL)
    	{
    		inside_while++;
    		visit(ctx->while_statement());
    		inside_while--;
    	}
    	else if(ctx->function_call() != NULL)
    	{
    		visit(ctx->function_call());
    	}
    	else if(ctx->break_statement() != NULL)
    	{
    		visit(ctx->break_statement());
    		return true;
    	}
    	else if(ctx->return_statement() != NULL)
    	{
    		visit(ctx->return_statement());
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

    antlrcpp::Any visitAssignment(zrParser::AssignmentContext *ctx) override
    {
    	Debug(": assigment" << std::endl);

    	std::string name = ctx->Identifier()->getText();

    	llvm::Value * val = visit(ctx->expression());
    	llvm::PointerType * type = (llvm::PointerType *)scope->get_variable(name)->get_value()->getType();

		if(type->getElementType() != val->getType())
	    {
	    	throw CompileException("Incompatible types");
	    }

    	llvm::Value * address = scope->get_variable(name)->get_value();

    	new llvm::StoreInst(val, address, false, bb);
    	
    	return NULL;
    }

    antlrcpp::Any visitIf_statement(zrParser::If_statementContext *ctx) override
    {
    	Debug(": if statatement" << std::endl);

    	compile_if(ctx->if_stat(), ctx->else_if_stat(), ctx->else_stat());

    	return NULL;
    }

    void compile_if(zrParser::If_statContext * if_context, std::vector<zrParser::Else_if_statContext *> else_if_context, zrParser::Else_statContext * else_context)
    {
    	llvm::BasicBlock * if_case = llvm::BasicBlock::Create(llvm_context, "if_case", f);
    	llvm::BasicBlock ** elif_cmp = new llvm::BasicBlock * [else_if_context.size()];
    	llvm::BasicBlock ** elif_case = new llvm::BasicBlock * [else_if_context.size()];
    	
    	for(int i=0;i<else_if_context.size();i++)
	    {
	    	elif_cmp[i] = llvm::BasicBlock::Create(llvm_context, "elif_cmp" + std::to_string(i), f);
	      	elif_case[i] = llvm::BasicBlock::Create(llvm_context, "elif_case" + std::to_string(i), f);
	    }

	    llvm::BasicBlock * else_case;

		if(else_context != NULL) else_case = llvm::BasicBlock::Create(llvm_context, "else_case", f);

    	llvm::BasicBlock * next = llvm::BasicBlock::Create(llvm_context, "next", f);

    	if(else_if_context.size() > 0)
    	{	    	
    		compile_if_case(if_context->expression(), if_context->block(), if_case, elif_cmp[0], next);

    		for(int i=0;i<else_if_context.size()-1;i++)
		    {
		      	compile_if_case(else_if_context.at(i)->expression(), else_if_context.at(i)->block(), 
		      		elif_case[i], elif_cmp[i+1], next);
		    }

		    if(else_context != NULL)
		    {
		    	compile_if_case(else_if_context.at(else_if_context.size()-1)->expression(), 
		    		else_if_context.at(else_if_context.size()-1)->block(), elif_case[else_if_context.size()-1], else_case, next);
    			compile_else_case(else_context->block(), next);
    		}
    		else
    			compile_if_case(else_if_context.at(else_if_context.size()-1)->expression(), 
    				else_if_context.at(else_if_context.size()-1)->block(), elif_case[else_if_context.size()-1], next, next);
    	}	
    	else
    	{
    		if(else_context != NULL)
	        {
	        	compile_if_case(if_context->expression(), if_context->block(), if_case, else_case, next);
	        	compile_else_case(else_context->block(), next);
	        }
	        else
	        {
	        	compile_if_case(if_context->expression(), if_context->block(), if_case, next, next);
	        }
    	}
    }

    void compile_if_case(zrParser::ExpressionContext * expression, zrParser::BlockContext * parse_block, llvm::BasicBlock * block, 
    	llvm::BasicBlock * next_block, llvm::BasicBlock * next)
    {
    	llvm::Value * exp_val = visit(expression);

    	llvm::Value * cmp_val;

    	if(exp_val->getType() == t_bool)
    	{
    		cmp_val = exp_val;
    	}
    	else if(exp_val->getType() == t_int)
    	{
    		cmp_val  = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_EQ, exp_val, llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)), "");
    	}

    	llvm::BranchInst::Create(block, next_block, cmp_val, bb);

    	scope = new Scope(scope);

    	bb = block;

    	bool block_returns = visit(parse_block);
    	if(!block_returns) llvm::BranchInst::Create(next, bb);

    	remove_scope();

    	bb = next_block;
    }

    void compile_else_case(zrParser::BlockContext * parse_block, llvm::BasicBlock * next)
    {
    	scope = new Scope(scope);

    	bool block_returns = visit(parse_block);
    	if(!block_returns) llvm::BranchInst::Create(next, bb);

    	remove_scope();

    	bb = next;
    }

    antlrcpp::Any visitWhile_statement(zrParser::While_statementContext *ctx) override
    {
    	Debug(": visit while" << std::endl);

    	llvm::BasicBlock * preface = llvm::BasicBlock::Create(llvm_context, "preface", f);
    	llvm::BasicBlock * loop = llvm::BasicBlock::Create(llvm_context, "loop", f);
    	llvm::BasicBlock * next = llvm::BasicBlock::Create(llvm_context, "next", f);
    	while_stack.push(next);

    	llvm::BranchInst::Create(preface, bb);

    	bb = preface;

    	llvm::Value * exp_val = visit(ctx->expression());

    	llvm::Value * cmp_val;

    	if(exp_val->getType() == t_bool)
    	{
    		cmp_val = exp_val;
    	}
    	else if(exp_val->getType() == t_int)
    	{
    		cmp_val  = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_EQ, exp_val, llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)), "");
    	}

    	llvm::BranchInst::Create(loop, next, cmp_val, bb);

    	create_scope();

    	bb = loop;
    	bool block_returns =  visit(ctx->block());

    	if(!block_returns) llvm::BranchInst::Create(preface, bb);

    	bb = next;

    	remove_scope();

    	while_stack.pop();

    	return NULL;
    }

    antlrcpp::Any visitIdentifierFunctionCall(zrParser::IdentifierFunctionCallContext *ctx) override 
    {
    	Debug(": Indentifier f call" << std::endl);

    	std::string f_name = ctx->Identifier()->getText();
    	std::vector<llvm::Value * > args;

    	if(ctx->exprList() != NULL)
    	{

	    	for(int i=0;i<ctx->exprList()->expression().size();i++)
	    	{
	    		llvm::Value * val = visit(ctx->exprList()->expression().at(i));
	    		args.push_back(val);
	    	}
    	}	

    	compile_call(f_name, args);

    	return NULL;
  	}

  	antlrcpp::Any visitPrintFunctionCall(zrParser::PrintFunctionCallContext *ctx) override 
  	{
    	Debug(": Print f call" << std::endl);

    	llvm::Value * val = visit(ctx->expression());

    	if(val->getType() == t_int)
    	{
    		llvm::CallInst::Create(m->getFunction("print_"), val, "", bb);
    	}
    	else if(val->getType() == t_bool)
    	{
    		llvm::CallInst::Create(m->getFunction("printb_"), val, "", bb);
    	}
		else
			throw CompileException("Print only supports int/bool");
    	
    	return NULL;
  	}

	antlrcpp::Any visitScanFunctionCall(zrParser::ScanFunctionCallContext *ctx) override 
	{
		Debug(": Scan f call" << std::endl);

    	std::vector<llvm::Value * > args;
    	llvm::CallInst::Create(m->getFunction("scan_"), args, "", bb);

    	return NULL;
	}

    antlrcpp::Any visitReturn_statement(zrParser::Return_statementContext *ctx) override
    {
    	Debug(": return" << std::endl);

    	if(ctx->expression() == NULL )
    	{
    		if(f->getFunctionType()->getReturnType() == t_void)
    			llvm::ReturnInst * ret = llvm::ReturnInst::Create(llvm_context, NULL, bb);
    		else 
    			throw CompileException(f->getName().lower() + " should return void");
    	}	
    	else
    	{
    		llvm::Value * val = visit(ctx->expression());

    		if(f->getFunctionType()->getReturnType() == t_void)
    			throw CompileException("void function " + f->getName().lower() + " cannot return value");

    		if(val->getType() != f->getFunctionType()->getReturnType())
    			throw CompileException(f->getName().lower() + " returns bad type");    			

    		else llvm::ReturnInst * ret = llvm::ReturnInst::Create(llvm_context, val, bb);
    	}

    	return NULL;
    }	

    antlrcpp::Any visitBreak_statement(zrParser::Break_statementContext *ctx) override
    {
    	Debug(": break" << std::endl);

    	if(inside_while > 0)
    		llvm::BranchInst::Create(while_stack.top(), bb);
    	else
    		throw CompileException("Break outside of while");

    	return NULL;
    }

   	llvm::Value * compile_call(std::string f_name, std::vector<llvm::Value * > args)
   	{
    	llvm::Function * func = m->getFunction(f_name);

        if (func == NULL)
        	throw CompileException("Function " + f_name + "does not exist");

        if (func->arg_size() != args.size())
        	throw CompileException(f_name + " called with wrong number of arguments");

        llvm::Function::arg_iterator f_args = func->arg_begin();
        for(int i=0;i < args.size(); i++)
        {
        	llvm::Value* arg = f_args;

        	if(arg->getType() != args.at(i)->getType())
        		throw CompileException(f_name + " called with wrong arguments");

        	++f_args;
        }

        llvm::Value * val = llvm::CallInst::Create(func, args, "", bb);

        return val;
   	}

  	antlrcpp::Any visitLtExpression(zrParser::LtExpressionContext *ctx) override 
  	{
  		Debug(": binary lt" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == exp_rv->getType())
			val = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SLT, exp_lv, exp_rv, "slt");
		else
			throw CompileException("Operation not supported");
	
		return val;
	}

	antlrcpp::Any visitScanCallExpression(zrParser::ScanCallExpressionContext *ctx) override 
	{
		Debug(": scan expr" << std::endl);

		std::vector<llvm::Value * > args;
    	llvm::Value * val = llvm::CallInst::Create(m->getFunction("scan_"), args, "", bb);

		return val;
	}

	antlrcpp::Any visitGtExpression(zrParser::GtExpressionContext *ctx) override 
	{
		Debug(": binary gt eq" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == exp_rv->getType())
			val = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SGT, exp_lv, exp_rv, "sgt");
		else
			throw CompileException("Operation not supported");

		return val;
	}

	antlrcpp::Any visitNotEqExpression(zrParser::NotEqExpressionContext *ctx) override 
	{
		Debug(": binary not eq" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == exp_rv->getType())
			val = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_NE, exp_lv, exp_rv, "ne");
		else
			throw CompileException("Operation not supported");

		return val;
	}

	antlrcpp::Any visitIdentifierExpression(zrParser::IdentifierExpressionContext *ctx) override 
	{
		Debug(": identifier" << std::endl);

    	std::string name = ctx->Identifier()->getText();

    	llvm::Value * address = scope->get_variable(name)->get_value();
    	llvm::Value * value = new llvm::LoadInst(address, name, bb);

    	return value;
	}

	antlrcpp::Any visitNotExpression(zrParser::NotExpressionContext *ctx) override 
	{
		Debug(": unary not" << std::endl);

		llvm::Value * exp_val = visit(ctx->expression());
    	llvm::Value * val;

    	if(exp_val->getType() == t_bool)
			val = llvm::BinaryOperator::Create(llvm::Instruction::Xor, llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 1)), exp_val, "", bb);
		else
			throw CompileException("Operation not supported");
    	
    	return val;
	}

	antlrcpp::Any visitMultiplyExpression(zrParser::MultiplyExpressionContext *ctx) override 
	{
		Debug(": binary mul" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
			val = llvm::BinaryOperator::Create(llvm::Instruction::Mul, exp_lv , exp_rv, "mul", bb);
		else
			throw CompileException("Operation not supported");
	
		return val;
	}

	antlrcpp::Any visitParanthesisExpression(zrParser::ParanthesisExpressionContext *ctx) override 
	{
		return visit(ctx->expression());
	}

	antlrcpp::Any visitGtEqExpression(zrParser::GtEqExpressionContext *ctx) override 
	{
		Debug(": binary gt eq" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == exp_rv->getType())
			val = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SGE, exp_lv, exp_rv, "sge");
		else
			throw CompileException("Operation not supported");

		return val;
	}

	antlrcpp::Any visitDivideExpression(zrParser::DivideExpressionContext *ctx) override 
	{
		Debug(": binary div" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
			val = llvm::BinaryOperator::Create(llvm::Instruction::SDiv, exp_lv , exp_rv, "sdiv", bb);
		else
			throw CompileException("Operation not supported");
    	
    	return val;
	}

	antlrcpp::Any visitOrExpression(zrParser::OrExpressionContext *ctx) override 
	{
	    Debug(": binary or" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

   		if(exp_lv->getType() == t_bool && exp_rv->getType() == t_bool)
			val = llvm::BinaryOperator::Create(llvm::Instruction::Or, exp_lv , exp_rv, "or", bb);
		else
			throw CompileException("Operation not supported");

		return val;
	}

	antlrcpp::Any visitUnaryMinusExpression(zrParser::UnaryMinusExpressionContext *ctx) override 
	{
		Debug(": unary minus" << std::endl);

		llvm::Value * exp_val = visit(ctx->expression());
    	llvm::Value * val;

		if(exp_val->getType() == t_int)
			val = llvm::BinaryOperator::Create(llvm::Instruction::Sub, llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)), exp_val, "", bb);
		else
			throw CompileException("Operation not supported");

    	return val;
	}

	antlrcpp::Any visitEqExpression(zrParser::EqExpressionContext *ctx) override 
	{
		Debug(": binary eq" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == exp_rv->getType())
			val = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_EQ, exp_lv, exp_rv, "eq");
		else
			throw CompileException("Operation not supported");

		return val;
	}

	antlrcpp::Any visitAndExpression(zrParser::AndExpressionContext *ctx) override 
	{
		Debug(": binary and" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == t_bool && exp_rv->getType() == t_bool)
			val = llvm::BinaryOperator::Create(llvm::Instruction::And, exp_lv , exp_rv, "and", bb);
		else
			throw CompileException("Operation not supported");

		return val;
	}

	antlrcpp::Any visitAddExpression(zrParser::AddExpressionContext *ctx) override 
	{
		Debug(": binary add" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
			val = llvm::BinaryOperator::Create(llvm::Instruction::Add, exp_lv , exp_rv, "add", bb);
		else
			throw CompileException("Operation not supported");
	
		return val;
	}

	antlrcpp::Any visitSubtractExpression(zrParser::SubtractExpressionContext *ctx) override 
	{
		Debug(": binary minus" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == t_int && exp_rv->getType() == t_int)
			val = llvm::BinaryOperator::Create(llvm::Instruction::Sub, exp_lv , exp_rv, "sub", bb);
		else
			throw CompileException("Operation not supported");
	
		return val;
	}

	antlrcpp::Any visitFunctionCallExpression(zrParser::FunctionCallExpressionContext *ctx) override 
	{
		Debug(": func call expr" << std::endl);

		std::string f_name = ctx->Identifier()->getText();
    	std::vector<llvm::Value * > args;

    	if(ctx->exprList() != NULL)
    	{
    		for(int i=0;i<ctx->exprList()->expression().size();i++)
    		{
	    		llvm::Value * val = visit(ctx->exprList()->expression().at(i));
	    		args.push_back(val);
    		}
    	}

    	return compile_call(f_name, args);
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

	antlrcpp::Any visitLtEqExpression(zrParser::LtEqExpressionContext *ctx) override 
	{
		Debug(": binary lt eq" << std::endl);

    	llvm::Value * exp_lv = visit(ctx->expression().at(0));
    	llvm::Value * exp_rv = visit(ctx->expression().at(1));

    	llvm::Value * val;

    	if(exp_lv->getType() == exp_rv->getType())
			val = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SLE, exp_lv, exp_rv, "sle");
		else
			throw CompileException("Operation not supported");

		return val;
	}	

    antlrcpp::Any visitBool_lit(zrParser::Bool_litContext *ctx) override
    {
    	Debug(": bool lit" << std::endl);

    	if(ctx->True() != NULL)
    		return llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 1));

    	if(ctx->False() != NULL)
			return llvm::ConstantInt::get(llvm_context, llvm::APInt(1, 0));
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

    void create_new_scope()
    {
    	scope = new Scope();
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