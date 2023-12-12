#pragma once

#include "InvalidCharacter.h"
#include "InvalidRomanNumeral.h"
#include "Lexer.h"
#include "Token.h"

#include <string>

class RomanNumeralLexer : public Lexer
{
  
public:
  char const* const get_token_name(int x) const override;

  Token next_token() override;
  void ws();
  Token thousand();
  Token five_hundred();
  Token hundred();
  Token fifty();
  Token ten();
  Token five();
  Token one();

  RomanNumeralLexer(std::string const& input) : Lexer(input)
  {}
};

