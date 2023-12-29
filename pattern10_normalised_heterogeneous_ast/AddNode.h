#pragma once

#include "ExprNode.h"
#include "Token.h"

struct AddNode : ExprNode
{
  AddNode(ExprNodePtr left, Token const& add_token, ExprNodePtr right) :
    ExprNode(add_token)
  {
    add_child(left);
    add_child(right);
  }
 /* 
  int get_eval_type() const override
  {
    ExprNode* left_node = static_cast<ExprNode*>(children_[0].get());
    ExprNode* right_node = static_cast<ExprNode*>(children_[1].get());

    const int left_eval_type = left_node->get_eval_type();
    const int right_eval_type = right_node->get_eval_type();

    if (left_eval_type != right_eval_type)
      return tINVALID;
    else
      return left_eval_type;
  }
*/
};

