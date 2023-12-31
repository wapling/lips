#pragma once

#include "Token.h"
#include "ExprNode.h"

#include <iostream>

class VectorNode : public ExprNode
{
  ExprNodePtrs elements_;

public:

  VectorNode(Token const& token, ExprNodePtrs const& elements) :
    ExprNode(token),
    elements_(elements)
  {}

  void print() const override
  {
    std::cout << '[';
    bool first_time = true;
    for (auto const& element : elements_)
    {
      if (first_time)
        first_time = false;
      else
        std::cout << ' ';
      element->print();
    }
    std::cout << ']';
  }
};

