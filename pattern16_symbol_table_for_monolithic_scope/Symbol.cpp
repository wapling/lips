#include "Symbol.h"

#include <sstream>

std::string Symbol::to_string()
{
  if (type_)
  {
    std::ostringstream oss;
    oss << '<' << get_name() << ':' << type_->get_name() << '>';
    return oss.str();
  }
  else
    return get_name();
}

