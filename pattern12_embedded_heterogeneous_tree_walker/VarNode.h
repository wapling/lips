#pragma once

#include "Token.h"
#include "ExprNode.h"

#include <memory>

struct VarNode : ExprNode
{
  VarNode(Token const& token) :
    ExprNode(token)
  {}
};

typedef std::shared_ptr<VarNode> VarNodePtr;
