#pragma once

#include "HeteroAST.h"
#include "Token.h"

struct VecMathNode : HeteroAST
{
  VecMathNode() = default;
  VecMathNode(Token const& token) :
    HeteroAST(token)
  {}
  virtual ~VecMathNode() = default;

  virtual void print() const;
};

