#include "ListLexer.h"
#include "Tokens.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  for(string input; getline(cin, input);)
  {
    ListLexer lexer(input);
    Token token (Lexer::EOF_TYPE, lexer.get_token_name(Lexer::EOF_TYPE));
    do
    {
      token = lexer.next_token();
      cout << token << '\n';
    } while (token.get_type() != Lexer::EOF_TYPE);
  }
}



