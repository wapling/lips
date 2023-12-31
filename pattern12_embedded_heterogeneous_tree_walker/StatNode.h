#pragma once

#include "Token.h"
#include "VecMathNode.h"

#include <memory>
#include <vector>

struct StatNode : VecMathNode
{
  StatNode() = default;
  StatNode(Token const& token) :
    VecMathNode(token)
  {}
};

typedef std::shared_ptr<StatNode> StatNodePtr;
typedef std::vector<StatNodePtr> StatNodePtrs;

