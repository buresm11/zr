
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zrParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by zrParser.
 */
class  zrListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterParse(zrParser::ParseContext *ctx) = 0;
  virtual void exitParse(zrParser::ParseContext *ctx) = 0;

  virtual void enterTop_block(zrParser::Top_blockContext *ctx) = 0;
  virtual void exitTop_block(zrParser::Top_blockContext *ctx) = 0;

  virtual void enterBlock(zrParser::BlockContext *ctx) = 0;
  virtual void exitBlock(zrParser::BlockContext *ctx) = 0;

  virtual void enterGlobal_statement(zrParser::Global_statementContext *ctx) = 0;
  virtual void exitGlobal_statement(zrParser::Global_statementContext *ctx) = 0;

  virtual void enterStatement(zrParser::StatementContext *ctx) = 0;
  virtual void exitStatement(zrParser::StatementContext *ctx) = 0;

  virtual void enterReturn_statement(zrParser::Return_statementContext *ctx) = 0;
  virtual void exitReturn_statement(zrParser::Return_statementContext *ctx) = 0;

  virtual void enterAssignment(zrParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(zrParser::AssignmentContext *ctx) = 0;

  virtual void enterVariable_def(zrParser::Variable_defContext *ctx) = 0;
  virtual void exitVariable_def(zrParser::Variable_defContext *ctx) = 0;

  virtual void enterFunction_call(zrParser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(zrParser::Function_callContext *ctx) = 0;

  virtual void enterIf_statement(zrParser::If_statementContext *ctx) = 0;
  virtual void exitIf_statement(zrParser::If_statementContext *ctx) = 0;

  virtual void enterIf_stat(zrParser::If_statContext *ctx) = 0;
  virtual void exitIf_stat(zrParser::If_statContext *ctx) = 0;

  virtual void enterElse_if_stat(zrParser::Else_if_statContext *ctx) = 0;
  virtual void exitElse_if_stat(zrParser::Else_if_statContext *ctx) = 0;

  virtual void enterElse_stat(zrParser::Else_statContext *ctx) = 0;
  virtual void exitElse_stat(zrParser::Else_statContext *ctx) = 0;

  virtual void enterWhile_statement(zrParser::While_statementContext *ctx) = 0;
  virtual void exitWhile_statement(zrParser::While_statementContext *ctx) = 0;

  virtual void enterFunction_decl(zrParser::Function_declContext *ctx) = 0;
  virtual void exitFunction_decl(zrParser::Function_declContext *ctx) = 0;

  virtual void enterFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *ctx) = 0;
  virtual void exitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *ctx) = 0;

  virtual void enterLtExpression(zrParser::LtExpressionContext *ctx) = 0;
  virtual void exitLtExpression(zrParser::LtExpressionContext *ctx) = 0;

  virtual void enterGtExpression(zrParser::GtExpressionContext *ctx) = 0;
  virtual void exitGtExpression(zrParser::GtExpressionContext *ctx) = 0;

  virtual void enterBoolExpression(zrParser::BoolExpressionContext *ctx) = 0;
  virtual void exitBoolExpression(zrParser::BoolExpressionContext *ctx) = 0;

  virtual void enterNotEqExpression(zrParser::NotEqExpressionContext *ctx) = 0;
  virtual void exitNotEqExpression(zrParser::NotEqExpressionContext *ctx) = 0;

  virtual void enterNumberExpression(zrParser::NumberExpressionContext *ctx) = 0;
  virtual void exitNumberExpression(zrParser::NumberExpressionContext *ctx) = 0;

  virtual void enterIdentifierExpression(zrParser::IdentifierExpressionContext *ctx) = 0;
  virtual void exitIdentifierExpression(zrParser::IdentifierExpressionContext *ctx) = 0;

  virtual void enterModulusExpression(zrParser::ModulusExpressionContext *ctx) = 0;
  virtual void exitModulusExpression(zrParser::ModulusExpressionContext *ctx) = 0;

  virtual void enterNotExpression(zrParser::NotExpressionContext *ctx) = 0;
  virtual void exitNotExpression(zrParser::NotExpressionContext *ctx) = 0;

  virtual void enterMultiplyExpression(zrParser::MultiplyExpressionContext *ctx) = 0;
  virtual void exitMultiplyExpression(zrParser::MultiplyExpressionContext *ctx) = 0;

  virtual void enterGtEqExpression(zrParser::GtEqExpressionContext *ctx) = 0;
  virtual void exitGtEqExpression(zrParser::GtEqExpressionContext *ctx) = 0;

  virtual void enterDivideExpression(zrParser::DivideExpressionContext *ctx) = 0;
  virtual void exitDivideExpression(zrParser::DivideExpressionContext *ctx) = 0;

  virtual void enterOrExpression(zrParser::OrExpressionContext *ctx) = 0;
  virtual void exitOrExpression(zrParser::OrExpressionContext *ctx) = 0;

  virtual void enterUnaryMinusExpression(zrParser::UnaryMinusExpressionContext *ctx) = 0;
  virtual void exitUnaryMinusExpression(zrParser::UnaryMinusExpressionContext *ctx) = 0;

  virtual void enterEqExpression(zrParser::EqExpressionContext *ctx) = 0;
  virtual void exitEqExpression(zrParser::EqExpressionContext *ctx) = 0;

  virtual void enterAndExpression(zrParser::AndExpressionContext *ctx) = 0;
  virtual void exitAndExpression(zrParser::AndExpressionContext *ctx) = 0;

  virtual void enterStringExpression(zrParser::StringExpressionContext *ctx) = 0;
  virtual void exitStringExpression(zrParser::StringExpressionContext *ctx) = 0;

  virtual void enterAddExpression(zrParser::AddExpressionContext *ctx) = 0;
  virtual void exitAddExpression(zrParser::AddExpressionContext *ctx) = 0;

  virtual void enterSubtractExpression(zrParser::SubtractExpressionContext *ctx) = 0;
  virtual void exitSubtractExpression(zrParser::SubtractExpressionContext *ctx) = 0;

  virtual void enterFunctionCallExpression(zrParser::FunctionCallExpressionContext *ctx) = 0;
  virtual void exitFunctionCallExpression(zrParser::FunctionCallExpressionContext *ctx) = 0;

  virtual void enterLtEqExpression(zrParser::LtEqExpressionContext *ctx) = 0;
  virtual void exitLtEqExpression(zrParser::LtEqExpressionContext *ctx) = 0;


};
