#pragma once

#include "Lexer.h"
#include "Token.h"

#include <array>
#include <ostream>
#include <stdexcept>
#include <string>

struct InvalidCharacter : public std::runtime_error
{
  char invalid_;

  static std::string get_message(char invalid)
  {
    std::string message = "Invalid character ' '";
    message[19] = invalid;
    return message;
  }

public:
  InvalidCharacter(char invalid) :
    std::runtime_error(get_message(invalid).c_str()),
    invalid_(invalid)
  {}  
};

class ListLexer : public Lexer
{
  
public:
  static int const NAME   = 2;
  static int const COMMA  = 3;
  static int const LBRACK = 4;
  static int const RBRACK = 5;

  static std::array<char const* const, 6> constexpr token_names
  {
    "n/a",
    "<EOF>",
    "NAME",
    "COMMA",
    "LBRACK",
    "RBRACK"
  };

  static char const* const get_token_name(int x);

  Token next_token() override;
  void ws();
  Token name();

  ListLexer(std::string const & input) : Lexer(input) {}
};

std::ostream& operator<<(std::ostream& ostrm, Token const& token);

