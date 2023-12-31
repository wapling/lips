#pragma once

#include "Token.h"
#include "ExprNode.h"

#include <iostream>

class AddNode : public ExprNode
{
  ExprNodePtr left_;
  ExprNodePtr right_;

public:

  AddNode(ExprNodePtr const& left, Token const& token, ExprNodePtr const right) :
    ExprNode(token),
    left_(left),
    right_(right)
  {}

  void print() const override
  {
    left_->print();
    std::cout << " + ";
    right_->print();
  }
};

