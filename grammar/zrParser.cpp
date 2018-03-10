
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
    setState(34);
    top_block();
    setState(35);
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
    setState(41);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zrParser::Def)
      | (1ULL << zrParser::Type_identifier)
      | (1ULL << zrParser::Identifier))) != 0)) {
      setState(39);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case zrParser::Def: {
          setState(37);
          function_decl();
          break;
        }

        case zrParser::Type_identifier:
        case zrParser::Identifier: {
          setState(38);
          global_statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(43);
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
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zrParser::If)
      | (1ULL << zrParser::Return)
      | (1ULL << zrParser::While)
      | (1ULL << zrParser::Type_identifier)
      | (1ULL << zrParser::Identifier))) != 0)) {
      setState(44);
      statement();
      setState(49);
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

zrParser::Variable_defContext* zrParser::Global_statementContext::variable_def() {
  return getRuleContext<zrParser::Variable_defContext>(0);
}

zrParser::AssignmentContext* zrParser::Global_statementContext::assignment() {
  return getRuleContext<zrParser::AssignmentContext>(0);
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
    setState(56);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zrParser::Type_identifier: {
        enterOuterAlt(_localctx, 1);
        setState(50);
        variable_def();
        setState(51);
        match(zrParser::SColon);
        break;
      }

      case zrParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        assignment();
        setState(54);
        match(zrParser::SColon);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
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
    setState(72);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(58);
      variable_def();
      setState(59);
      match(zrParser::SColon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(61);
      assignment();
      setState(62);
      match(zrParser::SColon);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(64);
      function_call();
      setState(65);
      match(zrParser::SColon);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(67);
      if_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(68);
      while_statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(69);
      return_statement();
      setState(70);
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
    setState(74);
    match(zrParser::Return);
    setState(75);
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
    setState(77);
    match(zrParser::Identifier);
    setState(78);
    match(zrParser::Assign);
    setState(79);
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
    setState(81);
    match(zrParser::Type_identifier);
    setState(82);
    match(zrParser::Identifier);
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Assign) {
      setState(83);
      match(zrParser::Assign);
      setState(84);
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
  enterRule(_localctx, 16, zrParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(zrParser::Identifier);
    setState(88);
    match(zrParser::OParen);
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << zrParser::Excl)
      | (1ULL << zrParser::Subtract)
      | (1ULL << zrParser::Bool)
      | (1ULL << zrParser::Number)
      | (1ULL << zrParser::Identifier)
      | (1ULL << zrParser::String))) != 0)) {
      setState(89);
      expression(0);
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == zrParser::Comma) {
        setState(90);
        match(zrParser::Comma);
        setState(91);
        expression(0);
        setState(96);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(99);
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
  enterRule(_localctx, 18, zrParser::RuleIf_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(101);
    if_stat();
    setState(105);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(102);
        else_if_stat(); 
      }
      setState(107);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Else) {
      setState(108);
      else_stat();
    }
    setState(111);
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

zrParser::ExpressionContext* zrParser::If_statContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
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
  enterRule(_localctx, 20, zrParser::RuleIf_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(zrParser::If);
    setState(114);
    expression(0);
    setState(115);
    match(zrParser::Do);
    setState(116);
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

zrParser::ExpressionContext* zrParser::Else_if_statContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
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
  enterRule(_localctx, 22, zrParser::RuleElse_if_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(zrParser::Else);
    setState(119);
    match(zrParser::If);
    setState(120);
    expression(0);
    setState(121);
    match(zrParser::Do);
    setState(122);
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
  enterRule(_localctx, 24, zrParser::RuleElse_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(zrParser::Else);
    setState(125);
    match(zrParser::Do);
    setState(126);
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

zrParser::ExpressionContext* zrParser::While_statementContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
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
  enterRule(_localctx, 26, zrParser::RuleWhile_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(zrParser::While);
    setState(129);
    expression(0);
    setState(130);
    match(zrParser::Do);
    setState(131);
    block();
    setState(132);
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
  enterRule(_localctx, 28, zrParser::RuleFunction_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(zrParser::Def);
    setState(135);
    match(zrParser::Type_identifier);
    setState(136);
    match(zrParser::Identifier);
    setState(137);
    match(zrParser::OParen);
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zrParser::Type_identifier) {
      setState(138);
      func_decl_arg_list();
    }
    setState(141);
    match(zrParser::CParen);
    setState(142);
    block();
    setState(143);
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

tree::TerminalNode* zrParser::Func_decl_arg_listContext::Type_identifier() {
  return getToken(zrParser::Type_identifier, 0);
}

tree::TerminalNode* zrParser::Func_decl_arg_listContext::Identifier() {
  return getToken(zrParser::Identifier, 0);
}

std::vector<zrParser::Func_decl_arg_listContext *> zrParser::Func_decl_arg_listContext::func_decl_arg_list() {
  return getRuleContexts<zrParser::Func_decl_arg_listContext>();
}

zrParser::Func_decl_arg_listContext* zrParser::Func_decl_arg_listContext::func_decl_arg_list(size_t i) {
  return getRuleContext<zrParser::Func_decl_arg_listContext>(i);
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
  enterRule(_localctx, 30, zrParser::RuleFunc_decl_arg_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(zrParser::Type_identifier);
    setState(146);
    match(zrParser::Identifier);
    setState(151);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(147);
        match(zrParser::Comma);
        setState(148);
        func_decl_arg_list(); 
      }
      setState(153);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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

//----------------- LtExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::LtExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::LtExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::LtExpressionContext::LtExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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

zrParser::GtExpressionContext::GtExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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
//----------------- BoolExpressionContext ------------------------------------------------------------------

tree::TerminalNode* zrParser::BoolExpressionContext::Bool() {
  return getToken(zrParser::Bool, 0);
}

zrParser::BoolExpressionContext::BoolExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::BoolExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolExpression(this);
}
void zrParser::BoolExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolExpression(this);
}

antlrcpp::Any zrParser::BoolExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitBoolExpression(this);
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

zrParser::NotEqExpressionContext::NotEqExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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
//----------------- NumberExpressionContext ------------------------------------------------------------------

tree::TerminalNode* zrParser::NumberExpressionContext::Number() {
  return getToken(zrParser::Number, 0);
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
//----------------- ModulusExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::ModulusExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::ModulusExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::ModulusExpressionContext::ModulusExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::ModulusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModulusExpression(this);
}
void zrParser::ModulusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModulusExpression(this);
}

antlrcpp::Any zrParser::ModulusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitModulusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExpressionContext ------------------------------------------------------------------

zrParser::ExpressionContext* zrParser::NotExpressionContext::expression() {
  return getRuleContext<zrParser::ExpressionContext>(0);
}

zrParser::NotExpressionContext::NotExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::NotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpression(this);
}
void zrParser::NotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpression(this);
}

antlrcpp::Any zrParser::NotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitNotExpression(this);
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
//----------------- GtEqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::GtEqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::GtEqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::GtEqExpressionContext::GtEqExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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
//----------------- OrExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::OrExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::OrExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::OrExpressionContext::OrExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::OrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpression(this);
}
void zrParser::OrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpression(this);
}

antlrcpp::Any zrParser::OrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitOrExpression(this);
  else
    return visitor->visitChildren(this);
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
//----------------- EqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::EqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::EqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::EqExpressionContext::EqExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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
//----------------- AndExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::AndExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::AndExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::AndExpressionContext::AndExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::AndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpression(this);
}
void zrParser::AndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpression(this);
}

antlrcpp::Any zrParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExpressionContext ------------------------------------------------------------------

tree::TerminalNode* zrParser::StringExpressionContext::String() {
  return getToken(zrParser::String, 0);
}

zrParser::StringExpressionContext::StringExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void zrParser::StringExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringExpression(this);
}
void zrParser::StringExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringExpression(this);
}

antlrcpp::Any zrParser::StringExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zrVisitor*>(visitor))
    return parserVisitor->visitStringExpression(this);
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
//----------------- LtEqExpressionContext ------------------------------------------------------------------

std::vector<zrParser::ExpressionContext *> zrParser::LtEqExpressionContext::expression() {
  return getRuleContexts<zrParser::ExpressionContext>();
}

zrParser::ExpressionContext* zrParser::LtEqExpressionContext::expression(size_t i) {
  return getRuleContext<zrParser::ExpressionContext>(i);
}

zrParser::LtEqExpressionContext::LtEqExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

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

zrParser::ExpressionContext* zrParser::expression() {
   return expression(0);
}

zrParser::ExpressionContext* zrParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  zrParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  zrParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, zrParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(176);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryMinusExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(155);
      match(zrParser::Subtract);
      setState(156);
      expression(20);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NotExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(157);
      match(zrParser::Excl);
      setState(158);
      expression(19);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NumberExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(159);
      match(zrParser::Number);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<BoolExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(160);
      match(zrParser::Bool);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<FunctionCallExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      match(zrParser::Identifier);
      setState(162);
      match(zrParser::OParen);
      setState(171);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << zrParser::Excl)
        | (1ULL << zrParser::Subtract)
        | (1ULL << zrParser::Bool)
        | (1ULL << zrParser::Number)
        | (1ULL << zrParser::Identifier)
        | (1ULL << zrParser::String))) != 0)) {
        setState(163);
        expression(0);
        setState(168);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zrParser::Comma) {
          setState(164);
          match(zrParser::Comma);
          setState(165);
          expression(0);
          setState(170);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(173);
      match(zrParser::CParen);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(174);
      match(zrParser::Identifier);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(175);
      match(zrParser::String);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(219);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(217);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(178);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(179);
          match(zrParser::Multiply);
          setState(180);
          expression(19);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivideExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(181);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(182);
          match(zrParser::Divide);
          setState(183);
          expression(18);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ModulusExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(184);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(185);
          match(zrParser::Modulus);
          setState(186);
          expression(17);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AddExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(187);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(188);
          match(zrParser::Add);
          setState(189);
          expression(16);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<SubtractExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(190);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(191);
          match(zrParser::Subtract);
          setState(192);
          expression(15);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<GtEqExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(193);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(194);
          match(zrParser::GTEquals);
          setState(195);
          expression(14);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<LtEqExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(196);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(197);
          match(zrParser::LTEquals);
          setState(198);
          expression(13);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<GtExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(199);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(200);
          match(zrParser::GT);
          setState(201);
          expression(12);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LtExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(202);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(203);
          match(zrParser::LT);
          setState(204);
          expression(11);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<EqExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(205);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(206);
          match(zrParser::Equals);
          setState(207);
          expression(10);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<NotEqExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(208);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(209);
          match(zrParser::NEquals);
          setState(210);
          expression(9);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AndExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(212);
          match(zrParser::And);
          setState(213);
          expression(8);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OrExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(215);
          match(zrParser::Or);
          setState(216);
          expression(7);
          break;
        }

        } 
      }
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
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
    case 16: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool zrParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 18);
    case 1: return precpred(_ctx, 17);
    case 2: return precpred(_ctx, 16);
    case 3: return precpred(_ctx, 15);
    case 4: return precpred(_ctx, 14);
    case 5: return precpred(_ctx, 13);
    case 6: return precpred(_ctx, 12);
    case 7: return precpred(_ctx, 11);
    case 8: return precpred(_ctx, 10);
    case 9: return precpred(_ctx, 9);
    case 10: return precpred(_ctx, 8);
    case 11: return precpred(_ctx, 7);
    case 12: return precpred(_ctx, 6);

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
  "assignment", "variable_def", "function_call", "if_statement", "if_stat", 
  "else_if_stat", "else_stat", "while_statement", "function_decl", "func_decl_arg_list", 
  "expression"
};

std::vector<std::string> zrParser::_literalNames = {
  "", "'def'", "'if'", "'else'", "'return'", "'while'", "'to'", "'do'", 
  "'end'", "'print'", "'scan'", "'println'", "'||'", "'&&'", "'=='", "'!='", 
  "'>='", "'<='", "'^'", "'!'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'{'", "'}'", "'['", "']'", "'('", "')'", "';'", "'='", "','", 
  "'?'", "':'"
};

std::vector<std::string> zrParser::_symbolicNames = {
  "", "Def", "If", "Else", "Return", "While", "To", "Do", "End", "Print", 
  "Scan", "PrintLn", "Or", "And", "Equals", "NEquals", "GTEquals", "LTEquals", 
  "Pow", "Excl", "GT", "LT", "Add", "Subtract", "Multiply", "Divide", "Modulus", 
  "OBrace", "CBrace", "OBracket", "CBracket", "OParen", "CParen", "SColon", 
  "Assign", "Comma", "QMark", "Colon", "Type_identifier", "Bool", "Number", 
  "Identifier", "String", "Comment", "Space"
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
    0x3, 0x2e, 0xe1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x2a, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2d, 0xb, 0x3, 0x3, 0x4, 0x7, 0x4, 
    0x30, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x33, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3b, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x4b, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x58, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0x5f, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x62, 0xb, 0xa, 0x5, 0xa, 0x64, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x6a, 0xa, 
    0xb, 0xc, 0xb, 0xe, 0xb, 0x6d, 0xb, 0xb, 0x3, 0xb, 0x5, 0xb, 0x70, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0x8e, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x98, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x9b, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xa9, 0xa, 0x12, 0xc, 
    0x12, 0xe, 0x12, 0xac, 0xb, 0x12, 0x5, 0x12, 0xae, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xb3, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xdc, 0xa, 
    0x12, 0xc, 0x12, 0xe, 0x12, 0xdf, 0xb, 0x12, 0x3, 0x12, 0x2, 0x3, 0x22, 
    0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x2, 0x2, 0x2, 0xf4, 0x2, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x59, 0x3, 0x2, 0x2, 0x2, 0x14, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x73, 0x3, 0x2, 0x2, 0x2, 0x18, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x88, 0x3, 0x2, 0x2, 0x2, 0x20, 0x93, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x5, 0x4, 0x3, 0x2, 0x25, 0x26, 
    0x7, 0x2, 0x2, 0x3, 0x26, 0x3, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x5, 
    0x1e, 0x10, 0x2, 0x28, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x29, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x30, 0x5, 0xa, 0x6, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x7, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x35, 0x5, 0x10, 0x9, 0x2, 0x35, 0x36, 0x7, 0x23, 0x2, 
    0x2, 0x36, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x5, 0xe, 0x8, 0x2, 
    0x38, 0x39, 0x7, 0x23, 0x2, 0x2, 0x39, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x10, 0x9, 0x2, 0x3d, 0x3e, 0x7, 
    0x23, 0x2, 0x2, 0x3e, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x5, 0xe, 
    0x8, 0x2, 0x40, 0x41, 0x7, 0x23, 0x2, 0x2, 0x41, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x43, 0x5, 0x12, 0xa, 0x2, 0x43, 0x44, 0x7, 0x23, 0x2, 0x2, 
    0x44, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x45, 0x4b, 0x5, 0x14, 0xb, 0x2, 0x46, 
    0x4b, 0x5, 0x1c, 0xf, 0x2, 0x47, 0x48, 0x5, 0xc, 0x7, 0x2, 0x48, 0x49, 
    0x7, 0x23, 0x2, 0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4b, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4d, 0x7, 0x6, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x22, 0x12, 0x2, 0x4e, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x2b, 0x2, 0x2, 0x50, 0x51, 
    0x7, 0x24, 0x2, 0x2, 0x51, 0x52, 0x5, 0x22, 0x12, 0x2, 0x52, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x28, 0x2, 0x2, 0x54, 0x57, 0x7, 0x2b, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0x24, 0x2, 0x2, 0x56, 0x58, 0x5, 0x22, 0x12, 
    0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x11, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x2b, 0x2, 0x2, 0x5a, 
    0x63, 0x7, 0x21, 0x2, 0x2, 0x5b, 0x60, 0x5, 0x22, 0x12, 0x2, 0x5c, 0x5d, 
    0x7, 0x25, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0x22, 0x12, 0x2, 0x5e, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x66, 0x7, 0x22, 0x2, 0x2, 0x66, 0x13, 0x3, 0x2, 0x2, 0x2, 0x67, 0x6b, 
    0x5, 0x16, 0xc, 0x2, 0x68, 0x6a, 0x5, 0x18, 0xd, 0x2, 0x69, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 0x5, 0x1a, 0xe, 0x2, 
    0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0xa, 0x2, 0x2, 0x72, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x4, 0x2, 0x2, 0x74, 0x75, 0x5, 
    0x22, 0x12, 0x2, 0x75, 0x76, 0x7, 0x9, 0x2, 0x2, 0x76, 0x77, 0x5, 0x6, 
    0x4, 0x2, 0x77, 0x17, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x5, 0x2, 
    0x2, 0x79, 0x7a, 0x7, 0x4, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x22, 0x12, 0x2, 
    0x7b, 0x7c, 0x7, 0x9, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x6, 0x4, 0x2, 0x7d, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x5, 0x2, 0x2, 0x7f, 0x80, 
    0x7, 0x9, 0x2, 0x2, 0x80, 0x81, 0x5, 0x6, 0x4, 0x2, 0x81, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0x7, 0x2, 0x2, 0x83, 0x84, 0x5, 0x22, 
    0x12, 0x2, 0x84, 0x85, 0x7, 0x9, 0x2, 0x2, 0x85, 0x86, 0x5, 0x6, 0x4, 
    0x2, 0x86, 0x87, 0x7, 0xa, 0x2, 0x2, 0x87, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x89, 0x7, 0x3, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x28, 0x2, 0x2, 0x8a, 
    0x8b, 0x7, 0x2b, 0x2, 0x2, 0x8b, 0x8d, 0x7, 0x21, 0x2, 0x2, 0x8c, 0x8e, 
    0x5, 0x20, 0x11, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x22, 
    0x2, 0x2, 0x90, 0x91, 0x5, 0x6, 0x4, 0x2, 0x91, 0x92, 0x7, 0xa, 0x2, 
    0x2, 0x92, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x28, 0x2, 0x2, 
    0x94, 0x99, 0x7, 0x2b, 0x2, 0x2, 0x95, 0x96, 0x7, 0x25, 0x2, 0x2, 0x96, 
    0x98, 0x5, 0x20, 0x11, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0x21, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x9d, 0x8, 0x12, 0x1, 0x2, 0x9d, 0x9e, 0x7, 0x19, 0x2, 
    0x2, 0x9e, 0xb3, 0x5, 0x22, 0x12, 0x16, 0x9f, 0xa0, 0x7, 0x15, 0x2, 
    0x2, 0xa0, 0xb3, 0x5, 0x22, 0x12, 0x15, 0xa1, 0xb3, 0x7, 0x2a, 0x2, 
    0x2, 0xa2, 0xb3, 0x7, 0x29, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x2b, 0x2, 0x2, 
    0xa4, 0xad, 0x7, 0x21, 0x2, 0x2, 0xa5, 0xaa, 0x5, 0x22, 0x12, 0x2, 0xa6, 
    0xa7, 0x7, 0x25, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x22, 0x12, 0x2, 0xa8, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xaf, 0xb3, 0x7, 0x22, 0x2, 0x2, 0xb0, 0xb3, 0x7, 0x2b, 0x2, 0x2, 0xb1, 
    0xb3, 0x7, 0x2c, 0x2, 0x2, 0xb2, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb5, 0xc, 0x14, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x1a, 0x2, 0x2, 
    0xb6, 0xdc, 0x5, 0x22, 0x12, 0x15, 0xb7, 0xb8, 0xc, 0x13, 0x2, 0x2, 
    0xb8, 0xb9, 0x7, 0x1b, 0x2, 0x2, 0xb9, 0xdc, 0x5, 0x22, 0x12, 0x14, 
    0xba, 0xbb, 0xc, 0x12, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x1c, 0x2, 0x2, 0xbc, 
    0xdc, 0x5, 0x22, 0x12, 0x13, 0xbd, 0xbe, 0xc, 0x11, 0x2, 0x2, 0xbe, 
    0xbf, 0x7, 0x18, 0x2, 0x2, 0xbf, 0xdc, 0x5, 0x22, 0x12, 0x12, 0xc0, 
    0xc1, 0xc, 0x10, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x19, 0x2, 0x2, 0xc2, 0xdc, 
    0x5, 0x22, 0x12, 0x11, 0xc3, 0xc4, 0xc, 0xf, 0x2, 0x2, 0xc4, 0xc5, 0x7, 
    0x12, 0x2, 0x2, 0xc5, 0xdc, 0x5, 0x22, 0x12, 0x10, 0xc6, 0xc7, 0xc, 
    0xe, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x13, 0x2, 0x2, 0xc8, 0xdc, 0x5, 0x22, 
    0x12, 0xf, 0xc9, 0xca, 0xc, 0xd, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x16, 0x2, 
    0x2, 0xcb, 0xdc, 0x5, 0x22, 0x12, 0xe, 0xcc, 0xcd, 0xc, 0xc, 0x2, 0x2, 
    0xcd, 0xce, 0x7, 0x17, 0x2, 0x2, 0xce, 0xdc, 0x5, 0x22, 0x12, 0xd, 0xcf, 
    0xd0, 0xc, 0xb, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x10, 0x2, 0x2, 0xd1, 0xdc, 
    0x5, 0x22, 0x12, 0xc, 0xd2, 0xd3, 0xc, 0xa, 0x2, 0x2, 0xd3, 0xd4, 0x7, 
    0x11, 0x2, 0x2, 0xd4, 0xdc, 0x5, 0x22, 0x12, 0xb, 0xd5, 0xd6, 0xc, 0x9, 
    0x2, 0x2, 0xd6, 0xd7, 0x7, 0xf, 0x2, 0x2, 0xd7, 0xdc, 0x5, 0x22, 0x12, 
    0xa, 0xd8, 0xd9, 0xc, 0x8, 0x2, 0x2, 0xd9, 0xda, 0x7, 0xe, 0x2, 0x2, 
    0xda, 0xdc, 0x5, 0x22, 0x12, 0x9, 0xdb, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xcf, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xdb, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x13, 0x29, 0x2b, 
    0x31, 0x3a, 0x4a, 0x57, 0x60, 0x63, 0x6b, 0x6f, 0x8d, 0x99, 0xaa, 0xad, 
    0xb2, 0xdb, 0xdd, 
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
