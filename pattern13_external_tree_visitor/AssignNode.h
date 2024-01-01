#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "StatNode.h"
#include "VarNode.h"
#include "VecMathVisitor.h"

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

  ExprNodePtr const get_id() const { return id_; }
  ExprNodePtr const get_value() const { return value_; }

  void visit(VecMathVisitor const& visitor) const override
  {
    visitor.visit(*this);
  }
};

