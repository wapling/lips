#pragma once

#include "Token.h"
#include "ExprNode.h"

#include <iostream>

class MultNode : public ExprNode
{
  ExprNodePtr left_;
  ExprNodePtr right_;

public:

  MultNode(ExprNodePtr const& left, Token const& token, ExprNodePtr const right) :
    ExprNode(token),
    left_(left),
    right_(right)
  {}

  void print() const override
  {
    left_->print();
    std::cout << " * ";
    right_->print();
  }
};

