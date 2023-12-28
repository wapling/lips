#pragma once

#include <string>

const int INVALID_TOKEN_TYPE = 0;
const int PLUS = 1;
const int INT = 2;

class Token
{
  int type_;
  std::string text_;

public:
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

