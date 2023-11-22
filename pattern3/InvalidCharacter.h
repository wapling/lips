#pragma once

#include <string>
#include <stdexcept>

class InvalidCharacter : public std::runtime_error
{
  static std::string get_message(char invalid)
  {
    std::string message = "Invalid character ' '";
    message[19] = invalid;
    return message;
  }

public:

  char invalid_;

  InvalidCharacter(char invalid) :
    std::runtime_error(get_message(invalid)),
    invalid_(invalid)
  {}  
};

