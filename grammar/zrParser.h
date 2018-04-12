
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zrParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, Integer = 6, Def = 7, 
    If = 8, Else = 9, Return = 10, Break = 11, While = 12, To = 13, Do = 14, 
    End = 15, Print = 16, Scan = 17, True = 18, False = 19, Void = 20, Or = 21, 
    And = 22, Equals = 23, NEquals = 24, GTEquals = 25, LTEquals = 26, Excl = 27, 
    Gt = 28, Lt = 29, Add = 30, Minus = 31, Multiply = 32, Divide = 33, 
    Type_identifier = 34, Identifier = 35, String = 36, Comment = 37, Space = 38
  };

  enum {
    RuleParse = 0, RuleTop_block = 1, RuleBlock = 2, RuleGlobal_statement = 3, 
    RuleStatement = 4, RuleBreak_statement = 5, RuleReturn_statement = 6, 
    RuleAssignment = 7, RuleVariable_def = 8, RuleGlobal_variable_def = 9, 
    RuleFunction_call = 10, RuleIf_statement = 11, RuleIf_stat = 12, RuleElse_if_stat = 13, 
    RuleElse_stat = 14, RuleWhile_statement = 15, RuleFunction_decl = 16, 
    RuleFunc_decl_arg_list = 17, RuleFunc_decl_arg = 18, RuleExpression = 19, 
    RuleUnOp = 20, RuleBinOp = 21, RuleBool_lit = 22, RuleNumber = 23
  };

  zrParser(antlr4::TokenStream *input);
  ~zrParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ParseContext;
  class Top_blockContext;
  class BlockContext;
  class Global_statementContext;
  class StatementContext;
  class Break_statementContext;
  class Return_statementContext;
  class AssignmentContext;
  class Variable_defContext;
  class Global_variable_defContext;
  class Function_callContext;
  class If_statementContext;
  class If_statContext;
  class Else_if_statContext;
  class Else_statContext;
  class While_statementContext;
  class Function_declContext;
  class Func_decl_arg_listContext;
  class Func_decl_argContext;
  class ExpressionContext;
  class UnOpContext;
  class BinOpContext;
  class Bool_litContext;
  class NumberContext; 

  class  ParseContext : public antlr4::ParserRuleContext {
  public:
    ParseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Top_blockContext *top_block();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParseContext* parse();

  class  Top_blockContext : public antlr4::ParserRuleContext {
  public:
    Top_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Function_declContext *> function_decl();
    Function_declContext* function_decl(size_t i);
    std::vector<Global_statementContext *> global_statement();
    Global_statementContext* global_statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Top_blockContext* top_block();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Global_statementContext : public antlr4::ParserRuleContext {
  public:
    Global_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Global_variable_defContext *global_variable_def();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_statementContext* global_statement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_defContext *variable_def();
    AssignmentContext *assignment();
    Function_callContext *function_call();
    If_statementContext *if_statement();
    While_statementContext *while_statement();
    Return_statementContext *return_statement();
    Break_statementContext *break_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Break_statementContext : public antlr4::ParserRuleContext {
  public:
    Break_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Break();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_statementContext* break_statement();

  class  Return_statementContext : public antlr4::ParserRuleContext {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_statementContext* return_statement();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Variable_defContext : public antlr4::ParserRuleContext {
  public:
    Variable_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type_identifier();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_defContext* variable_def();

  class  Global_variable_defContext : public antlr4::ParserRuleContext {
  public:
    Global_variable_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type_identifier();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_variable_defContext* global_variable_def();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Function_callContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Function_callContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ScanFunctionCallContext : public Function_callContext {
  public:
    ScanFunctionCallContext(Function_callContext *ctx);

    antlr4::tree::TerminalNode *Scan();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierFunctionCallContext : public Function_callContext {
  public:
    IdentifierFunctionCallContext(Function_callContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrintFunctionCallContext : public Function_callContext {
  public:
    PrintFunctionCallContext(Function_callContext *ctx);

    antlr4::tree::TerminalNode *Print();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Function_callContext* function_call();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_statContext *if_stat();
    antlr4::tree::TerminalNode *End();
    std::vector<Else_if_statContext *> else_if_stat();
    Else_if_statContext* else_if_stat(size_t i);
    Else_statContext *else_stat();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  If_statContext : public antlr4::ParserRuleContext {
  public:
    If_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Do();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statContext* if_stat();

  class  Else_if_statContext : public antlr4::ParserRuleContext {
  public:
    Else_if_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Else();
    antlr4::tree::TerminalNode *If();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Do();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_if_statContext* else_if_stat();

  class  Else_statContext : public antlr4::ParserRuleContext {
  public:
    Else_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Else();
    antlr4::tree::TerminalNode *Do();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_statContext* else_stat();

  class  While_statementContext : public antlr4::ParserRuleContext {
  public:
    While_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Do();
    BlockContext *block();
    antlr4::tree::TerminalNode *End();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_statementContext* while_statement();

  class  Function_declContext : public antlr4::ParserRuleContext {
  public:
    Function_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Def();
    antlr4::tree::TerminalNode *Identifier();
    BlockContext *block();
    antlr4::tree::TerminalNode *End();
    antlr4::tree::TerminalNode *Type_identifier();
    antlr4::tree::TerminalNode *Void();
    Func_decl_arg_listContext *func_decl_arg_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_declContext* function_decl();

  class  Func_decl_arg_listContext : public antlr4::ParserRuleContext {
  public:
    Func_decl_arg_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Func_decl_argContext *> func_decl_arg();
    Func_decl_argContext* func_decl_arg(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_decl_arg_listContext* func_decl_arg_list();

  class  Func_decl_argContext : public antlr4::ParserRuleContext {
  public:
    Func_decl_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type_identifier();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_decl_argContext* func_decl_arg();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryExpressionContext : public ExpressionContext {
  public:
    BinaryExpressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    BinOpContext *binOp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ScanCallExpressionContext : public ExpressionContext {
  public:
    ScanCallExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Scan();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierExpressionContext : public ExpressionContext {
  public:
    IdentifierExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallExpressionContext : public ExpressionContext {
  public:
    FunctionCallExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExpressionContext : public ExpressionContext {
  public:
    UnaryExpressionContext(ExpressionContext *ctx);

    UnOpContext *unOp();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralExpressionContext : public ExpressionContext {
  public:
    LiteralExpressionContext(ExpressionContext *ctx);

    Bool_litContext *bool_lit();
    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  UnOpContext : public antlr4::ParserRuleContext {
  public:
    UnOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Excl();
    antlr4::tree::TerminalNode *Minus();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnOpContext* unOp();

  class  BinOpContext : public antlr4::ParserRuleContext {
  public:
    BinOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Or();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Equals();
    antlr4::tree::TerminalNode *NEquals();
    antlr4::tree::TerminalNode *GTEquals();
    antlr4::tree::TerminalNode *LTEquals();
    antlr4::tree::TerminalNode *Gt();
    antlr4::tree::TerminalNode *Lt();
    antlr4::tree::TerminalNode *Add();
    antlr4::tree::TerminalNode *Minus();
    antlr4::tree::TerminalNode *Multiply();
    antlr4::tree::TerminalNode *Divide();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinOpContext* binOp();

  class  Bool_litContext : public antlr4::ParserRuleContext {
  public:
    Bool_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_litContext* bool_lit();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

