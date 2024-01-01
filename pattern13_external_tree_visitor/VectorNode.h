#pragma once

#include "Token.h"
#include "ExprNode.h"
#include "VecMathVisitor.h"

class VectorNode : public ExprNode
{
  ExprNodePtrs elements_;

public:

  VectorNode(Token const& token, ExprNodePtrs const& elements) :
    ExprNode(token),
    elements_(elements)
  {}

  ExprNodePtrs const& get_elements() const
  {
    return elements_;
  }

  void visit(VecMathVisitor const& visitor) const override
  {
    visitor.visit(*this);
  }
};

