#pragma once

#include "Parser.h"
#include "Lexer.h"
#include "Tokens.h"
#include "RecognitionException.h"
#include "NoViableAltException.h"

class BacktrackingParser : public Parser
{
  bool speculate(void (BacktrackingParser::* alt_func)())
  {
    bool retval = true;
    mark();
    try
    {
      (this->*alt_func)();
    }
    catch (RecognitionException const&)
    {
      retval = false;
    }
    release();
    return retval;
  }

  void stat_alt1()
  {
    list();
    match(Lexer::EOF_TYPE);
  }

  void stat_alt2()
  {
    assign();
    match(Lexer::EOF_TYPE);
  }

  void elements()
  {
    // match comma seperated list
    // pattern: element (',' element)*
    element();
    while (LA(1) == COMMA)
    {
      match(COMMA);
      element();
    }
  }

  void element()
  {
    // match assignment, name or list
    // pattern: NAME '=' NAME | NAME | list
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
      throw NoViableAltException("Expecting element found ", LT(1));
  }

  void assign()
  {
    // match parallel assignment
    // pattern: list '=' list
    list();
    match(EQUALS);
    list();
  }

  void list()
  {
    // match bracketed list
    // pattern: '[' elements ']'
    match(LBRACK);
    elements();
    match(RBRACK);
  }

public:

  BacktrackingParser(Lexer& input) :
    Parser(input)
  {}

  void stat()
  {
    // match statement: list or assignment
    // pattern: list EOF | assign EOF
    if (speculate(&BacktrackingParser::stat_alt1))
      stat_alt1();
    else if (speculate(&BacktrackingParser::stat_alt2))
      stat_alt2();
    else
      throw NoViableAltException("stat", LT(1));
  }
};

