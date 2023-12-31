#pragma once

#include <string>

class Token
{
  int type_;
  std::string text_;

public:
  static const int INVALID_TOKEN_TYPE = 0;
  static const int PLUS = 1;
  static const int MULT = 2;
  static const int DOT = 3;
  static const int INT = 4;
  static const int VEC = 5;
  static const int ID = 6;
  static const int ASSIGN = 7;
  static const int PRINT = 8;
  static const int STAT_LIST = 9;

  Token(int type, std::string const& text) :
    type_(type),
    text_(text)
  {}

  Token(int type) :
    type_(type)
  {}

  Token() :
    type_(INVALID_TOKEN_TYPE)
  {}

  int get_type() const { return type_; }
  std::string const& get_text() const { return text_; }
    
};

