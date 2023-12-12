#include "OutOfOrderRomanNumeral.h"
#include "Token.h"

#include <sstream>

std::string OutOfOrderRomanNumeral::get_message(Token const& first, 
                                                Token const& second)
{
  std::ostringstream oss;

  oss << "Out of order Roman numeral, '"
      << first.get_text()
      << "' appears before '"
      << second.get_text()
      << "'.";

  return oss.str();
}
