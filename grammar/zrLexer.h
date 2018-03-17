
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zrLexer : public antlr4::Lexer {
public:
  enum {
    Integer = 1, Def = 2, If = 3, Else = 4, Return = 5, While = 6, To = 7, 
    Do = 8, End = 9, Print = 10, Scan = 11, Or = 12, And = 13, Equals = 14, 
    NEquals = 15, GTEquals = 16, LTEquals = 17, Pow = 18, Excl = 19, GT = 20, 
    LT = 21, Add = 22, Subtract = 23, Multiply = 24, Divide = 25, Modulus = 26, 
    OBrace = 27, CBrace = 28, OBracket = 29, CBracket = 30, OParen = 31, 
    CParen = 32, SColon = 33, Assign = 34, Comma = 35, QMark = 36, Colon = 37, 
    Type_identifier = 38, Identifier = 39, String = 40, Comment = 41, Space = 42
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

