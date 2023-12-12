#pragma once

#include "InvalidRomanNumeral.h"

#include <stdexcept>
#include <string>
#include <utility>

class Token;

struct OutOfOrderRomanNumeral : InvalidRomanNumeral
{

  static std::string get_message(Token const& first, Token const& second);

  OutOfOrderRomanNumeral(std::string invalid_numeral, 
                         Token const& first,
                         Token const& second) :
    InvalidRomanNumeral(std::move(invalid_numeral), 
                        get_message(first, second))
  {}
};

