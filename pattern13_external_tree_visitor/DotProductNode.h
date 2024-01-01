#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "VecMathVisitor.h"

class DotProductNode : public ExprNode
{
  ExprNodePtr left_;
  ExprNodePtr right_;

public:

  DotProductNode(ExprNodePtr const& left,
                 Token const& token,
                 ExprNodePtr const right) :
    ExprNode(token),
    left_(left),
    right_(right)
  {}

  ExprNodePtr const get_left() const { return left_; }
  ExprNodePtr const get_right() const { return right_; }

  void visit(VecMathVisitor const& visitor) const override
  {
    visitor.visit(*this);
  }
};

