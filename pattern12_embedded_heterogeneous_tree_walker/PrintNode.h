#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "StatNode.h"

#include <iostream>

class PrintNode : public StatNode
{
  ExprNodePtr value_;

public:
  PrintNode(Token const& token, ExprNodePtr value) :
    StatNode(token),
    value_(value)
  {}

  void print() const override
  {
    std::cout << "print ";
    value_->print();
    std::cout << '\n';
  }
};

