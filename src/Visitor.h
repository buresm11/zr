
#pragma once

#include <iostream>

#include "llvm.h"
#include "zrVisitor.h"

class Visitor : public zrVisitor
{
	llvm::LLVMContext llvm_context;
	llvm::Module * m;

	static llvm::Type * t_int;
	static llvm::Type * t_string;
    static llvm::Type * t_bool;
    static llvm::Type * t_void;

public:

	antlrcpp::Any visitParse(zrParser::ParseContext *context)
	{
		std::cout << "Compilation started" << std::endl;

		m = new llvm::Module("zr", llvm_context);

		llvm::GlobalVariable * gv = new llvm::GlobalVariable(*m, t_int, false, llvm::GlobalValue::CommonLinkage, nullptr, "xxxx");
        gv->setAlignment(4);
        gv->setInitializer(llvm::ConstantInt::get(llvm_context, llvm::APInt(32, 5)));

		return m;
	}

    antlrcpp::Any visitTop_block(zrParser::Top_blockContext *context)
    {

    }

    antlrcpp::Any visitBlock(zrParser::BlockContext *context)
    {

    }

   	antlrcpp::Any visitGlobal_statement(zrParser::Global_statementContext *context)
   	{

   	}

    antlrcpp::Any visitGlobal_variable_def(zrParser::Global_variable_defContext *context)
    {

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

    antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *context)
    {

    }

    antlrcpp::Any visitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *context)
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

    antlrcpp::Any visitLiteral(zrParser::LiteralContext *context)
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