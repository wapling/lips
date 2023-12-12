#pragma once

#include "Parser.h"
#include "Lexer.h"
#include "Tokens.h"
#include "InvalidToken.h"
#include "OutOfOrderRomanNumeral.h"

class RomanNumeralParser : public Parser
{

public:

  RomanNumeralParser(Lexer& input) :
    Parser(input)
  {}

  int translate()
  {
    bool first_token = true;
    int total = 0;

    Token last = lookahead_;
    if (lookahead_.get_type() == THOUSAND)
    {
      last = lookahead_;
      total += lookahead_.get_text().length() * 1000;
      match(THOUSAND);
      first_token = false;
    }
    if (lookahead_.get_type() == FIVE_HUNDRED)
    {
      last = lookahead_;
      total += 500;
      match(FIVE_HUNDRED);
      first_token = false;
    }
    if (lookahead_.get_type() == HUNDRED)
    {
      bool nine_hundred_legal = first_token || last.get_type() != FIVE_HUNDRED;

      last = lookahead_;
      total += last.get_text().length() * 100;
      match(HUNDRED);
      first_token = false;

      if (nine_hundred_legal &&
          last.get_text().length() == 1 &&
          lookahead_.get_type() == THOUSAND &&
          lookahead_.get_text().length() == 1)
      {
        last = lookahead_;
        total += 800;
        match(THOUSAND);
      }
    }
    if (lookahead_.get_type() == FIFTY)
    {
      last = lookahead_;
      total += 50;
      match(FIFTY);
      first_token = false;
    }
    if (lookahead_.get_type() == TEN)
    {
      bool ninety_legal = first_token || last.get_type() != FIFTY;

      last = lookahead_;
      total += last.get_text().length() * 10;
      match(TEN);

      if (ninety_legal &&
          last.get_text().length() == 1 &&
          lookahead_.get_type() == HUNDRED &&
          lookahead_.get_text().length() == 1)
      {
        last = lookahead_;
        total += 80;
        match(HUNDRED);
      }
    }
    if (lookahead_.get_type() == FIVE)
    {
      last = lookahead_;
      total += 5;
      match(FIVE);
    }
    if (lookahead_.get_type() == ONE)
    {
      last = lookahead_;
      total += last.get_text().length();
      match(ONE);
      
      if (last.get_text().length() == 1 &&
          lookahead_.get_text().length() == 1)
      {
        if (lookahead_.get_type() == TEN)
        {
          last = lookahead_;
          total += 8;
          match(TEN);
        }
        else if (lookahead_.get_type() == FIVE)
        {
          last = lookahead_;
          total += 3;
          match(FIVE);
        }
      }          
    }

    if (lookahead_.get_type() != Lexer::EOF_TYPE)
      throw OutOfOrderRomanNumeral(input_.get_input(), last, lookahead_);

    return total;
  }
    
};

