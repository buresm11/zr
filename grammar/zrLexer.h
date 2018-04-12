
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zrLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, Integer = 6, Def = 7, 
    If = 8, Else = 9, Return = 10, Break = 11, While = 12, To = 13, Do = 14, 
    End = 15, Print = 16, Scan = 17, True = 18, False = 19, Void = 20, Or = 21, 
    And = 22, Equals = 23, NEquals = 24, GTEquals = 25, LTEquals = 26, Excl = 27, 
    Gt = 28, Lt = 29, Add = 30, Minus = 31, Multiply = 32, Divide = 33, 
    Type_identifier = 34, Identifier = 35, String = 36, Comment = 37, Space = 38
  };

  zrLexer(antlr4::CharStream *input);
  ~zrLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

