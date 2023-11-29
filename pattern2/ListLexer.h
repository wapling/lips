#pragma once

#include "Lexer.h"
#include "Token.h"
#include "InvalidCharacter.h"

#include <array>
#include <ostream>
#include <string>

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

