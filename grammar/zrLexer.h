
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zrLexer : public antlr4::Lexer {
public:
  enum {
    Integer = 1, Def = 2, If = 3, Else = 4, Return = 5, While = 6, To = 7, 
    Do = 8, End = 9, Or = 10, And = 11, Equals = 12, NEquals = 13, GTEquals = 14, 
    LTEquals = 15, Pow = 16, Excl = 17, GT = 18, LT = 19, Add = 20, Subtract = 21, 
    Multiply = 22, Divide = 23, Modulus = 24, OBrace = 25, CBrace = 26, 
    OBracket = 27, CBracket = 28, OParen = 29, CParen = 30, SColon = 31, 
    Assign = 32, Comma = 33, QMark = 34, Colon = 35, Type_identifier = 36, 
    Identifier = 37, String = 38, Comment = 39, Space = 40
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

