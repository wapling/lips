#pragma once

#include <stdexcept>
#include <string>

struct InvalidCharacter : std::runtime_error
{
  char invalid_;

  static std::string get_message(char invalid)
  {
    std::string message = "Invalid character ' '";
    message[19] = invalid;
    return message;
  }

  InvalidCharacter(char invalid) :
    std::runtime_error(get_message(invalid).c_str()),
    invalid_(invalid)
  {}  
};

