#pragma once

#include "Lexer.h"
#include "Token.h"

#include <ostream>
#include <string>

class ListLexer : public Lexer
{
public:
  static int const NAME   = 2;
  static int const COMMA  = 3;
  static int const LBRACK = 4;
  static int const RBRACK = 5;

  ListLexer(std::string const & input) : Lexer(input) 
  {}

  std::string const& get_token_name(int x) const override;

  Token next_token() override;
  void ws();
  Token name();
};

