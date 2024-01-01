#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "VecMathVisitor.h"

#include <memory>

struct VarNode : ExprNode
{
  VarNode(Token const& token) :
    ExprNode(token)
  {}

  void visit(VecMathVisitor const& visitor) const override
  {
    visitor.visit(*this);
  }
};

typedef std::shared_ptr<VarNode> VarNodePtr;

