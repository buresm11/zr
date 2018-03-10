
// Generated from zr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zrLexer : public antlr4::Lexer {
public:
  enum {
    Def = 1, If = 2, Else = 3, Return = 4, While = 5, To = 6, Do = 7, End = 8, 
    Print = 9, Scan = 10, PrintLn = 11, Or = 12, And = 13, Equals = 14, 
    NEquals = 15, GTEquals = 16, LTEquals = 17, Pow = 18, Excl = 19, GT = 20, 
    LT = 21, Add = 22, Subtract = 23, Multiply = 24, Divide = 25, Modulus = 26, 
    OBrace = 27, CBrace = 28, OBracket = 29, CBracket = 30, OParen = 31, 
    CParen = 32, SColon = 33, Assign = 34, Comma = 35, QMark = 36, Colon = 37, 
    Type_identifier = 38, Bool = 39, Number = 40, Identifier = 41, String = 42, 
    Comment = 43, Space = 44
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

