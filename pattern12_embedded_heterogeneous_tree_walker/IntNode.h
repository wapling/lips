#pragma once

#include "Token.h"
#include "ExprNode.h"

#include <string>

struct IntNode : ExprNode
{
  IntNode(Token const& token) :
    ExprNode(token)
  {}

  IntNode(int i) :
    ExprNode(Token(Token::INT, std::to_string(i)))
  {}
};

