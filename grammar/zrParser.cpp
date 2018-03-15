
// Generated from zr.g4 by ANTLR 4.7.1


#include "zrListener.h"
#include "zrVisitor.h"

#include "zrParser.h"


using namespace antlrcpp;
using namespace antlr4;

zrParser::zrParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

zrParser::~zrParser() {
  delete _interpreter;
}

std::string zrParser::getGrammarFileName() const {
  return "zr.g4";
}

const std::vector<std::string>& zrParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& zrParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ParseContext ------------------------------------------------------------------

zrParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zrParser::Top_blockContext* zrParser::ParseContext::top_block() {
  return getRuleContext<zrParser::Top_blockContext>(0);
}

tree::TerminalNode* zrParser::ParseContext::EOF() {
  return getToken(zrParser::EOF, 0);
}


size_t zrParser::ParseContext::getRuleIndex() const {
  return zrParser::RuleParse;
}

void zrParser::ParseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParse(this);
}

void zrParser::ParseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParse(this);
}


antlrcpp::Any zrParser::ParseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitParse(this);
  else
    return visitor->visitChildren(this);
}

zrParser::ParseContext* zrParser::parse() {
  ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
  enterRule(_localctx, 0, zrParser::RuleParse);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    top_block();
    setState(43);
    match(zrParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Top_blockContext ------------------------------------------------------------------

zrParser::Top_blockContext::Top_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zrParser::Function_declContext *> zrParser::Top_blockContext::function_decl() {
  return getRuleContexts<zrParser::Function_declContext>();
}

zrParser::Function_declContext* zrParser::Top_blockContext::function_decl(size_t i) {
  return getRuleContext<zrParser::Function_declContext>(i);
}

std::vector<zrParser::Global_statementContext *> zrParser::Top_blockContext::global_statement() {
  return getRuleContexts<zrParser::Global_statementContext>();
}

zrParser::Global_statementContext* zrParser::Top_blockContext::global_statement(size_t i) {
  return getRuleContext<zrParser::Global_statementContext>(i);
}


size_t zrParser::Top_blockContext::getRuleIndex() const {
  return zrParser::RuleTop_block;
}

void zrParser::Top_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTop_block(this);
}

void zrParser::Top_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTop_block(this);
}


antlrcpp::Any zrParser::Top_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitTop_block(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Top_blockContext* zrParser::top_block() {
  Top_blockContext *_localctx = _tracker.createInstance<Top_blockContext>(_ctx, getState());
  enterRule(_localctx, 2, zrParser::RuleTop_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zrParser::Def

    || _la == zrParser::Type_identifier) {
      setState(47);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case zrParser::Def: {
          setState(45);
          function_decl();
          break;
        }

        case zrParser::Type_identifier: {
          setState(46);
          global_statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

zrParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zrParser::StatementContext *> zrParser::BlockContext::statement() {
  return getRuleContexts<zrParser::StatementContext>();
}

zrParser::StatementContext* zrParser::BlockContext::statement(size_t i) {
  return getRuleContext<zrParser::StatementContext>(i);
}


size_t zrParser::BlockContext::getRuleIndex() const {
  return zrParser::RuleBlock;
}

void zrParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void zrParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any zrParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

zrParser::BlockContext* zrParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, zrParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zrParser::If)
      | (1ULL << zrParser::Return)
      | (1ULL << zrParser::While)
      | (1ULL << zrParser::Type_identifier)
      | (1ULL << zrParser::Identifier))) != 0)) {
      setState(52);
      statement();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_statementContext ------------------------------------------------------------------

zrParser::Global_statementContext::Global_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zrParser::Global_variable_defContext* zrParser::Global_statementContext::global_variable_def() {
  return getRuleContext<zrParser::Global_variable_defContext>(0);
}


size_t zrParser::Global_statementContext::getRuleIndex() const {
  return zrParser::RuleGlobal_statement;
}

void zrParser::Global_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal_statement(this);
}

void zrParser::Global_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal_statement(this);
}


antlrcpp::Any zrParser::Global_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitGlobal_statement(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Global_statementContext* zrParser::global_statement() {
  Global_statementContext *_localctx = _tracker.createInstance<Global_statementContext>(_ctx, getState());
  enterRule(_localctx, 6, zrParser::RuleGlobal_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    global_variable_def();
    setState(59);
    match(zrParser::SColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

zrParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zrParser::Variable_defContext* zrParser::StatementContext::variable_def() {
  return getRuleContext<zrParser::Variable_defContext>(0);
}

zrParser::AssignmentContext* zrParser::StatementContext::assignment() {
  return getRuleContext<zrParser::AssignmentContext>(0);
}

zrParser::Function_callContext* zrParser::StatementContext::function_call() {
  return getRuleContext<zrParser::Function_callContext>(0);
}

zrParser::If_statementContext* zrParser::StatementContext::if_statement() {
  return getRuleContext<zrParser::If_statementContext>(0);
}

zrParser::While_statementContext* zrParser::StatementContext::while_statement() {
  return getRuleContext<zrParser::While_statementContext>(0);
}

zrParser::Return_statementContext* zrParser::StatementContext::return_statement() {
  return getRuleContext<zrParser::Return_statementContext>(0);
}


size_t zrParser::StatementContext::getRuleIndex() const {
  return zrParser::RuleStatement;
}

void zrParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void zrParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any zrParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

zrParser::StatementContext* zrParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, zrParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61);
      variable_def();
      setState(62);
      match(zrParser::SColon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      assignment();
      setState(65);
      match(zrParser::SColon);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(67);
      function_call();
      setState(68);
      match(zrParser::SColon);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(70);
      if_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(71);
      while_statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(72);
      return_statement();
      setState(73);
      match(zrParser::SColon);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

zrParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Return_statementContext::Return() {
  return getToken(zrParser::Return, 0);
}

zrParser::ExpressionContext* zrParser::Return_statementContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
}


size_t zrParser::Return_statementContext::getRuleIndex() const {
  return zrParser::RuleReturn_statement;
}

void zrParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void zrParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}


antlrcpp::Any zrParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Return_statementContext* zrParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 10, zrParser::RuleReturn_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(zrParser::Return);
    setState(78);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

zrParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::AssignmentContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

zrParser::ExpressionContext* zrParser::AssignmentContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
}


size_t zrParser::AssignmentContext::getRuleIndex() const {
  return zrParser::RuleAssignment;
}

void zrParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void zrParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any zrParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

zrParser::AssignmentContext* zrParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 12, zrParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(zrParser::Identifier);
    setState(81);
    match(zrParser::Assign);
    setState(82);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_defContext ------------------------------------------------------------------

zrParser::Variable_defContext::Variable_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Variable_defContext::Type_identifier() {
  return getToken(zrParser::Type_identifier, 0);
}

tree::TerminalNode* zrParser::Variable_defContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

zrParser::ExpressionContext* zrParser::Variable_defContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
}


size_t zrParser::Variable_defContext::getRuleIndex() const {
  return zrParser::RuleVariable_def;
}

void zrParser::Variable_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_def(this);
}

void zrParser::Variable_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_def(this);
}


antlrcpp::Any zrParser::Variable_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitVariable_def(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Variable_defContext* zrParser::variable_def() {
  Variable_defContext *_localctx = _tracker.createInstance<Variable_defContext>(_ctx, getState());
  enterRule(_localctx, 14, zrParser::RuleVariable_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(zrParser::Type_identifier);
    setState(85);
    match(zrParser::Identifier);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Assign) {
      setState(86);
      match(zrParser::Assign);
      setState(87);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_variable_defContext ------------------------------------------------------------------

zrParser::Global_variable_defContext::Global_variable_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Global_variable_defContext::Type_identifier() {
  return getToken(zrParser::Type_identifier, 0);
}

tree::TerminalNode* zrParser::Global_variable_defContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

zrParser::NumberContext* zrParser::Global_variable_defContext::number() {
  return getRuleContext<zrParser::NumberContext>(0);
}


size_t zrParser::Global_variable_defContext::getRuleIndex() const {
  return zrParser::RuleGlobal_variable_def;
}

void zrParser::Global_variable_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal_variable_def(this);
}

void zrParser::Global_variable_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal_variable_def(this);
}


antlrcpp::Any zrParser::Global_variable_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitGlobal_variable_def(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Global_variable_defContext* zrParser::global_variable_def() {
  Global_variable_defContext *_localctx = _tracker.createInstance<Global_variable_defContext>(_ctx, getState());
  enterRule(_localctx, 16, zrParser::RuleGlobal_variable_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(zrParser::Type_identifier);
    setState(91);
    match(zrParser::Identifier);
    setState(94);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Assign) {
      setState(92);
      match(zrParser::Assign);
      setState(93);
      number();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

zrParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Function_callContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

std::vector<zrParser::ExpressionContext *> zrParser::Function_callContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::Function_callContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}


size_t zrParser::Function_callContext::getRuleIndex() const {
  return zrParser::RuleFunction_call;
}

void zrParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}

void zrParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}


antlrcpp::Any zrParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Function_callContext* zrParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 18, zrParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(zrParser::Identifier);
    setState(97);
    match(zrParser::OParen);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zrParser::Integer)
      | (1ULL << zrParser::Subtract)
      | (1ULL << zrParser::Identifier))) != 0)) {
      setState(98);
      expression(0);
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == zrParser::Comma) {
        setState(99);
        match(zrParser::Comma);
        setState(100);
        expression(0);
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(108);
    match(zrParser::CParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

zrParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zrParser::If_statContext* zrParser::If_statementContext::if_stat() {
  return getRuleContext<zrParser::If_statContext>(0);
}

tree::TerminalNode* zrParser::If_statementContext::End() {
  return getToken(zrParser::End, 0);
}

std::vector<zrParser::Else_if_statContext *> zrParser::If_statementContext::else_if_stat() {
  return getRuleContexts<zrParser::Else_if_statContext>();
}

zrParser::Else_if_statContext* zrParser::If_statementContext::else_if_stat(size_t i) {
  return getRuleContext<zrParser::Else_if_statContext>(i);
}

zrParser::Else_statContext* zrParser::If_statementContext::else_stat() {
  return getRuleContext<zrParser::Else_statContext>(0);
}


size_t zrParser::If_statementContext::getRuleIndex() const {
  return zrParser::RuleIf_statement;
}

void zrParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void zrParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any zrParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

zrParser::If_statementContext* zrParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 20, zrParser::RuleIf_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(110);
    if_stat();
    setState(114);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(111);
        else_if_stat(); 
      }
      setState(116);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Else) {
      setState(117);
      else_stat();
    }
    setState(120);
    match(zrParser::End);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statContext ------------------------------------------------------------------

zrParser::If_statContext::If_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::If_statContext::If() {
  return getToken(zrParser::If, 0);
}

zrParser::Cond_expressionContext* zrParser::If_statContext::cond_expression() {
  return getRuleContext<zrParser::Cond_expressionContext>(0);
}

tree::TerminalNode* zrParser::If_statContext::Do() {
  return getToken(zrParser::Do, 0);
}

zrParser::BlockContext* zrParser::If_statContext::block() {
  return getRuleContext<zrParser::BlockContext>(0);
}


size_t zrParser::If_statContext::getRuleIndex() const {
  return zrParser::RuleIf_stat;
}

void zrParser::If_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_stat(this);
}

void zrParser::If_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_stat(this);
}


antlrcpp::Any zrParser::If_statContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitIf_stat(this);
  else
    return visitor->visitChildren(this);
}

zrParser::If_statContext* zrParser::if_stat() {
  If_statContext *_localctx = _tracker.createInstance<If_statContext>(_ctx, getState());
  enterRule(_localctx, 22, zrParser::RuleIf_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(zrParser::If);
    setState(123);
    cond_expression();
    setState(124);
    match(zrParser::Do);
    setState(125);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_if_statContext ------------------------------------------------------------------

zrParser::Else_if_statContext::Else_if_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Else_if_statContext::Else() {
  return getToken(zrParser::Else, 0);
}

tree::TerminalNode* zrParser::Else_if_statContext::If() {
  return getToken(zrParser::If, 0);
}

zrParser::Cond_expressionContext* zrParser::Else_if_statContext::cond_expression() {
  return getRuleContext<zrParser::Cond_expressionContext>(0);
}

tree::TerminalNode* zrParser::Else_if_statContext::Do() {
  return getToken(zrParser::Do, 0);
}

zrParser::BlockContext* zrParser::Else_if_statContext::block() {
  return getRuleContext<zrParser::BlockContext>(0);
}


size_t zrParser::Else_if_statContext::getRuleIndex() const {
  return zrParser::RuleElse_if_stat;
}

void zrParser::Else_if_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_if_stat(this);
}

void zrParser::Else_if_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_if_stat(this);
}


antlrcpp::Any zrParser::Else_if_statContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitElse_if_stat(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Else_if_statContext* zrParser::else_if_stat() {
  Else_if_statContext *_localctx = _tracker.createInstance<Else_if_statContext>(_ctx, getState());
  enterRule(_localctx, 24, zrParser::RuleElse_if_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(zrParser::Else);
    setState(128);
    match(zrParser::If);
    setState(129);
    cond_expression();
    setState(130);
    match(zrParser::Do);
    setState(131);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_statContext ------------------------------------------------------------------

zrParser::Else_statContext::Else_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Else_statContext::Else() {
  return getToken(zrParser::Else, 0);
}

tree::TerminalNode* zrParser::Else_statContext::Do() {
  return getToken(zrParser::Do, 0);
}

zrParser::BlockContext* zrParser::Else_statContext::block() {
  return getRuleContext<zrParser::BlockContext>(0);
}


size_t zrParser::Else_statContext::getRuleIndex() const {
  return zrParser::RuleElse_stat;
}

void zrParser::Else_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_stat(this);
}

void zrParser::Else_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_stat(this);
}


antlrcpp::Any zrParser::Else_statContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitElse_stat(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Else_statContext* zrParser::else_stat() {
  Else_statContext *_localctx = _tracker.createInstance<Else_statContext>(_ctx, getState());
  enterRule(_localctx, 26, zrParser::RuleElse_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(zrParser::Else);
    setState(134);
    match(zrParser::Do);
    setState(135);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statementContext ------------------------------------------------------------------

zrParser::While_statementContext::While_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::While_statementContext::While() {
  return getToken(zrParser::While, 0);
}

zrParser::Cond_expressionContext* zrParser::While_statementContext::cond_expression() {
  return getRuleContext<zrParser::Cond_expressionContext>(0);
}

tree::TerminalNode* zrParser::While_statementContext::Do() {
  return getToken(zrParser::Do, 0);
}

zrParser::BlockContext* zrParser::While_statementContext::block() {
  return getRuleContext<zrParser::BlockContext>(0);
}

tree::TerminalNode* zrParser::While_statementContext::End() {
  return getToken(zrParser::End, 0);
}


size_t zrParser::While_statementContext::getRuleIndex() const {
  return zrParser::RuleWhile_statement;
}

void zrParser::While_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_statement(this);
}

void zrParser::While_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_statement(this);
}


antlrcpp::Any zrParser::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}

zrParser::While_statementContext* zrParser::while_statement() {
  While_statementContext *_localctx = _tracker.createInstance<While_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, zrParser::RuleWhile_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(zrParser::While);
    setState(138);
    cond_expression();
    setState(139);
    match(zrParser::Do);
    setState(140);
    block();
    setState(141);
    match(zrParser::End);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_declContext ------------------------------------------------------------------

zrParser::Function_declContext::Function_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Function_declContext::Def() {
  return getToken(zrParser::Def, 0);
}

tree::TerminalNode* zrParser::Function_declContext::Type_identifier() {
  return getToken(zrParser::Type_identifier, 0);
}

tree::TerminalNode* zrParser::Function_declContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

zrParser::BlockContext* zrParser::Function_declContext::block() {
  return getRuleContext<zrParser::BlockContext>(0);
}

tree::TerminalNode* zrParser::Function_declContext::End() {
  return getToken(zrParser::End, 0);
}

zrParser::Func_decl_arg_listContext* zrParser::Function_declContext::func_decl_arg_list() {
  return getRuleContext<zrParser::Func_decl_arg_listContext>(0);
}


size_t zrParser::Function_declContext::getRuleIndex() const {
  return zrParser::RuleFunction_decl;
}

void zrParser::Function_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_decl(this);
}

void zrParser::Function_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_decl(this);
}


antlrcpp::Any zrParser::Function_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitFunction_decl(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Function_declContext* zrParser::function_decl() {
  Function_declContext *_localctx = _tracker.createInstance<Function_declContext>(_ctx, getState());
  enterRule(_localctx, 30, zrParser::RuleFunction_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    match(zrParser::Def);
    setState(144);
    match(zrParser::Type_identifier);
    setState(145);
    match(zrParser::Identifier);
    setState(146);
    match(zrParser::OParen);
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Type_identifier) {
      setState(147);
      func_decl_arg_list();
    }
    setState(150);
    match(zrParser::CParen);
    setState(151);
    block();
    setState(152);
    match(zrParser::End);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_decl_arg_listContext ------------------------------------------------------------------

zrParser::Func_decl_arg_listContext::Func_decl_arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zrParser::Func_decl_argContext *> zrParser::Func_decl_arg_listContext::func_decl_arg() {
  return getRuleContexts<zrParser::Func_decl_argContext>();
}

zrParser::Func_decl_argContext* zrParser::Func_decl_arg_listContext::func_decl_arg(size_t i) {
  return getRuleContext<zrParser::Func_decl_argContext>(i);
}


size_t zrParser::Func_decl_arg_listContext::getRuleIndex() const {
  return zrParser::RuleFunc_decl_arg_list;
}

void zrParser::Func_decl_arg_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_decl_arg_list(this);
}

void zrParser::Func_decl_arg_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_decl_arg_list(this);
}


antlrcpp::Any zrParser::Func_decl_arg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitFunc_decl_arg_list(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Func_decl_arg_listContext* zrParser::func_decl_arg_list() {
  Func_decl_arg_listContext *_localctx = _tracker.createInstance<Func_decl_arg_listContext>(_ctx, getState());
  enterRule(_localctx, 32, zrParser::RuleFunc_decl_arg_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    func_decl_arg();
    setState(159);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zrParser::Comma) {
      setState(155);
      match(zrParser::Comma);
      setState(156);
      func_decl_arg();
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_decl_argContext ------------------------------------------------------------------

zrParser::Func_decl_argContext::Func_decl_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::Func_decl_argContext::Type_identifier() {
  return getToken(zrParser::Type_identifier, 0);
}

tree::TerminalNode* zrParser::Func_decl_argContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}


size_t zrParser::Func_decl_argContext::getRuleIndex() const {
  return zrParser::RuleFunc_decl_arg;
}

void zrParser::Func_decl_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_decl_arg(this);
}

void zrParser::Func_decl_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_decl_arg(this);
}


antlrcpp::Any zrParser::Func_decl_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitFunc_decl_arg(this);
  else
    return visitor->visitChildren(this);
}

zrParser::Func_decl_argContext* zrParser::func_decl_arg() {
  Func_decl_argContext *_localctx = _tracker.createInstance<Func_decl_argContext>(_ctx, getState());
  enterRule(_localctx, 34, zrParser::RuleFunc_decl_arg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(zrParser::Type_identifier);
    setState(163);
    match(zrParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_expressionContext ------------------------------------------------------------------

zrParser::Cond_expressionContext::Cond_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t zrParser::Cond_expressionContext::getRuleIndex() const {
  return zrParser::RuleCond_expression;
}

void zrParser::Cond_expressionContext::copyFrom(Cond_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LtExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::LtExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::LtExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::LtExpressionContext::LtExpressionContext(Cond_expressionContext *ctx) { copyFrom(ctx); }

void zrParser::LtExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtExpression(this);
}
void zrParser::LtExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtExpression(this);
}

antlrcpp::Any zrParser::LtExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitLtExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GtExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::GtExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::GtExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::GtExpressionContext::GtExpressionContext(Cond_expressionContext *ctx) { copyFrom(ctx); }

void zrParser::GtExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGtExpression(this);
}
void zrParser::GtExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGtExpression(this);
}

antlrcpp::Any zrParser::GtExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitGtExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::EqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::EqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::EqExpressionContext::EqExpressionContext(Cond_expressionContext *ctx) { copyFrom(ctx); }

void zrParser::EqExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpression(this);
}
void zrParser::EqExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpression(this);
}

antlrcpp::Any zrParser::EqExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitEqExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotEqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::NotEqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::NotEqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::NotEqExpressionContext::NotEqExpressionContext(Cond_expressionContext *ctx) { copyFrom(ctx); }

void zrParser::NotEqExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotEqExpression(this);
}
void zrParser::NotEqExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotEqExpression(this);
}

antlrcpp::Any zrParser::NotEqExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitNotEqExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GtEqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::GtEqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::GtEqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::GtEqExpressionContext::GtEqExpressionContext(Cond_expressionContext *ctx) { copyFrom(ctx); }

void zrParser::GtEqExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGtEqExpression(this);
}
void zrParser::GtEqExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGtEqExpression(this);
}

antlrcpp::Any zrParser::GtEqExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitGtEqExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LtEqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::LtEqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::LtEqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::LtEqExpressionContext::LtEqExpressionContext(Cond_expressionContext *ctx) { copyFrom(ctx); }

void zrParser::LtEqExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtEqExpression(this);
}
void zrParser::LtEqExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtEqExpression(this);
}

antlrcpp::Any zrParser::LtEqExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitLtEqExpression(this);
  else
    return visitor->visitChildren(this);
}
zrParser::Cond_expressionContext* zrParser::cond_expression() {
  Cond_expressionContext *_localctx = _tracker.createInstance<Cond_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, zrParser::RuleCond_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Cond_expressionContext *>(_tracker.createInstance<zrParser::GtEqExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(165);
      expression(0);
      setState(166);
      match(zrParser::GTEquals);
      setState(167);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Cond_expressionContext *>(_tracker.createInstance<zrParser::LtEqExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(169);
      expression(0);
      setState(170);
      match(zrParser::LTEquals);
      setState(171);
      expression(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Cond_expressionContext *>(_tracker.createInstance<zrParser::GtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(173);
      expression(0);
      setState(174);
      match(zrParser::GT);
      setState(175);
      expression(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Cond_expressionContext *>(_tracker.createInstance<zrParser::LtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(177);
      expression(0);
      setState(178);
      match(zrParser::LT);
      setState(179);
      expression(0);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<Cond_expressionContext *>(_tracker.createInstance<zrParser::EqExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(181);
      expression(0);
      setState(182);
      match(zrParser::Equals);
      setState(183);
      expression(0);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<Cond_expressionContext *>(_tracker.createInstance<zrParser::NotEqExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(185);
      expression(0);
      setState(186);
      match(zrParser::NEquals);
      setState(187);
      expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

zrParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t zrParser::ExpressionContext::getRuleIndex() const {
  return zrParser::RuleExpression;
}

void zrParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryMinusExpressionContext ------------------------------------------------------------------

zrParser::ExpressionContext* zrParser::UnaryMinusExpressionContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
}

zrParser::UnaryMinusExpressionContext::UnaryMinusExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::UnaryMinusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryMinusExpression(this);
}
void zrParser::UnaryMinusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryMinusExpression(this);
}

antlrcpp::Any zrParser::UnaryMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::AddExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::AddExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::AddExpressionContext::AddExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::AddExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpression(this);
}
void zrParser::AddExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpression(this);
}

antlrcpp::Any zrParser::AddExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitAddExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubtractExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::SubtractExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::SubtractExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::SubtractExpressionContext::SubtractExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::SubtractExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtractExpression(this);
}
void zrParser::SubtractExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtractExpression(this);
}

antlrcpp::Any zrParser::SubtractExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitSubtractExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberExpressionContext ------------------------------------------------------------------

zrParser::NumberContext* zrParser::NumberExpressionContext::number() {
  return getRuleContext<zrParser::NumberContext>(0);
}

zrParser::NumberExpressionContext::NumberExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::NumberExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberExpression(this);
}
void zrParser::NumberExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberExpression(this);
}

antlrcpp::Any zrParser::NumberExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitNumberExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* zrParser::IdentifierExpressionContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

zrParser::IdentifierExpressionContext::IdentifierExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::IdentifierExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierExpression(this);
}
void zrParser::IdentifierExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierExpression(this);
}

antlrcpp::Any zrParser::IdentifierExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallExpressionContext ------------------------------------------------------------------

tree::TerminalNode* zrParser::FunctionCallExpressionContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

std::vector<zrParser::ExpressionContext *> zrParser::FunctionCallExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::FunctionCallExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::FunctionCallExpressionContext::FunctionCallExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::FunctionCallExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallExpression(this);
}
void zrParser::FunctionCallExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallExpression(this);
}

antlrcpp::Any zrParser::FunctionCallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitFunctionCallExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplyExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::MultiplyExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::MultiplyExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::MultiplyExpressionContext::MultiplyExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::MultiplyExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplyExpression(this);
}
void zrParser::MultiplyExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplyExpression(this);
}

antlrcpp::Any zrParser::MultiplyExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitMultiplyExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivideExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::DivideExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::DivideExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::DivideExpressionContext::DivideExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::DivideExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDivideExpression(this);
}
void zrParser::DivideExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDivideExpression(this);
}

antlrcpp::Any zrParser::DivideExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitDivideExpression(this);
  else
    return visitor->visitChildren(this);
}

zrParser::ExpressionContext* zrParser::expression() {
   return expression(0);
}

zrParser::ExpressionContext* zrParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  zrParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  zrParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, zrParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryMinusExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(192);
      match(zrParser::Subtract);
      setState(193);
      expression(8);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FunctionCallExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(194);
      match(zrParser::Identifier);
      setState(195);
      match(zrParser::OParen);
      setState(204);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << zrParser::Integer)
        | (1ULL << zrParser::Subtract)
        | (1ULL << zrParser::Identifier))) != 0)) {
        setState(196);
        expression(0);
        setState(201);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zrParser::Comma) {
          setState(197);
          match(zrParser::Comma);
          setState(198);
          expression(0);
          setState(203);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(206);
      match(zrParser::CParen);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(207);
      match(zrParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(208);
      number();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(225);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(223);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(212);
          match(zrParser::Multiply);
          setState(213);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivideExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(215);
          match(zrParser::Divide);
          setState(216);
          expression(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(218);
          match(zrParser::Add);
          setState(219);
          expression(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<SubtractExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(220);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(221);
          match(zrParser::Subtract);
          setState(222);
          expression(5);
          break;
        }

        } 
      }
      setState(227);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

zrParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zrParser::NumberContext::Integer() {
  return getToken(zrParser::Integer, 0);
}


size_t zrParser::NumberContext::getRuleIndex() const {
  return zrParser::RuleNumber;
}

void zrParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void zrParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any zrParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

zrParser::NumberContext* zrParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, zrParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(zrParser::Integer);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool zrParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool zrParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> zrParser::_decisionToDFA;
atn::PredictionContextCache zrParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN zrParser::_atn;
std::vector<uint16_t> zrParser::_serializedATN;

std::vector<std::string> zrParser::_ruleNames = {
  "parse", "top_block", "block", "global_statement", "statement", "return_statement", 
  "assignment", "variable_def", "global_variable_def", "function_call", 
  "if_statement", "if_stat", "else_if_stat", "else_stat", "while_statement", 
  "function_decl", "func_decl_arg_list", "func_decl_arg", "cond_expression", 
  "expression", "number"
};

std::vector<std::string> zrParser::_literalNames = {
  "", "", "'def'", "'if'", "'else'", "'return'", "'while'", "'to'", "'do'", 
  "'end'", "'||'", "'&&'", "'=='", "'!='", "'>='", "'<='", "'^'", "'!'", 
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'{'", "'}'", "'['", 
  "']'", "'('", "')'", "';'", "'='", "','", "'?'", "':'", "'int'"
};

std::vector<std::string> zrParser::_symbolicNames = {
  "", "Integer", "Def", "If", "Else", "Return", "While", "To", "Do", "End", 
  "Or", "And", "Equals", "NEquals", "GTEquals", "LTEquals", "Pow", "Excl", 
  "GT", "LT", "Add", "Subtract", "Multiply", "Divide", "Modulus", "OBrace", 
  "CBrace", "OBracket", "CBracket", "OParen", "CParen", "SColon", "Assign", 
  "Comma", "QMark", "Colon", "Type_identifier", "Identifier", "String", 
  "Comment", "Space"
};

dfa::Vocabulary zrParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> zrParser::_tokenNames;

zrParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2a, 0xe9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x32, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x35, 0xb, 0x3, 
    0x3, 0x4, 0x7, 0x4, 0x38, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3b, 0xb, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4e, 0xa, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x5b, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x61, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x68, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 
    0x6b, 0xb, 0xb, 0x5, 0xb, 0x6d, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x73, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x76, 0xb, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0x79, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x97, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x7, 0x12, 0xa0, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xa3, 0xb, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0xc0, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xca, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xcd, 0xb, 0x15, 0x5, 0x15, 0xcf, 0xa, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xd4, 0xa, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xe2, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xe5, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x2, 0x3, 0x28, 0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2, 0x2, 0x2, 0xf1, 0x2, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x4d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x52, 0x3, 0x2, 0x2, 0x2, 0x10, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x70, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x87, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x91, 0x3, 0x2, 0x2, 0x2, 0x22, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x26, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x2d, 0x5, 0x4, 0x3, 0x2, 0x2d, 0x2e, 0x7, 0x2, 0x2, 0x3, 
    0x2e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 0x5, 0x20, 0x11, 0x2, 0x30, 
    0x32, 0x5, 0x8, 0x5, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0xa, 0x6, 
    0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 
    0x5, 0x12, 0xa, 0x2, 0x3d, 0x3e, 0x7, 0x21, 0x2, 0x2, 0x3e, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x10, 0x9, 0x2, 0x40, 0x41, 0x7, 0x21, 
    0x2, 0x2, 0x41, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0xe, 0x8, 
    0x2, 0x43, 0x44, 0x7, 0x21, 0x2, 0x2, 0x44, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x46, 0x5, 0x14, 0xb, 0x2, 0x46, 0x47, 0x7, 0x21, 0x2, 0x2, 0x47, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4e, 0x5, 0x16, 0xc, 0x2, 0x49, 0x4e, 
    0x5, 0x1e, 0x10, 0x2, 0x4a, 0x4b, 0x5, 0xc, 0x7, 0x2, 0x4b, 0x4c, 0x7, 
    0x21, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x7, 0x2, 0x2, 0x50, 0x51, 0x5, 0x28, 0x15, 0x2, 0x51, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x27, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x22, 0x2, 0x2, 0x54, 0x55, 0x5, 0x28, 0x15, 0x2, 0x55, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x57, 0x7, 0x26, 0x2, 0x2, 0x57, 0x5a, 0x7, 0x27, 0x2, 
    0x2, 0x58, 0x59, 0x7, 0x22, 0x2, 0x2, 0x59, 0x5b, 0x5, 0x28, 0x15, 0x2, 
    0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x26, 0x2, 0x2, 0x5d, 0x60, 
    0x7, 0x27, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x22, 0x2, 0x2, 0x5f, 0x61, 0x5, 
    0x2a, 0x16, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x13, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x27, 0x2, 
    0x2, 0x63, 0x6c, 0x7, 0x1f, 0x2, 0x2, 0x64, 0x69, 0x5, 0x28, 0x15, 0x2, 
    0x65, 0x66, 0x7, 0x23, 0x2, 0x2, 0x66, 0x68, 0x5, 0x28, 0x15, 0x2, 0x67, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x7, 0x20, 0x2, 0x2, 0x6f, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x74, 0x5, 0x18, 0xd, 0x2, 0x71, 0x73, 0x5, 0x1a, 0xe, 0x2, 0x72, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x5, 0x1c, 
    0xf, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0xb, 0x2, 0x2, 
    0x7b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x5, 0x2, 0x2, 0x7d, 
    0x7e, 0x5, 0x26, 0x14, 0x2, 0x7e, 0x7f, 0x7, 0xa, 0x2, 0x2, 0x7f, 0x80, 
    0x5, 0x6, 0x4, 0x2, 0x80, 0x19, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 
    0x6, 0x2, 0x2, 0x82, 0x83, 0x7, 0x5, 0x2, 0x2, 0x83, 0x84, 0x5, 0x26, 
    0x14, 0x2, 0x84, 0x85, 0x7, 0xa, 0x2, 0x2, 0x85, 0x86, 0x5, 0x6, 0x4, 
    0x2, 0x86, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x6, 0x2, 0x2, 
    0x88, 0x89, 0x7, 0xa, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x6, 0x4, 0x2, 0x8a, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x8, 0x2, 0x2, 0x8c, 0x8d, 
    0x5, 0x26, 0x14, 0x2, 0x8d, 0x8e, 0x7, 0xa, 0x2, 0x2, 0x8e, 0x8f, 0x5, 
    0x6, 0x4, 0x2, 0x8f, 0x90, 0x7, 0xb, 0x2, 0x2, 0x90, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x92, 0x7, 0x4, 0x2, 0x2, 0x92, 0x93, 0x7, 0x26, 0x2, 
    0x2, 0x93, 0x94, 0x7, 0x27, 0x2, 0x2, 0x94, 0x96, 0x7, 0x1f, 0x2, 0x2, 
    0x95, 0x97, 0x5, 0x22, 0x12, 0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 
    0x7, 0x20, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x6, 0x4, 0x2, 0x9a, 0x9b, 0x7, 
    0xb, 0x2, 0x2, 0x9b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xa1, 0x5, 0x24, 
    0x13, 0x2, 0x9d, 0x9e, 0x7, 0x23, 0x2, 0x2, 0x9e, 0xa0, 0x5, 0x24, 0x13, 
    0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 
    0x7, 0x26, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x27, 0x2, 0x2, 0xa6, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x28, 0x15, 0x2, 0xa8, 0xa9, 0x7, 0x10, 
    0x2, 0x2, 0xa9, 0xaa, 0x5, 0x28, 0x15, 0x2, 0xaa, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xac, 0x5, 0x28, 0x15, 0x2, 0xac, 0xad, 0x7, 0x11, 0x2, 0x2, 
    0xad, 0xae, 0x5, 0x28, 0x15, 0x2, 0xae, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x5, 0x28, 0x15, 0x2, 0xb0, 0xb1, 0x7, 0x14, 0x2, 0x2, 0xb1, 0xb2, 
    0x5, 0x28, 0x15, 0x2, 0xb2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x5, 
    0x28, 0x15, 0x2, 0xb4, 0xb5, 0x7, 0x15, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x28, 
    0x15, 0x2, 0xb6, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x28, 0x15, 
    0x2, 0xb8, 0xb9, 0x7, 0xe, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x28, 0x15, 0x2, 
    0xba, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x28, 0x15, 0x2, 0xbc, 
    0xbd, 0x7, 0xf, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x28, 0x15, 0x2, 0xbe, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x8, 0x15, 0x1, 0x2, 
    0xc2, 0xc3, 0x7, 0x17, 0x2, 0x2, 0xc3, 0xd4, 0x5, 0x28, 0x15, 0xa, 0xc4, 
    0xc5, 0x7, 0x27, 0x2, 0x2, 0xc5, 0xce, 0x7, 0x1f, 0x2, 0x2, 0xc6, 0xcb, 
    0x5, 0x28, 0x15, 0x2, 0xc7, 0xc8, 0x7, 0x23, 0x2, 0x2, 0xc8, 0xca, 0x5, 
    0x28, 0x15, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd4, 0x7, 0x20, 0x2, 0x2, 0xd1, 0xd4, 
    0x7, 0x27, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x2a, 0x16, 0x2, 0xd3, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd6, 0xc, 0x9, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x18, 0x2, 0x2, 
    0xd7, 0xe2, 0x5, 0x28, 0x15, 0xa, 0xd8, 0xd9, 0xc, 0x8, 0x2, 0x2, 0xd9, 
    0xda, 0x7, 0x19, 0x2, 0x2, 0xda, 0xe2, 0x5, 0x28, 0x15, 0x9, 0xdb, 0xdc, 
    0xc, 0x7, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x16, 0x2, 0x2, 0xdd, 0xe2, 0x5, 
    0x28, 0x15, 0x8, 0xde, 0xdf, 0xc, 0x6, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x17, 
    0x2, 0x2, 0xe0, 0xe2, 0x5, 0x28, 0x15, 0x7, 0xe1, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdb, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x7, 
    0x3, 0x2, 0x2, 0xe7, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x31, 0x33, 0x39, 
    0x4d, 0x5a, 0x60, 0x69, 0x6c, 0x74, 0x78, 0x96, 0xa1, 0xbf, 0xcb, 0xce, 
    0xd3, 0xe1, 0xe3, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

zrParser::Initializer zrParser::_init;
