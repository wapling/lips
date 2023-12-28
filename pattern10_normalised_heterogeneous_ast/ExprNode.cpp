#include "ExprNode.h"

ExprNode::~ExprNode()
{}

std::string ExprNode::to_string() const
{
  switch (get_eval_type())
  {
    case tINTEGER:
      return Ast::to_string() + "<type=tINTEGER>";
    case tVECTOR:
      return Ast::to_string() + "<type=tVECTOR>";
    default:
      return Ast::to_string();
  }
}

