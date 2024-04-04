#include "SymbolTable.h"

#include <sstream>

std::ostream& operator<<(std::ostream& ostrm, SymbolMap const& data)
{
  bool first_try = true;
  for (auto const& datum : data)
  {
    if (first_try)
      first_try = false;
    else
      ostrm << ", ";
    ostrm << datum.first << "=" << *datum.second;
  }
  return ostrm;
}

std::string SymbolTable::to_string() const
{
  std::ostringstream oss;
  oss << get_scope_name() << ": {" << symbols_ << "}";
  return oss.str();
}

