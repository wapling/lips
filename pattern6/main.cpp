#include "BacktrackingLexer.h"
#include "BacktrackingParser.h"

#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    for (string input; getline(cin, input);)
    {
      BacktrackingLexer lexer(input);
      BacktrackingParser parser(lexer);
      parser.stat();
    }
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}



