#include "ListNode.h"

#include <sstream>

std::string ListNode::to_string_tree() const
{
  if (elements_.empty())
    return to_string();

  std::ostringstream oss;
  bool first_time = true;
  for (auto const& element : elements_)
  {
    if (first_time)
      first_time = false;
    else
      oss << ' ';
    oss << element->to_string_tree();
  }
  return oss.str();
}
