#pragma once

#include "ExprNode.h"
#include "Token.h"

#include <string>

class AddNode : public ExprNode
{
  ExprNodePtr left_;
  ExprNodePtr right_;

public:

  AddNode(ExprNodePtr left, Token const& add_token, ExprNodePtr right) :
    ExprNode(add_token),
    left_(left),
    right_(right)
  {}

  std::string to_string_tree() const override;
};

