#pragma once

#include "Parser.h"
#include "Lexer.h"
#include "Tokens.h"
#include "InvalidToken.h"

class ListParser : public Parser
{
  void elements()
  {
    element();
    while (LA(1) == COMMA)
    {
      match(COMMA);
      element();
    }
  }

  void element()
  {
    int const LA1 = LA(1);
    int const LA2 = LA(2);
    if (LA1 == NAME && LA2 == EQUALS)
    {
      match(NAME);
      match(EQUALS);
      match(NAME);
    } 
    else if (LA1 == NAME)
      match(NAME);
    else if (LA1 == LBRACK)
      list();
    else
      throw InvalidToken("Name or List", LT(1));
  }

public:

  ListParser(Lexer& input, size_t depth) :
    Parser(input, depth)
  {}

  void list()
  {
    match(LBRACK);
    elements();
    match(RBRACK);
  }
};

