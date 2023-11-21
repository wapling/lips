#pragma once

#include <string>

class Token
{
  int         type_;
  std::string text_;

public:
  Token(int type, std::string const& text) :
    type_(type), text_(text)
  {}
  int get_type() const { return type_; }
  std::string const& get_text() const { return text_; } 
};

