#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "StatNode.h"
#include "VecMathVisitor.h"

class PrintNode : public StatNode
{
  ExprNodePtr value_;

public:
  PrintNode(Token const& token, ExprNodePtr value) :
    StatNode(token),
    value_(value)
  {}

  ExprNodePtr const get_value() const { return value_; }

  void visit(VecMathVisitor const& visitor) const override
  {
    visitor.visit(*this);
  }
};

