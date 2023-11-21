#pragma once

#include "Lexer.h"
#include "Token.h"
#include "InvalidToken.h"

class Parser
{
protected:

  Lexer&  input_;
  Token   lookahead_;

  virtual void consume()
  {
    lookahead_ = input_.next_token();
  }

public:
  Parser(Lexer& input) : 
    input_(input),
    lookahead_(input_.next_token())
  {}

  virtual ~Parser() = default;

  void match(int x)
  {
    if (lookahead_.get_type() == x)
      consume();
    else
      throw InvalidToken(input_.get_token_name(x), lookahead_);
  }

};


