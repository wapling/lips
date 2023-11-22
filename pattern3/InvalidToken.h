#pragma once

#include "Token.h"
#include "Tokens.h"

#include <stdexcept>
#include <sstream>
#include <string>
#include <utility>


class InvalidToken : public std::runtime_error
{
  static std::string get_message(std::string const& expecting, Token const& found)
  {
    std::ostringstream oss;
    oss << "Expecting '" << expecting
        << "', found '" << found << "'";
    return oss.str();
  }

public:

  std::string expecting_;
  Token found_;

  InvalidToken(std::string expecting, Token const& found) :
    std::runtime_error(get_message(expecting, found)),
    expecting_(std::move(expecting)),
    found_(found)
  {}  
};

