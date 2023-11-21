#pragma once

#include "Token.h"
#include "Tokens.h"

#include <stdexcept>
#include <sstream>
#include <string>

class InvalidToken : public std::runtime_error
{
  static std::string get_message(Token const& expecting, Token const& found)
  {
    std::ostringstream oss;
    oss << "Expecting '" << expecting
        << "', found '" << found << "'";
    return oss.str();
  }

  static std::string get_message(std::string const& expecting, Token const& found)
  {
    std::ostringstream oss;
    oss << "Expecting '" << expecting
        << "', found '" << found << "'";
    return oss.str();
  }

public:

  Token found_;

  InvalidToken(Token const& expecting, Token const& found) :
    std::runtime_error(get_message(expecting, found).c_str()),
    found_(found)
  {}

  InvalidToken(std::string const& expecting, Token const& found) :
    std::runtime_error(get_message(expecting, found).c_str()),
    found_(found)
  {}  
};

