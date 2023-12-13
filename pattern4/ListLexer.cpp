#include "ListLexer.h"
#include "Tokens.h"

#include <sstream>

using namespace std;

namespace
{

bool is_letter(char x)
{
  return (x >= 'a' && x <= 'z') ||
         (x >= 'A' && x <= 'Z');
}

}

char const* const ListLexer::get_token_name(int x) const
{
  return ::get_token_name(x);
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

      case COMMA_CHAR:
        consume();
        return Token(COMMA, COMMA_CHAR);

      case LBRACK_CHAR:
        consume();
        return Token(LBRACK, LBRACK_CHAR);

      case RBRACK_CHAR:
        consume();
        return Token(RBRACK, RBRACK_CHAR);

      case EQUALS_CHAR:
        consume();
        return Token(EQUALS, EQUALS_CHAR);

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
  do
  {
    oss << current_;
    consume();
  } while (is_letter(current_));
  return Token(NAME, oss.str());
}



