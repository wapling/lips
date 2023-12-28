#pragma once

#include "Expr.h"
#include "Token.h"

#include <vector>

struct VectorNode : ExprNode
{
  VectorNode(Token const& token, AstNodes const& elements) :
    ExprNode(token, tVECTOR)
  {
    for (auto const& element : elements)
      add_child(element);
  }
};
