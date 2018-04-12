
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zrVisitor.h"


/**
 * This class provides an empty implementation of zrVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  zrBaseVisitor : public zrVisitor {
public:

  virtual antlrcpp::Any visitParse(zrParser::ParseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTop_block(zrParser::Top_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(zrParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobal_statement(zrParser::Global_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(zrParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreak_statement(zrParser::Break_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_statement(zrParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(zrParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_def(zrParser::Variable_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobal_variable_def(zrParser::Global_variable_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierFunctionCall(zrParser::IdentifierFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintFunctionCall(zrParser::PrintFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanFunctionCall(zrParser::ScanFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_statement(zrParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_stat(zrParser::If_statContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElse_if_stat(zrParser::Else_if_statContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElse_stat(zrParser::Else_statContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_statement(zrParser::While_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_decl(zrParser::Function_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_decl_arg(zrParser::Func_decl_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryExpression(zrParser::BinaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanCallExpression(zrParser::ScanCallExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpression(zrParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCallExpression(zrParser::FunctionCallExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpression(zrParser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpression(zrParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnOp(zrParser::UnOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinOp(zrParser::BinOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_lit(zrParser::Bool_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(zrParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }


};

