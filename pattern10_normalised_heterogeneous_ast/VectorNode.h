#pragma once

#include "ExprNode.h"
#include "Token.h"

#include <vector>

struct VectorNode : ExprNode
{
  VectorNode(Token const& token, AstPtrs const& elements) :
    ExprNode(token, tVECTOR)
  {
    for (auto const& element : elements)
      add_child(element);
  }
};
