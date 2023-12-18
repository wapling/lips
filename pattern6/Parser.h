#pragma once

#include "Lexer.h"
#include "Token.h"
#include "MismatchedTokenException.h"
#include "PreviousParseFailedException.h"

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

typedef std::unordered_map<int, int> RuleMemo;

const int FAILED = -1;

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
      clear_memo();
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

  virtual void clear_memo() = 0;

  bool already_parsed_rule(RuleMemo const& memoization)
  {
    auto memo = memoization.find(position_);
    if (memo == memoization.end())
      return false;

    const int previous_result = memo->second;
    std::cout << "Parsed rule before at index " 
              << position_
              << "; skip ahead to token index "
              << previous_result
              << ": "
              << lookahead_[previous_result].get_text()
              << std::endl;
    if (FAILED == previous_result)
      throw PreviousParseFailedException();

    seek(previous_result);
    return true;
  }

  void memoize(RuleMemo& memoization,
               int start_token_index,
               bool failed)
  {
    int stop_token_index = failed ? FAILED : position_;
    memoization.emplace(start_token_index, stop_token_index);
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

