#pragma once

#include "HeteroAST.h"
#include "Token.h"

struct VecMathVisitor;

struct VecMathNode : HeteroAST
{
  VecMathNode() = default;
  VecMathNode(Token const& token) :
    HeteroAST(token)
  {}
  virtual ~VecMathNode() = default;

  virtual void visit(VecMathVisitor const& visitor) const = 0;
};

