
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
        bb = llvm::BasicBlock::Create(llvm_context, "", this->f);

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

    	}
    	else if(context->if_statement() != NULL)
    	{

    	}
    	else if(context->while_statement() != NULL)
    	{

    	}
    	else if(context->return_statement() != NULL)
    	{

    	}

    	return NULL;
    }

    /*antlr4::tree::TerminalNode *Type_identifier();
    antlr4::tree::TerminalNode *Identifier();
    ExpressionContext *expression();*/

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
    		visit(context->expression());
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

    }

    antlrcpp::Any visitFunction_call(zrParser::Function_callContext *context)
    {

    }

    antlrcpp::Any visitIf_statement(zrParser::If_statementContext *context)
    {

    }

    antlrcpp::Any visitIf_stat(zrParser::If_statContext *context)
    {

    }

    antlrcpp::Any visitElse_if_stat(zrParser::Else_if_statContext *context)
    {

    }

    antlrcpp::Any visitElse_stat(zrParser::Else_statContext *context)
    {

    }

    antlrcpp::Any visitWhile_statement(zrParser::While_statementContext *context)
    {

    }

    antlrcpp::Any visitLtExpression(zrParser::LtExpressionContext *context)
    {

    }

    antlrcpp::Any visitGtExpression(zrParser::GtExpressionContext *context)
    {

    }

    antlrcpp::Any visitNotEqExpression(zrParser::NotEqExpressionContext *context)
    {

    }

    antlrcpp::Any visitIdentifierExpression(zrParser::IdentifierExpressionContext *context)
    {

    }

    antlrcpp::Any visitNotExpression(zrParser::NotExpressionContext *context)
    {

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

    }

};