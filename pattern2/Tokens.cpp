#include "Tokens.h"

#include <array>
#include <ostream>

using namespace std;

char const* const get_token_name(int x)
{
  static array<char const* const, 6> const token_names 
  {
    "n/a",
    "<EOF>",
    "NAME",
    "COMMA",
    "LBRACK",
    "RBRACK"
  };
  static char const* const nothing = "";

  if (x < 0 || x >= token_names.size())
    return nothing;

  return token_names[x];
}


ostream& operator<<(ostream& ostrm, Token const& token)
{
  ostrm << "<'" << token.get_text() 
        << "'," << get_token_name(token.get_type())
        << ">";
  return ostrm;  
}

