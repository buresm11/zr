
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zrParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by zrParser.
 */
class  zrVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by zrParser.
   */
    virtual antlrcpp::Any visitParse(zrParser::ParseContext *context) = 0;

    virtual antlrcpp::Any visitTop_block(zrParser::Top_blockContext *context) = 0;

    virtual antlrcpp::Any visitBlock(zrParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitGlobal_statement(zrParser::Global_statementContext *context) = 0;

    virtual antlrcpp::Any visitStatement(zrParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitReturn_statement(zrParser::Return_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(zrParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitVariable_def(zrParser::Variable_defContext *context) = 0;

    virtual antlrcpp::Any visitGlobal_variable_def(zrParser::Global_variable_defContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(zrParser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(zrParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitIf_stat(zrParser::If_statContext *context) = 0;

    virtual antlrcpp::Any visitElse_if_stat(zrParser::Else_if_statContext *context) = 0;

    virtual antlrcpp::Any visitElse_stat(zrParser::Else_statContext *context) = 0;

    virtual antlrcpp::Any visitWhile_statement(zrParser::While_statementContext *context) = 0;

    virtual antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl_arg(zrParser::Func_decl_argContext *context) = 0;

    virtual antlrcpp::Any visitGtEqExpression(zrParser::GtEqExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLtEqExpression(zrParser::LtEqExpressionContext *context) = 0;

    virtual antlrcpp::Any visitGtExpression(zrParser::GtExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLtExpression(zrParser::LtExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqExpression(zrParser::EqExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNotEqExpression(zrParser::NotEqExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryMinusExpression(zrParser::UnaryMinusExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAddExpression(zrParser::AddExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSubtractExpression(zrParser::SubtractExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpression(zrParser::NumberExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierExpression(zrParser::IdentifierExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallExpression(zrParser::FunctionCallExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplyExpression(zrParser::MultiplyExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDivideExpression(zrParser::DivideExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNumber(zrParser::NumberContext *context) = 0;


};

