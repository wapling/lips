#pragma once

#include "InvalidCharacter.h"
#include "InvalidRomanNumeral.h"
#include "Lexer.h"
#include "Token.h"

#include <array>
#include <ostream>
#include <stdexcept>
#include <string>

class RomanNumeralLexer : public Lexer
{
  
public:
  static int const THOUSAND     = 2;
  static int const FIVE_HUNDRED = 3;
  static int const HUNDRED      = 4;
  static int const FIFTY        = 5;
  static int const TEN          = 6;
  static int const FIVE         = 7;
  static int const ONE          = 8;

  static char const THOUSAND_CHAR     = 'M';
  static char const FIVE_HUNDRED_CHAR = 'D';
  static char const HUNDRED_CHAR      = 'C';
  static char const FIFTY_CHAR        = 'L';
  static char const TEN_CHAR          = 'X';
  static char const FIVE_CHAR         = 'V';
  static char const ONE_CHAR          = 'I';
  
  static std::array<char const* const, 9> constexpr token_names
  {
    "n/a",
    "<EOF>",
    "THOUSAND",
    "FIVE_HUNDRED",
    "HUNDRED",
    "FIFTY",
    "TEN",
    "FIVE",
    "ONE"
  };

  static char const* const get_token_name(int x);


  Token next_token() override;
  void ws();
  Token thousand();
  Token five_hundred();
  Token hundred();
  Token fifty();
  Token ten();
  Token five();
  Token one();

  RomanNumeralLexer(std::string const & input) : Lexer(input) {}
};

std::ostream& operator<<(std::ostream& ostrm, Token const& token);

