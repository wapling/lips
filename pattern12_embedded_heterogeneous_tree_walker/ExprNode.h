#pragma once

#include "Token.h"
#include "VecMathNode.h"

#include <memory>
#include <vector>

struct ExprNode : VecMathNode
{
  ExprNode(Token const& token) :
    VecMathNode(token)
  {}
};

typedef std::shared_ptr<ExprNode> ExprNodePtr;
typedef std::vector<ExprNodePtr> ExprNodePtrs;

