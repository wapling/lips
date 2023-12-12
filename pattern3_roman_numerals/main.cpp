#include "RomanNumeralLexer.h"
#include "RomanNumeralParser.h"
#include "InvalidRomanNumeral.h"
#include "InvalidCharacter.h"

#include <iostream>

using namespace std;

void LoopOverInput()
{
  for(string input; getline(cin, input);)
  {
    RomanNumeralLexer lexer(input);
    RomanNumeralParser parser(lexer);

    try
    {
      int total = parser.translate();
      cout << "Roman numeral: " << input << " = " << total << '\n';
    }
    catch (InvalidRomanNumeral const& ex)
    {
      cout << "Invalid Roman Numeral: " << input 
           << " has the following error:\n" << ex.what() << '\n';
    }
    catch (InvalidCharacter const& ex)
    {
      cout << "Invalid Character: " << input << '\n' << ex.what() << '\n';
    }
  }
}


int main(int argc, char* argv[])
{
  try
  {
    LoopOverInput();
    return 0;
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}


