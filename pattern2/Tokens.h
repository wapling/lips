#pragma once

#include "Token.h"

#include <iosfwd>

int const NAME   = 2;
int const COMMA  = 3;
int const LBRACK = 4;
int const RBRACK = 5;

char const* const get_token_name(int x);

std::ostream& operator<<(std::ostream& ostrm, Token const& token);
