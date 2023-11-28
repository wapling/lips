#include "RomanNumeralLexer.h"
#include "RomanNumeralAdder.h"
#include "InvalidRomanNumeral.h"

#include <iostream>

using namespace std;

void LoopOverInput()
{
  for(string input; getline(cin, input);)
  {
    RomanNumeralLexer lexer(input);
    RomanNumeralAdder adder;
    Token token(Lexer::EOF_TYPE, RomanNumeralLexer::get_token_name(Lexer::EOF_TYPE));

    try
    {
      do
      {
        token = lexer.next_token();
        cout << token << '\n';
        adder.add(token);
      } while (token.get_type() != Lexer::EOF_TYPE);

      cout << adder.get_total() << '\n';
    }
    catch (InvalidRomanNumeral const& ex)
    {
      cout << "Invalid Roman Numeral: " << ex.what() << '\n';
    }
  }
}


int main(int argc, char* argv[])
{
  LoopOverInput();
}



