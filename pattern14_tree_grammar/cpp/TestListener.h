#pragma once

#include "PrinterBaseListener.h"

#include <iostream>

class TestListener : public PrinterBaseListener
{
  bool in_vec_;
  bool first_val_;
  char infix_op_;
  

public:

  TestListener() :
    in_vec_(false),
    first_val_(false),
    infix_op_('\0')
  {}

  void enterStat_equals(PrinterParser::Stat_equalsContext * ctx) override
  {
    std::cout << ctx->ID()->getText() << " = ";
  }

  void exitStat_equals(PrinterParser::Stat_equalsContext * ctx) override
  {
    std::cout << '\n';
  }

  void enterStat_print(PrinterParser::Stat_printContext * ctx) override
  {
    std::cout << "print ";
  }

  void exitStat_print(PrinterParser::Stat_printContext * ctx) override
  {
    std::cout << '\n';
  }

  void enterExpr(PrinterParser::ExprContext * ctx) override
  {
    if (ctx->multExpr().size() > 1)
      infix_op_ = '+';
  }

  void enterMultExpr(PrinterParser::MultExprContext * ctx) override
  {
    if (ctx->primary().size() > 1)
      infix_op_ = '*';
  }

  void enterPrimary_int(PrinterParser::Primary_intContext * ctx) override
  {
    print_comma();
    std::cout << ctx->INT()->getText();
    print_infix_op();
  }

  void enterPrimary_id(PrinterParser::Primary_idContext * ctx) override
  {
    print_comma();
    std::cout << ctx->ID()->getText();
    print_infix_op();
  }

  void enterPrimary_vec(PrinterParser::Primary_vecContext * ctx) override
  {
    in_vec_ = true;
    first_val_ = true;
    std::cout << '[';
  }

  void exitPrimary_vec(PrinterParser::Primary_vecContext * ctx) override
  {
    in_vec_ = false;
    std::cout << ']';
  }

protected:

  virtual void print_infix_op()
  {
    if (infix_op_ != '\0')
    {
      std::cout << infix_op_;
      infix_op_ = '\0';
    }
  }

  virtual void print_comma()
  {
    if (in_vec_)
    {
      if (first_val_)
        first_val_ = false;
      else
        std::cout << ", ";
    }
  }
};

