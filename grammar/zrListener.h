
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

  virtual void enterBreak_statement(zrParser::Break_statementContext *ctx) = 0;
  virtual void exitBreak_statement(zrParser::Break_statementContext *ctx) = 0;

  virtual void enterReturn_statement(zrParser::Return_statementContext *ctx) = 0;
  virtual void exitReturn_statement(zrParser::Return_statementContext *ctx) = 0;

  virtual void enterAssignment(zrParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(zrParser::AssignmentContext *ctx) = 0;

  virtual void enterVariable_def(zrParser::Variable_defContext *ctx) = 0;
  virtual void exitVariable_def(zrParser::Variable_defContext *ctx) = 0;

  virtual void enterGlobal_variable_def(zrParser::Global_variable_defContext *ctx) = 0;
  virtual void exitGlobal_variable_def(zrParser::Global_variable_defContext *ctx) = 0;

  virtual void enterIdentifierFunctionCall(zrParser::IdentifierFunctionCallContext *ctx) = 0;
  virtual void exitIdentifierFunctionCall(zrParser::IdentifierFunctionCallContext *ctx) = 0;

  virtual void enterPrintFunctionCall(zrParser::PrintFunctionCallContext *ctx) = 0;
  virtual void exitPrintFunctionCall(zrParser::PrintFunctionCallContext *ctx) = 0;

  virtual void enterScanFunctionCall(zrParser::ScanFunctionCallContext *ctx) = 0;
  virtual void exitScanFunctionCall(zrParser::ScanFunctionCallContext *ctx) = 0;

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

  virtual void enterFunc_decl_arg(zrParser::Func_decl_argContext *ctx) = 0;
  virtual void exitFunc_decl_arg(zrParser::Func_decl_argContext *ctx) = 0;

  virtual void enterBinaryExpression(zrParser::BinaryExpressionContext *ctx) = 0;
  virtual void exitBinaryExpression(zrParser::BinaryExpressionContext *ctx) = 0;

  virtual void enterScanCallExpression(zrParser::ScanCallExpressionContext *ctx) = 0;
  virtual void exitScanCallExpression(zrParser::ScanCallExpressionContext *ctx) = 0;

  virtual void enterIdentifierExpression(zrParser::IdentifierExpressionContext *ctx) = 0;
  virtual void exitIdentifierExpression(zrParser::IdentifierExpressionContext *ctx) = 0;

  virtual void enterFunctionCallExpression(zrParser::FunctionCallExpressionContext *ctx) = 0;
  virtual void exitFunctionCallExpression(zrParser::FunctionCallExpressionContext *ctx) = 0;

  virtual void enterUnaryExpression(zrParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(zrParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterLiteralExpression(zrParser::LiteralExpressionContext *ctx) = 0;
  virtual void exitLiteralExpression(zrParser::LiteralExpressionContext *ctx) = 0;

  virtual void enterUnOp(zrParser::UnOpContext *ctx) = 0;
  virtual void exitUnOp(zrParser::UnOpContext *ctx) = 0;

  virtual void enterBinOp(zrParser::BinOpContext *ctx) = 0;
  virtual void exitBinOp(zrParser::BinOpContext *ctx) = 0;

  virtual void enterBool_lit(zrParser::Bool_litContext *ctx) = 0;
  virtual void exitBool_lit(zrParser::Bool_litContext *ctx) = 0;

  virtual void enterNumber(zrParser::NumberContext *ctx) = 0;
  virtual void exitNumber(zrParser::NumberContext *ctx) = 0;


};

