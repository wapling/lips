#pragma once

#include "Ast.h"

#include <memory>
#include <string>
#include <vector>

class ExprNode;

typedef std::shared_ptr<ExprNode> ExprNodePtr;
typedef std::vector<ExprNodePtr> ExprNodePtrs;

class ExprNode : public Ast
{
  int eval_type_;

protected:

  ExprNode(Token const& payload, int eval_type) :
    Ast(payload),
    eval_type_(eval_type)
  {}

  virtual ~ExprNode() = 0;

public:
  
  static int const tINVALID = 0;
  static int const tINTEGER = 1;
  static int const tVECTOR = 2;

  ExprNode(Token const& payload) :
    Ast(payload),
    eval_type_(tINVALID)
  {}

  virtual int get_eval_type() const { return eval_type_; }

  std::string to_string() const override;
};

