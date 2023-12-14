#pragma once

#include <string>
#include <utility>

class Token
{
  int         type_;
  std::string text_;

public:
  Token() : type_(0)
  {}

  Token(int type, std::string text) :
    type_(type), text_(std::move(text))
  {}

  Token(int type, char text) :
    type_(type), text_(1, text)
  {}

  int get_type() const { return type_; }
  std::string const& get_text() const { return text_; } 
};

