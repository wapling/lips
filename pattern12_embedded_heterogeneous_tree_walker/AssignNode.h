#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "StatNode.h"
#include "VarNode.h"

#include <iostream>

class AssignNode : public StatNode
{
  VarNodePtr id_;
  ExprNodePtr value_;

public:
  AssignNode(VarNodePtr const& id, Token const& token, ExprNodePtr const& value) :
    StatNode(token),
    id_(id),
    value_(value)
  {}

  void print() const override
  {
    id_->print();
    std::cout << " = ";
    value_->print();
    std::cout << '\n';
  }
};

