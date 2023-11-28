#pragma once

#include <ostream>
#include <stdexcept>
#include <string>

struct InvalidRomanNumeral : public std::runtime_error
{
  std::string invalid_numeral_;

public:
  InvalidRomanNumeral(std::string invalid_numeral, std::string message) :
    std::runtime_error(std::move(message)),
    invalid_numeral_(std::move(invalid_numeral))
  {}
};

