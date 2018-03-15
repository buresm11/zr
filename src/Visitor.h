
#pragma once

#include <iostream>
#include <vector>

#include "antlr4-runtime.h"
#include "llvm.h"
#include "zrVisitor.h"
#include "ContextValue.h"
#include "Type.h"
#include "Literal.h"
#include "IntLiteral.h"
#include "BoolLiteral.h"
#include "Scope.h"

#define DEBUG_ENABLED

#ifdef DEBUG_ENABLED
#define Debug(x) std::cout << x;
#else
#define Debug(x) 
#endif 

class Visitor : public zrVisitor
{
	llvm::LLVMContext llvm_context;
	llvm::Module * m;
	llvm::Function * f;
	llvm::BasicBlock * bb;
	llvm::BasicBlock * next;
	Scope * scope;

	static llvm::Type * t_int;

public:

	llvm::Module * compile(antlr4::tree::ParseTree *tree)
	{
		m = new llvm::Module("zr", llvm_context);
		scope = new Scope();

		visit(tree);

		return m;
	}

	antlrcpp::Any visitParse(zrParser::ParseContext *context)
	{
		Debug(": parse" << std::endl);

		return visit(context->top_block());		
	}

    antlrcpp::Any visitTop_block(zrParser::Top_blockContext *context)
    {
    	Debug(": top_block" << std::endl);

    	for(int i=0;i<context->global_statement().size();i++)
    	{
    		visit(context->global_statement().at(i));	
    	}

    	for(int i=0;i<context->function_decl().size();i++)
    	{
    		visit(context->function_decl().at(i));
    	}

    	ContextValue cv;
    	return cv;
    }

   	antlrcpp::Any visitGlobal_statement(zrParser::Global_statementContext *context)
   	{
   		Debug(": global_statement" << std::endl);

   		return visit(context->global_variable_def());
   	}

    antlrcpp::Any visitGlobal_variable_def(zrParser::Global_variable_defContext *context)
    {
    	Debug(": global_variable_def" << std::endl);

    	std::string name = context->Identifier()->getText();

    	if(scope->has_variable(name))
    	{
    		//TODO already exists

    		return NULL;
    	}

    	if(context->number() == NULL)
    	{
    		llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, NULL, name);
		    gv->setAlignment(4);
		    gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)));

		    Variable * variable = new Variable(gv, true);
		    scope->add_variable(name, variable);
    	}
    	else
    	{
    		llvm::ConstantInt * number = visit(context->number());

    		llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, NULL, name);
		    gv->setAlignment(4);
		    gv->setInitializer(number);

		    Variable * variable = new Variable(gv, true);
		    scope->add_variable(name, variable);
    	}

    	return NULL;
    }

    antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *context)
    {
    	Debug(": function decl" << std::endl);

    	std::string func_name = context->Identifier()->getText();

    	std::vector<std::string> args = visit(context->func_decl_arg_list());

    	std::vector<llvm::Type * > at;
        for (int i = 0; i < args.size(); i++)
            at.push_back(t_int);

        llvm::FunctionType * ft = llvm::FunctionType::get(t_int, at, false);

        f = llvm::Function::Create(ft, llvm::GlobalValue::ExternalLinkage, func_name, m);
        f->setCallingConv(llvm::CallingConv::C);

		scope = new Scope(scope);
        bb = llvm::BasicBlock::Create(llvm_context, "entry_" + func_name, this->f);

        llvm::Function::arg_iterator f_args = f->arg_begin();

        for(int i=0;i < args.size(); i++)
        {
        	std::string name = args.at(i);
        	llvm::Value* arg = f_args++;

        	if(scope->has_variable(name))
        	{
        		std::cout << "Redefinition" << std::endl;
        	}

        	llvm::AllocaInst * loc = new llvm::AllocaInst(t_int, name, bb);

        	Variable * variable = new Variable(loc, true);
		    scope->add_variable(name, variable);

		    new llvm::StoreInst(arg, loc, false, bb);

		    arg->setName(name);
		    loc->setName(name);
        }

        visit(context->block());

    	return NULL;
    }

    antlrcpp::Any visitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *context)
    {
    	std::vector<std::string> args;

    	for(int i=0;i<context->func_decl_arg().size();i++)
    	{
    		args.push_back(visit(context->func_decl_arg().at(i)));
    	}

    	return args;
    }

    antlrcpp::Any visitFunc_decl_arg(zrParser::Func_decl_argContext *context)
    {
    	return context->Identifier()->getText();
    }

    antlrcpp::Any visitBlock(zrParser::BlockContext *context)
    {
    	Debug(": block" << std::endl);

    	for(int i=0;i<context->statement().size();i++)
    	{
    		visit(context->statement().at(i));
    	}

    	return NULL;
    }

    antlrcpp::Any visitNumber(zrParser::NumberContext *context)
    {
    	Debug(": visit number" << std::endl);

		std::string text = context->Integer()->getText();
    	
		return llvm::ConstantInt::get(llvm_context, llvm::APInt(32, parse_int(text)));
    }	

    antlrcpp::Any visitNumberExpression(zrParser::NumberExpressionContext *context)
    {
    	Debug(": visit number" << std::endl);

    	std::string text = context->number()->getText();
    	
    	llvm::Value * val = llvm::ConstantInt::get(llvm_context, llvm::APInt(32, parse_int(text)));

    	return val;
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
        	//TODO 
        }
        catch(std::out_of_range & e)
        {
        	//TODO
        }

        return number;
    }

    antlrcpp::Any visitStatement(zrParser::StatementContext *context)
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
    		visit(context->if_statement());
    	}
    	else if(context->while_statement() != NULL)
    	{
    		visit(context->while_statement());
    	}
    	else if(context->return_statement() != NULL)
    	{
    		//visit(context->return_statement());
    	}

    	return NULL;
    }

    antlrcpp::Any visitVariable_def(zrParser::Variable_defContext *context)
    {
    	Debug(": variable def" << std::endl);

    	std::string name = context->Identifier()->getText();

    	if(scope->has_variable(name))
    	{
    		std::cout << "Redefinitioxn" << std::endl;
    	}

    	if(context->expression())
    	{
    		llvm::Value * val = visit(context->expression());
    		llvm::AllocaInst * loc = new llvm::AllocaInst(t_int, name, bb);

    		Variable * variable = new Variable(loc, false);

    		new llvm::StoreInst(val, loc, false, bb);

    		scope->add_variable(name, variable);
    	}
    	else
    	{
    		Variable * variable = new Variable(new llvm::AllocaInst(t_int, name, bb), false);
    		scope->add_variable(name, variable);
    	}

    	return NULL;
    }

    antlrcpp::Any visitAddExpression(zrParser::AddExpressionContext *context)
    {
    	Debug(": add expr" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::Value * val = llvm::BinaryOperator::Create(llvm::Instruction::Add, lv , rv, "", bb);

    	return val;
    }

    antlrcpp::Any visitReturn_statement(zrParser::Return_statementContext *context)
    {

    }

    antlrcpp::Any visitAssignment(zrParser::AssignmentContext *context)
    {
    	Debug(": assigment" << std::endl);

    	std::string name = context->Identifier()->getText();

    	if(!scope->has_variable(name))
    	{
    		//TODO
    	}

    	llvm::Value * val = visit(context->expression());
    	llvm::Value * address = scope->get_variable(name)->get_value();

    	new llvm::StoreInst(val, address, false, bb);

    	return NULL;
    }

    antlrcpp::Any visitFunction_call(zrParser::Function_callContext *context)
    {

    }

    antlrcpp::Any visitIf_statement(zrParser::If_statementContext *context)
    {
    	Debug(": if statatement" << std::endl);

    	compile_if(context->if_stat(), context->else_if_stat(), context->else_stat());

    	return NULL;
    }

    antlrcpp::Any visitIf_stat(zrParser::If_statContext *context)
    {

    }

    void compile_if(zrParser::If_statContext * if_context, std::vector<zrParser::Else_if_statContext *> else_if_context, zrParser::Else_statContext * else_context)
    {
    	llvm::BasicBlock * if_case = llvm::BasicBlock::Create(llvm_context, "if_case", f);
    	llvm::BasicBlock ** elif_t_cases = new llvm::BasicBlock * [else_if_context.size()];
    	llvm::BasicBlock ** elif_f_cases = new llvm::BasicBlock * [else_if_context.size()];
    	
    	for(int i=0;i<else_if_context.size();i++)
	    {
	    	elif_f_cases[i] = llvm::BasicBlock::Create(llvm_context, "elif_f_case" + std::to_string(i), f);
	      	elif_t_cases[i] = llvm::BasicBlock::Create(llvm_context, "elif_t_case" + std::to_string(i), f);
	    }

	    llvm::BasicBlock * else_case;

		if(else_context != NULL) else_case = llvm::BasicBlock::Create(llvm_context, "else_case", f);

    	llvm::BasicBlock * next = llvm::BasicBlock::Create(llvm_context, "next", f);;

    	if(else_if_context.size() > 0)
    	{	    	
    		compile_if_case(if_context->cond_expression(), if_context->block(), if_case, elif_f_cases[0], next);

    		for(int i=0;i<else_if_context.size()-1;i++)
		    {
		    	bb = elif_f_cases[i];
		      	compile_if_case(else_if_context.at(i)->cond_expression(), else_if_context.at(i)->block(), elif_t_cases[i], elif_f_cases[i+1], next);
		    }

		    bb = elif_f_cases[else_if_context.size()-1];

		    if(else_context != NULL)
		    	compile_if_case(else_if_context.at(else_if_context.size()-1)->cond_expression(), else_if_context.at(else_if_context.size()-1)->block(), elif_t_cases[else_if_context.size()-1], else_case, next);
    		else
    			compile_if_case(else_if_context.at(else_if_context.size()-1)->cond_expression(), else_if_context.at(else_if_context.size()-1)->block(), elif_t_cases[else_if_context.size()-1], next, next);
    	}
    	else
    	{
    		if(else_context != NULL)
	        {
	        	compile_if_case(if_context->cond_expression(), if_context->block(), if_case, else_case, next);
	        	compile_else_case(else_context->block(), else_case,next);
	        }
	        else
	        {
	        	compile_if_case(if_context->cond_expression(), if_context->block(), if_case, next, next);
	        }
    	}
    }

    void compile_if_case(zrParser::Cond_expressionContext * cond, zrParser::BlockContext * true_block, llvm::BasicBlock * true_case, llvm::BasicBlock * false_case, llvm::BasicBlock * next)
    {
    	llvm::ICmpInst * cmp = visit(cond);
    	llvm::BranchInst::Create(true_case, false_case, cmp, bb);

    	scope = new Scope(scope);

    	bb = true_case;
    	visit(true_block);

    	llvm::BranchInst::Create(next, bb);

    	Scope * tmp = scope;
    	scope = scope->get_parent();
    	delete tmp;
    }

    void compile_else_case(zrParser::BlockContext * else_block, llvm::BasicBlock * else_case, llvm::BasicBlock * next)
    {
    	scope = new Scope(scope);

    	bb = else_case;
    	visit(else_block);

    	llvm::BranchInst::Create(next, bb);

    	Scope * tmp = scope;
    	scope = scope->get_parent();
    	delete tmp;
    }

    antlrcpp::Any visitElse_if_stat(zrParser::Else_if_statContext *context)
    {

    }

    antlrcpp::Any visitElse_stat(zrParser::Else_statContext *context)
    {

    }

    antlrcpp::Any visitWhile_statement(zrParser::While_statementContext *context)
    {
    	/*llvm::BasicBlock * loop = llvm::BasicBlock::Create(llvm_context, "preface", f);
    	llvm::BasicBlock * loop = llvm::BasicBlock::Create(llvm_context, "loop", f);
    	llvm::BasicBlock * next = llvm::BasicBlock::Create(llvm_context, "next", f);

    	llvm::ICmpInst * cmp = visit(cond);
    	llvm::BranchInst::Create(loop, next, cmp, bb);

    	scope = new Scope(scope);

    	bb = loop;
    	visit(context->block());*/


    	return NULL;
    }

    antlrcpp::Any visitLtExpression(zrParser::LtExpressionContext *context)
    {
    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::ICmpInst * cmp = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SLT, lv, rv, "");

    	return cmp;
    }

    antlrcpp::Any visitGtExpression(zrParser::GtExpressionContext *context)
    {
    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::ICmpInst * cmp = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SGT, lv, rv, "");

    	return cmp;
    }

    antlrcpp::Any visitIdentifierExpression(zrParser::IdentifierExpressionContext *context)
    {
    	Debug(": Identifier" << std::endl);

    	std::string name = context->Identifier()->getText();

    	llvm::Value * address = scope->get_variable(name)->get_value();
    	llvm::Value * value = new llvm::LoadInst(address, name, bb);

    	return value;
    }

    antlrcpp::Any visitNotEqExpression(zrParser::NotEqExpressionContext *context)
    {
    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::ICmpInst * cmp = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_NE, lv, rv, "");

    	return cmp;
    }

    antlrcpp::Any visitMultiplyExpression(zrParser::MultiplyExpressionContext *context)
    {
    	Debug(": add expr" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::Value * val = llvm::BinaryOperator::Create(llvm::Instruction::Mul, lv , rv, "", bb);

    	return val;
    }

    antlrcpp::Any visitGtEqExpression(zrParser::GtEqExpressionContext *context)
    {
    	Debug(": eq expression" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::ICmpInst * cmp = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SGE, lv, rv, "");

    	return cmp;
    }

    antlrcpp::Any visitDivideExpression(zrParser::DivideExpressionContext *context)
    {
    	Debug(": add expr" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::Value * val = llvm::BinaryOperator::Create(llvm::Instruction::UDiv, lv , rv, "", bb);

    	return val;
    }

    antlrcpp::Any visitUnaryMinusExpression(zrParser::UnaryMinusExpressionContext *context)
    {
    	Debug(": add expr" << std::endl);

    	llvm::Value * v = visit(context->expression());

    	llvm::Value * val = llvm::BinaryOperator::Create(llvm::Instruction::Sub, llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)) , v, "", bb);

    	return val;
    }

    antlrcpp::Any visitEqExpression(zrParser::EqExpressionContext *context)
    {
    	Debug(": eq expression" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::ICmpInst * cmp = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_EQ, lv, rv, "");

    	return cmp;
    }

    antlrcpp::Any visitSubtractExpression(zrParser::SubtractExpressionContext *context)
    {
    	Debug(": add expr" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::Value * val = llvm::BinaryOperator::Create(llvm::Instruction::Sub, lv , rv, "", bb);

    	return val;
    }

    antlrcpp::Any visitFunctionCallExpression(zrParser::FunctionCallExpressionContext *context)
    {

    }

    antlrcpp::Any visitLtEqExpression(zrParser::LtEqExpressionContext *context)
    {
    	Debug(": eq expression" << std::endl);

    	llvm::Value * lv = visit(context->expression().at(0));
    	llvm::Value * rv = visit(context->expression().at(1));

    	llvm::ICmpInst * cmp = new llvm::ICmpInst(*bb, llvm::ICmpInst::ICMP_SLE, lv, rv, "");

    	return cmp;
    }
};