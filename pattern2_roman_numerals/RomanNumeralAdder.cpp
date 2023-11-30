#include "RomanNumeralAdder.h"
#include "Token.h"
#include "Tokens.h"
#include "InvalidRomanNumeral.h"

void RomanNumeralAdder::add(Token const& token)
{
  switch (token.get_type())
  {
    case THOUSAND:
      if (thousands_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += token.get_text().length() * 1000;
      thousands_done_ = true;
      break;

    case FIVE_HUNDRED:
      if (five_hundred_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += 500;
      thousands_done_ = true;
      five_hundred_done_ = true;
      break;

    case HUNDRED:
      if (hundreds_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += token.get_text().length() * 100;
      thousands_done_ = true;
      five_hundred_done_ = true;
      hundreds_done_ = true;
      break;

    case FIFTY:
      if (fifty_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += 50;
      thousands_done_ = true;
      five_hundred_done_ = true;
      hundreds_done_ = true;
      fifty_done_ = true;
      break;

    case TEN:
      if (tens_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += token.get_text().length() * 10;
      thousands_done_ = true;
      five_hundred_done_ = true;
      hundreds_done_ = true;
      fifty_done_ = true;
      tens_done_ = true;
      break;

    case FIVE:
      if (five_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += 5;
      thousands_done_ = true;
      five_hundred_done_ = true;
      hundreds_done_ = true;
      fifty_done_ = true;
      tens_done_ = true;
      five_done_ = true;
      break;
    
    case ONE:
      if (ones_done_)
        throw InvalidRomanNumeral(token.get_text(), "Invalid character order for Roman Numeral");
      total_ += token.get_text().length();
      thousands_done_ = true;
      five_hundred_done_ = true;
      hundreds_done_ = true;
      fifty_done_ = true;
      tens_done_ = true;
      five_done_ = true;
      ones_done_ = true;
      break;
  }
}

