#pragma once

#include "Token.h"
#include "StatNode.h"
#include "VecMathNode.h"
#include "VecMathVisitor.h"

class StatListNode : public VecMathNode
{
  StatNodePtrs elements_;

public:
  
  StatListNode(StatNodePtrs elements) :
    VecMathNode(Token::STAT_LIST),
    elements_(elements)
  {}

  StatNodePtrs const& get_elements() const
  {
    return elements_;
  }

  void visit(VecMathVisitor const& visitor) const override
  {
    visitor.visit(*this);
  }
};

