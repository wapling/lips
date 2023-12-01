#pragma once

#include <stdexcept>

struct InvalidCharacter : std::runtime_error
{
  char invalid_;

  static const char* const get_message(char invalid)
  {
    static char message[] = "Invalid character ' '";
    message[19] = invalid;
    return message;
  }

  InvalidCharacter(char invalid) :
    std::runtime_error(get_message(invalid)),
    invalid_(invalid)
  {}  
};

