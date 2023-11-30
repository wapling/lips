#include "RomanNumeralLexer.h"
#include "RomanNumeralAdder.h"
#include "Tokens.h"

#include <iostream>

using namespace std;

void LoopOverInput()
{
  for(string input; getline(cin, input);)
  {
    RomanNumeralLexer lexer(input);
    RomanNumeralAdder adder;
    Token token(Lexer::EOF_TYPE, lexer.get_token_name(Lexer::EOF_TYPE));

    try
    {
      do
      {
        token = lexer.next_token();
        cout << token << '\n';
        adder.add(token);
      } while (token.get_type() != Lexer::EOF_TYPE);

      cout << "Roman numeral: " << input << " = " << adder.get_total() << '\n';
    }
    catch (InvalidRomanNumeral const& ex)
    {
      cout << "Invalid Roman Numeral: " << input 
           << " has the following error:\n" << ex.what() << '\n';
    }
    catch (InvalidCharacter const& ex)
    {
      cout << "Invalid Roman Numeral: " << input 
           << " has the following error:\n" << ex.what() << '\n';
    }
  }
}


int main(int argc, char* argv[])
{
  LoopOverInput();
}



