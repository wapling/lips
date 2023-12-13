#pragma once

#include "Lexer.h"
#include "Token.h"
#include "InvalidToken.h"

#include <vector>

class Parser
{
protected:

  Lexer&              input_;
  size_t              depth_;
  std::vector<Token>  lookahead_;
  size_t              position_;

  virtual void consume()
  {
    lookahead_[position_] = input_.next_token();
    position_ = (position_ + 1) % depth_;
  }

  Token const& LT(size_t position) const
  {
    return lookahead_[(position_ + position - 1) % depth_];
  }

  int LA(size_t position) const
  {
    return LT(position).get_type();
  }
  
public:
  Parser(Lexer& input, size_t depth) : 
    input_(input),
    depth_(depth),
    lookahead_(depth_),
    position_(0)
  {
    for (size_t n = 0; n < depth_; ++n)
      consume();
  }

  virtual ~Parser() = default;

  void match(int x)
  {
    if (LA(1) == x)
      consume();
    else
      throw InvalidToken(input_.get_token_name(x), LT(1));
  }

};


