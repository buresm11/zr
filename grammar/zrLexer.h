
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zrLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, Integer = 4, Def = 5, If = 6, Else = 7, 
    Return = 8, Break = 9, While = 10, To = 11, Do = 12, End = 13, Print = 14, 
    Scan = 15, True = 16, False = 17, Void = 18, Or = 19, And = 20, Equals = 21, 
    NEquals = 22, GTEquals = 23, LTEquals = 24, Excl = 25, Gt = 26, Lt = 27, 
    Add = 28, Minus = 29, Multiply = 30, Divide = 31, Lparen = 32, Rparen = 33, 
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

