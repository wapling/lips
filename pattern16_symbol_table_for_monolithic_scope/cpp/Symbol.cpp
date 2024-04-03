#include "Symbol.h"

#include <ostream>
#include <sstream>

std::string Symbol::to_string() const
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

std::ostream& operator<<(std::ostream& ostrm, Symbol const& data)
{
  return ostrm << data.to_string();
}

