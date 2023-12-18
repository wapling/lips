#include "RecognitionException.h"
#include "Tokens.h"

#include <sstream>

std::string RecognitionException::get_message(Token const& expecting,
                                              Token const& found)
{
  std::ostringstream oss;
  oss << "Expecting '" << expecting
      << "', found '" << found << "'";
  return oss.str();
}

std::string RecognitionException::get_message(std::string const& expecting,
                                              Token const& found)
{
  std::ostringstream oss;
  oss << "Expecting '" << expecting
      << "', found '" << found << "'";
  return oss.str();
}

