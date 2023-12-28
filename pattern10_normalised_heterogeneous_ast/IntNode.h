#pragma once

#include "ExprNode.h"
#include "Token.h"

struct IntNode : ExprNode
{
  IntNode(Token const& token) :
    ExprNode(token, tINTEGER)
  {}
};
