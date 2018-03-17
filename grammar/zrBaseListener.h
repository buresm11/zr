
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zrListener.h"


/**
 * This class provides an empty implementation of zrListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  zrBaseListener : public zrListener {
public:

  virtual void enterParse(zrParser::ParseContext * /*ctx*/) override { }
  virtual void exitParse(zrParser::ParseContext * /*ctx*/) override { }

  virtual void enterTop_block(zrParser::Top_blockContext * /*ctx*/) override { }
  virtual void exitTop_block(zrParser::Top_blockContext * /*ctx*/) override { }

  virtual void enterBlock(zrParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(zrParser::BlockContext * /*ctx*/) override { }

  virtual void enterGlobal_statement(zrParser::Global_statementContext * /*ctx*/) override { }
  virtual void exitGlobal_statement(zrParser::Global_statementContext * /*ctx*/) override { }

  virtual void enterStatement(zrParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(zrParser::StatementContext * /*ctx*/) override { }

  virtual void enterReturn_statement(zrParser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(zrParser::Return_statementContext * /*ctx*/) override { }

  virtual void enterAssignment(zrParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(zrParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterVariable_def(zrParser::Variable_defContext * /*ctx*/) override { }
  virtual void exitVariable_def(zrParser::Variable_defContext * /*ctx*/) override { }

  virtual void enterGlobal_variable_def(zrParser::Global_variable_defContext * /*ctx*/) override { }
  virtual void exitGlobal_variable_def(zrParser::Global_variable_defContext * /*ctx*/) override { }

  virtual void enterIdentifierFunctionCall(zrParser::IdentifierFunctionCallContext * /*ctx*/) override { }
  virtual void exitIdentifierFunctionCall(zrParser::IdentifierFunctionCallContext * /*ctx*/) override { }

  virtual void enterPrintFunctionCall(zrParser::PrintFunctionCallContext * /*ctx*/) override { }
  virtual void exitPrintFunctionCall(zrParser::PrintFunctionCallContext * /*ctx*/) override { }

  virtual void enterScanFunctionCall(zrParser::ScanFunctionCallContext * /*ctx*/) override { }
  virtual void exitScanFunctionCall(zrParser::ScanFunctionCallContext * /*ctx*/) override { }

  virtual void enterIf_statement(zrParser::If_statementContext * /*ctx*/) override { }
  virtual void exitIf_statement(zrParser::If_statementContext * /*ctx*/) override { }

  virtual void enterIf_stat(zrParser::If_statContext * /*ctx*/) override { }
  virtual void exitIf_stat(zrParser::If_statContext * /*ctx*/) override { }

  virtual void enterElse_if_stat(zrParser::Else_if_statContext * /*ctx*/) override { }
  virtual void exitElse_if_stat(zrParser::Else_if_statContext * /*ctx*/) override { }

  virtual void enterElse_stat(zrParser::Else_statContext * /*ctx*/) override { }
  virtual void exitElse_stat(zrParser::Else_statContext * /*ctx*/) override { }

  virtual void enterWhile_statement(zrParser::While_statementContext * /*ctx*/) override { }
  virtual void exitWhile_statement(zrParser::While_statementContext * /*ctx*/) override { }

  virtual void enterFunction_decl(zrParser::Function_declContext * /*ctx*/) override { }
  virtual void exitFunction_decl(zrParser::Function_declContext * /*ctx*/) override { }

  virtual void enterFunc_decl_arg_list(zrParser::Func_decl_arg_listContext * /*ctx*/) override { }
  virtual void exitFunc_decl_arg_list(zrParser::Func_decl_arg_listContext * /*ctx*/) override { }

  virtual void enterFunc_decl_arg(zrParser::Func_decl_argContext * /*ctx*/) override { }
  virtual void exitFunc_decl_arg(zrParser::Func_decl_argContext * /*ctx*/) override { }

  virtual void enterGtEqExpression(zrParser::GtEqExpressionContext * /*ctx*/) override { }
  virtual void exitGtEqExpression(zrParser::GtEqExpressionContext * /*ctx*/) override { }

  virtual void enterLtEqExpression(zrParser::LtEqExpressionContext * /*ctx*/) override { }
  virtual void exitLtEqExpression(zrParser::LtEqExpressionContext * /*ctx*/) override { }

  virtual void enterGtExpression(zrParser::GtExpressionContext * /*ctx*/) override { }
  virtual void exitGtExpression(zrParser::GtExpressionContext * /*ctx*/) override { }

  virtual void enterLtExpression(zrParser::LtExpressionContext * /*ctx*/) override { }
  virtual void exitLtExpression(zrParser::LtExpressionContext * /*ctx*/) override { }

  virtual void enterEqExpression(zrParser::EqExpressionContext * /*ctx*/) override { }
  virtual void exitEqExpression(zrParser::EqExpressionContext * /*ctx*/) override { }

  virtual void enterNotEqExpression(zrParser::NotEqExpressionContext * /*ctx*/) override { }
  virtual void exitNotEqExpression(zrParser::NotEqExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryMinusExpression(zrParser::UnaryMinusExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryMinusExpression(zrParser::UnaryMinusExpressionContext * /*ctx*/) override { }

  virtual void enterScanCallExpression(zrParser::ScanCallExpressionContext * /*ctx*/) override { }
  virtual void exitScanCallExpression(zrParser::ScanCallExpressionContext * /*ctx*/) override { }

  virtual void enterAddExpression(zrParser::AddExpressionContext * /*ctx*/) override { }
  virtual void exitAddExpression(zrParser::AddExpressionContext * /*ctx*/) override { }

  virtual void enterSubtractExpression(zrParser::SubtractExpressionContext * /*ctx*/) override { }
  virtual void exitSubtractExpression(zrParser::SubtractExpressionContext * /*ctx*/) override { }

  virtual void enterNumberExpression(zrParser::NumberExpressionContext * /*ctx*/) override { }
  virtual void exitNumberExpression(zrParser::NumberExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifierExpression(zrParser::IdentifierExpressionContext * /*ctx*/) override { }
  virtual void exitIdentifierExpression(zrParser::IdentifierExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionCallExpression(zrParser::FunctionCallExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionCallExpression(zrParser::FunctionCallExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplyExpression(zrParser::MultiplyExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplyExpression(zrParser::MultiplyExpressionContext * /*ctx*/) override { }

  virtual void enterDivideExpression(zrParser::DivideExpressionContext * /*ctx*/) override { }
  virtual void exitDivideExpression(zrParser::DivideExpressionContext * /*ctx*/) override { }

  virtual void enterNumber(zrParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(zrParser::NumberContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

