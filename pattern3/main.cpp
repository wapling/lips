#include "ListLexer.h"
#include "ListParser.h"

#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    for (string input; getline(cin, input);)
    {
      ListLexer lexer(input);
      ListParser parser(lexer);
      parser.list();
    }
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}



