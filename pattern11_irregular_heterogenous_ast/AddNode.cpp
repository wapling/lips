#include "AddNode.h"

#include <sstream>

std::string AddNode::to_string_tree() const
{
  if (left_ == nullptr || right_ == nullptr)
    return to_string();

  std::ostringstream oss;
  oss << '(' << to_string() 
      << ' ' << left_->to_string_tree()
      << ' ' << right_->to_string_tree()
      << ')';
  return oss.str();
}
