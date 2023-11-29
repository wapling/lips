#pragma once

#include <stdexcept>
#include <string>
#include <utility>

struct InvalidRomanNumeral : std::runtime_error
{
  std::string invalid_numeral_;

  InvalidRomanNumeral(std::string invalid_numeral, std::string message) :
    std::runtime_error(std::move(message)),
    invalid_numeral_(std::move(invalid_numeral))
  {}
};

