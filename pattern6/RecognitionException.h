#pragma once

#include "Token.h"

#include <stdexcept>
#include <string>

class RecognitionException : public std::runtime_error
{
  static std::string get_message(Token const& expecting, Token const& found);

  static std::string get_message(std::string const& expecting, Token const& found);

protected:
  RecognitionException(std::string const& message) :
    std::runtime_error(message)
  {}

public:
  RecognitionException(Token const& expecting, Token const& found) :
    std::runtime_error(get_message(expecting, found).c_str())
  {}

  RecognitionException(std::string const& expecting, Token const& found) :
    std::runtime_error(get_message(expecting, found).c_str())
  {}  
};

