#pragma once

#include "HeteroAST.h"

#include <string>
#include <vector>

class ListNode : public HeteroAST
{
  HeteroASTPtrs elements_;

public:

  ListNode(HeteroASTPtrs const& elements) :
    elements_(elements)    
  {}

  std::string to_string_tree() const override;
};
