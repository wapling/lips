#pragma once

#include "Lexer.h"
#include "Token.h"

#include <string>

struct ListLexer : public Lexer
{
  ListLexer(std::string const& input) : Lexer(input) 
  {}

  std::string const& get_token_name(int x) const override;

  Token next_token() override;
  void ws();
  Token name();
};

