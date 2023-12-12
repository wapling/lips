#include "RomanNumeralLexer.h"
#include "Tokens.h"

#include <sstream>

using namespace std;

char const* const RomanNumeralLexer::get_token_name(int x) const
{
  return ::get_token_name(x);
}

Token RomanNumeralLexer::next_token()
{
  while (current_ != EOF_CHAR)
  {
    switch (current_)
    {
      case ' ': case '\t': case '\n': case '\r': 
        ws();
        break;

      case THOUSAND_CHAR:     return thousand();
      case FIVE_HUNDRED_CHAR: return five_hundred();
      case HUNDRED_CHAR:      return hundred();
      case FIFTY_CHAR:        return fifty();
      case TEN_CHAR:          return ten();
      case FIVE_CHAR:         return five();
      case ONE_CHAR:          return one();
      default:
        throw InvalidCharacter(current_);
    }
  }
  return Token(EOF_TYPE, get_token_name(EOF_TYPE));
}

void RomanNumeralLexer::ws()
{
  while (current_ == ' '  ||
         current_ == '\t' ||
         current_ == '\n' ||
         current_ == '\r' )
    consume();
}

Token RomanNumeralLexer::thousand()
{
  ostringstream oss;
  do
  {
    oss << current_;
    consume();
  } while (current_ == THOUSAND_CHAR);
  return Token(THOUSAND, oss.str());
}

Token RomanNumeralLexer::five_hundred()
{
  consume();
  return Token(FIVE_HUNDRED, FIVE_HUNDRED_CHAR);
}

Token RomanNumeralLexer::hundred()
{
  ostringstream oss;
  int count = 0;
  do
  {
    if (count > 4)
      throw InvalidRomanNumeral(get_input(), "More than 4 consecutive Cs");
    oss << current_;
    consume();
    ++count;
  } while (current_ == HUNDRED_CHAR);
  return Token(HUNDRED, oss.str());
}

Token RomanNumeralLexer::fifty()
{
  consume();
  return Token(FIFTY, FIFTY_CHAR);
}

Token RomanNumeralLexer::ten()
{
  ostringstream oss;
  int count = 0;
  do
  {
    if (count > 4)
      throw InvalidRomanNumeral(get_input(), "More than 4 consecutive Xs");
    oss << current_;
    consume();
    ++count;
  } while (current_ == TEN_CHAR);
  return Token(TEN, oss.str());
}

Token RomanNumeralLexer::five()
{
  consume();
  return Token(FIVE, FIVE_CHAR);
}

Token RomanNumeralLexer::one()
{
  ostringstream oss;
  int count = 0;
  do
  {
    if (count > 4)
      throw InvalidRomanNumeral(get_input(), "More than 4 consecutive Is");
    oss << current_;
    consume();
    ++count;
  } while (current_ == ONE_CHAR);
  return Token(ONE, oss.str());
}


