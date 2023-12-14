#pragma once

#include "Lexer.h"
#include "Token.h"
#include "InvalidCharacter.h"

#include <string>

struct BacktrackingLexer : Lexer
{
  BacktrackingLexer(std::string const& input) : Lexer(input) 
  {}

  char const* const get_token_name(int x) const override;

  Token next_token() override;
  void ws();
  Token name();
};

