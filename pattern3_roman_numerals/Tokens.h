#pragma once

#include "Token.h"

#include <iosfwd>


int const THOUSAND     = 2;
int const FIVE_HUNDRED = 3;
int const HUNDRED      = 4;
int const FIFTY        = 5;
int const TEN          = 6;
int const FIVE         = 7;
int const ONE          = 8;

char const THOUSAND_CHAR     = 'M';
char const FIVE_HUNDRED_CHAR = 'D';
char const HUNDRED_CHAR      = 'C';
char const FIFTY_CHAR        = 'L';
char const TEN_CHAR          = 'X';
char const FIVE_CHAR         = 'V';
char const ONE_CHAR          = 'I';
  
char const* const get_token_name(int x);

std::ostream& operator<<(std::ostream& ostrm, Token const& token);

