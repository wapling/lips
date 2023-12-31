#pragma once

#include "Token.h"
#include "StatNode.h"
#include "VecMathNode.h"

class StatListNode : public VecMathNode
{
  StatNodePtrs elements_;

public:
  
  StatListNode(StatNodePtrs elements) :
    VecMathNode(Token::STAT_LIST),
    elements_(elements)
  {}

  void print() const override
  {
    for (auto const& element : elements_)
      element->print();
  }
  
};

