#include "ListLexer.h"

#include <sstream>
#include <array>

using namespace std;

namespace
{

bool is_letter(char x)
{
  return (x >= 'a' && x <= 'z') ||
         (x >= 'A' && x <= 'Z');
}

}

string const& ListLexer::get_token_name(int x)
{
  static array<string, 6> const token_names 
  {
    "n/a",
    "<EOF>",
    "NAME",
    "COMMA",
    "LBRACK",
    "RBRACK"
  };
  static string const nothing = "";

  if (x < 0 || x >= token_names.size())
    return nothing;

  return token_names[x];
}

Token ListLexer::next_token()
{
  while (current_ != EOF_CHAR)
  {
    switch (current_)
    {
      case ' ': case '\t': case '\n': case '\r': 
        ws();
        break;

      case ',':
        consume();
        return Token(COMMA, ",");

      case '[':
        consume();
        return Token(LBRACK, "[");

      case ']':
        consume();
        return Token(RBRACK, "]");

      default:
        if (is_letter(current_))
          return name();
        throw InvalidCharacter(current_);
    }
  }
  return Token(EOF_TYPE, get_token_name(EOF_TYPE));
}

void ListLexer::ws()
{
  while (current_ == ' '  ||
         current_ == '\t' ||
         current_ == '\n' ||
         current_ == '\r' )
    consume();
}

Token ListLexer::name()
{
  ostringstream oss;
  while (is_letter(current_))
  {
    oss << current_;
    consume();
  }
  return Token(NAME, oss.str());
}

ostream& operator<<(ostream& ostrm, Token const& token)
{
  ostrm << "<'" << token.get_text() 
        << "',"  << ListLexer::get_token_name(token.get_type())
        << ">";
  return ostrm;  
}


