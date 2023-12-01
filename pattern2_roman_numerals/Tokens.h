#pragma once

#include "Token.h"

#include <iosfwd>


int const THOUSAND     = 2;
int const NINE_HUNDRED = 3;
int const FIVE_HUNDRED = 4;
int const HUNDRED      = 5;
int const NINETY       = 6;
int const FIFTY        = 7;
int const TEN          = 8;
int const NINE         = 9;
int const FIVE         = 10;
int const FOUR         = 11;
int const ONE          = 12;

char const THOUSAND_CHAR     = 'M';
char const FIVE_HUNDRED_CHAR = 'D';
char const HUNDRED_CHAR      = 'C';
char const FIFTY_CHAR        = 'L';
char const TEN_CHAR          = 'X';
char const FIVE_CHAR         = 'V';
char const ONE_CHAR          = 'I';
  
char const* const get_token_name(int x);

std::ostream& operator<<(std::ostream& ostrm, Token const& token);

