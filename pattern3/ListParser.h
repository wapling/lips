#pragma once

#include "Parser.h"
#include "Lexer.h"
#include "InvalidToken.h"

class ListParser : public Parser
{
  void elements()
  {
    element();
    while (lookahead_.get_type() == ListLexer::COMMA)
    {
      match(ListLexer::COMMA);
      element();
    }
  }

  void element()
  {
    int const lookahead_type = lookahead_.get_type();
    if (lookahead_type == ListLexer::NAME)
      match(ListLexer::NAME);
    else if (lookahead_type == ListLexer::LBRACK)
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
    match(ListLexer::LBRACK);
    elements();
    match(ListLexer::RBRACK);
  }
};

