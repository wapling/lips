#pragma once

#include "Lexer.h"
#include "Token.h"
#include "MismatchedTokenException.h"

#include <stack>
#include <vector>

class Parser
{
protected:

  Lexer&              input_;
  std::stack<size_t>  markers_;
  std::vector<Token>  lookahead_;
  size_t              position_;

  void fill(size_t count)
  {
    for (size_t n = 0; n < count; ++n)
      lookahead_.push_back(input_.next_token());
  }

  void sync(size_t index)
  {
    if (position_ + index > lookahead_.size())
    {
      size_t n = position_ + index - lookahead_.size();
      fill(n);
    }
  }  

  virtual void consume()
  {
    ++position_;
    if (position_ == lookahead_.size() && !is_speculating())
    {
      position_ = 0;
      lookahead_.clear();
    }
    sync(1);
  }

  Token const& LT(size_t index)
  {
    sync(index);
    return lookahead_[position_ + index - 1];
  }

  int LA(size_t index)
  {
    return LT(index).get_type();
  }

  size_t mark()
  {
    markers_.push(position_);
    return position_;
  }

  void release()
  {
    size_t marker = markers_.top();
    markers_.pop();
    seek(marker);
  }

  void seek(size_t index)
  {
    position_ = index;
  }

  bool is_speculating() const
  {
    return !markers_.empty();
  }

public:
  Parser(Lexer& input) : 
    input_(input),
    position_(0)
  {
    sync(1);
  }

  virtual ~Parser() = default;

  void match(int x)
  {
    if (LA(1) == x)
      consume();
    else
      throw MismatchedTokenException(input_.get_token_name(x), LT(1));
  }

};


