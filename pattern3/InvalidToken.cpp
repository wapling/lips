#include "InvalidToken.h"

#include <sstream>

std::string InvalidToken::get_message(std::string const& expecting, 
                                      Token const& found)
{
  std::ostringstream oss;
  oss << "Expecting '" << expecting
      << "', found '" << found << "'";
  return oss.str();
}
