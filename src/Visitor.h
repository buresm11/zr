
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
	Scope * scope;

	static llvm::Type * t_int;
    static llvm::Type * t_bool;
    static llvm::Type * t_void;

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

    antlrcpp::Any visitBlock(zrParser::BlockContext *context)
    {
    	 Debug(": block" << std::endl);
    }

   	antlrcpp::Any visitGlobal_statement(zrParser::Global_statementContext *context)
   	{
   		Debug(": global_statement" << std::endl);

   		return visit(context->global_variable_def());
   	}

    antlrcpp::Any visitGlobal_variable_def(zrParser::Global_variable_defContext *context)
    {
    	Debug(": global_variable_def" << std::endl);

    	std::string type = context->Type_identifier()->getText();
    	std::string name = context->Identifier()->getText();

    	std::cout << type << "xx" << name << std::endl;

    	if(scope->has_variable(name))
    	{
    		//TODO already exists

    		ContextValue cv;
    		return cv;
    	}

    	if(context->literal() == NULL)
    	{
    		Type t = get_type_from_string(type);

    		if(t == IntType)
    		{
    			llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, NULL, name);
		        gv->setAlignment(4);
		        gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 0)));

		        Variable * variable = new Variable(gv, true);
		        scope->add_variable(name, variable);
    		}
    		else if(t == BoolType)
    		{
    			llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_bool, false, llvm::GlobalValue::CommonLinkage, NULL, name);
		        gv->setAlignment(4);
		        gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(8, 0)));

		        Variable * variable = new Variable(gv, true);
		        scope->add_variable(name, variable);
    		}
    	}
    	else
    	{
    		Literal * literal = visit(context->literal());
    		
    		Type t = get_type_from_string(type);

    		if(t == IntType)
    		{
    			llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, NULL, name);
		        gv->setAlignment(4);
		        gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, ((IntLiteral*)literal)->get_value())));

		        Variable * variable = new Variable(gv, true);
		        scope->add_variable(name, variable);
    		}
    		else if(t == BoolType)
    		{
    			llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_bool, false, llvm::GlobalValue::CommonLinkage, NULL, name);
		        gv->setAlignment(4);

		        bool val = ((IntLiteral*)literal)->get_value();

		        if(val) gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(8, 1)));
		        else gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(8, 0)));

		        Variable * variable = new Variable(gv, true);
		        scope->add_variable(name, variable);
    		}
    	}

    	ContextValue cv;
    	return cv;
    }

    antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *context)
    {
    	Debug(": function decl" << std::endl);

    	std::string func_name = context->Identifier();
    	Type func_ret_type = get_type_from_string(context->Type_identifier());

    	

    	ContextValue cv;
    	return cv;
    }

    /*virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Def();
    antlr4::tree::TerminalNode *Type_identifier();
    antlr4::tree::TerminalNode *Identifier();
    BlockContext *block();
    antlr4::tree::TerminalNode *End();
    Func_decl_arg_listContext *func_decl_arg_list();*/

    antlrcpp::Any visitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *context)
    {
    	Debug(": func decl arg list" << std::endl);

    	ContextValue cv;
    	return cv;
    }

    Type get_type_from_string(std::string type)
    {
        if(type.compare("int") == 0)
        {
            return IntType;
        }
        else if(type.compare("bool") == 0)
        {
            return BoolType;
        } 
    }

    antlrcpp::Any visitLiteral(zrParser::LiteralContext *context)
    {
    	Debug(": literal" << std::endl);

    	if(context->Number() != NULL)
    	{
    		Debug(": number literal" << std::endl);

    		std::string val = context->Number()->getText();
    		int number;

	        try
	        {
	            number = std::stoi(context->Number()->getText());
	        }
	        catch(std::invalid_argument & e)
	        { 
	        	//TODO
	        }
	        catch(std::out_of_range & e)
	        {
	        	//TODO
	        }

    		Literal * literal = new IntLiteral(number);
    		return literal;
    	}
    	else if(context->Bool() != NULL)
    	{
    		Debug(": bool literal" << std::endl);

    		std::string val = context->Bool()->getText();
    		bool value;

	        if(context->Bool()->getText().compare("true") == 0) 
	        {
	            value = true;
	        }
	        else
	        {
	            value = false;
	        }

    		Literal * literal = new BoolLiteral(value);
    		return literal;
    	}
    }

    antlrcpp::Any visitStatement(zrParser::StatementContext *context)
    {

    }

    antlrcpp::Any visitReturn_statement(zrParser::Return_statementContext *context)
    {

    }

    antlrcpp::Any visitAssignment(zrParser::AssignmentContext *context)
    {

    }

    antlrcpp::Any visitVariable_def(zrParser::Variable_defContext *context)
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

    antlrcpp::Any visitLiteralExpression(zrParser::LiteralExpressionContext *context)
    {

    }


    antlrcpp::Any visitNotEqExpression(zrParser::NotEqExpressionContext *context)
    {

    }

    antlrcpp::Any visitIdentifierExpression(zrParser::IdentifierExpressionContext *context)
    {

    }

    antlrcpp::Any visitModulusExpression(zrParser::ModulusExpressionContext *context)
    {

    }

    antlrcpp::Any visitNotExpression(zrParser::NotExpressionContext *context)
    {

    }

    antlrcpp::Any visitMultiplyExpression(zrParser::MultiplyExpressionContext *context)
    {

    }

    antlrcpp::Any visitGtEqExpression(zrParser::GtEqExpressionContext *context)
    {

    }

    antlrcpp::Any visitDivideExpression(zrParser::DivideExpressionContext *context)
    {

    }

    antlrcpp::Any visitOrExpression(zrParser::OrExpressionContext *context)
    {

    }

    antlrcpp::Any visitUnaryMinusExpression(zrParser::UnaryMinusExpressionContext *context)
    {

    }

    antlrcpp::Any visitEqExpression(zrParser::EqExpressionContext *context)
    {

    }

    antlrcpp::Any visitAndExpression(zrParser::AndExpressionContext *context)
    {

    }

    antlrcpp::Any visitAddExpression(zrParser::AddExpressionContext *context)
    {

    }

    antlrcpp::Any visitSubtractExpression(zrParser::SubtractExpressionContext *context)
    {

    }

    antlrcpp::Any visitFunctionCallExpression(zrParser::FunctionCallExpressionContext *context)
    {

    }

    antlrcpp::Any visitLtEqExpression(zrParser::LtEqExpressionContext *context)
    {

    }

};