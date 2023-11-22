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
    while (lookahead_.get_type() == COMMA)
    {
      match(COMMA);
      element();
    }
  }

  void element()
  {
    int const lookahead_type = lookahead_.get_type();
    if (lookahead_type == NAME)
      match(NAME);
    else if (lookahead_type == LBRACK)
      list();
    else
      throw InvalidToken("Name or List", lookahead_);
  }

public:

  ListParser(Lexer& input) :
    Parser(input)
  {}

  void list()
  {
    match(LBRACK);
    elements();
    match(RBRACK);
  }
};

