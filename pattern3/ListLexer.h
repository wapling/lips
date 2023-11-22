#pragma once

#include "Lexer.h"
#include "Token.h"

#include <ostream>
#include <string>

class ListLexer : public Lexer
{
public:

  ListLexer(std::string const & input) : Lexer(input) 
  {}

  std::string const& get_token_name(int x) const override;

  Token next_token() override;
  void ws();
  Token name();
};

