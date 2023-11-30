#pragma once

#include "Token.h"

#include <stdexcept>
#include <string>
#include <utility>

struct MatchException : public std::runtime_error
{
  char expecting_;
  char found_;

  static std::string get_message(char expecting, char found)
  {
    std::string message = "Expecting ' ', Found ' '";
    message[11] = expecting;
    message[22] = found;
    return message;
  }

public:  
  MatchException(char expecting, char found) :
    std::runtime_error(get_message(expecting, found)),
    expecting_(expecting),
    found_(found)
  {}
};

class Lexer
{
  std::string input_;
  int         index_;

protected:
  char    current_;

public:
  static char const EOF_CHAR = -1;
  static int  const EOF_TYPE =  1;

  Lexer(std::string input) :
    input_(std::move(input)),
    index_(0),
    current_(input_.empty() ? EOF_CHAR : input_[0])
  {}

  virtual ~Lexer() = default;

  void consume()
  {
    index_++;
    if (index_ >= input_.length())
      current_ = EOF_CHAR;
    else
      current_ = input_[index_];
  }

  void match(char x)
  {
    if (current_ != x)
      throw MatchException(x, current_);
    consume();
  }

  virtual Token next_token() = 0;
  virtual char const* const get_token_name(int x) const = 0; 
};

