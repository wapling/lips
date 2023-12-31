#pragma once

#include "HeteroAST.h"
#include "Token.h"

#include <memory>
#include <vector>

struct ExprNode;

typedef std::shared_ptr<ExprNode> ExprNodePtr;
typedef std::vector<ExprNodePtr> ExprNodePtrs;

struct ExprNode : HeteroAST
{
  ExprNode(Token const& payload) :
    HeteroAST(payload)
  {}

  virtual ~ExprNode() = 0;
};

