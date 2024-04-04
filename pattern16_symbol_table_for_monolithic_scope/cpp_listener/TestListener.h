#pragma once

#include "SymbolTable.h"
#include "Type.h"
#include "VariableSymbol.h"

#include "CymbolBaseListener.h"

#include <iostream>

class TestListener : public CymbolBaseListener
{
  SymbolTablePtr symtab_;

public:

  TestListener(SymbolTablePtr symtab) :
    symtab_(symtab)
  {}

  void exitVarDeclaration(CymbolParser::VarDeclarationContext * ctx) override
  {
    std::cout << "line " << ctx->ID()->getSymbol()->getLine()
              << ": def " << ctx->ID()->getText() << '\n';

    TypePtr tsym = std::dynamic_pointer_cast<Type>(
      symtab_->resolve(ctx->type()->getText()));
    SymbolPtr vs(std::make_shared<VariableSymbol>(ctx->ID()->getText(), tsym));
    symtab_->define(vs);
  }

  void exitType(CymbolParser::TypeContext * ctx) override
  {
    TypePtr tsym = std::dynamic_pointer_cast<Type>(
      symtab_->resolve(ctx->getText()));
    std::cout << "line " << ctx->start->getLine()
              << ": ref " << tsym->get_name() << '\n';
  }

  void enterPrimary_id(CymbolParser::Primary_idContext * ctx) override
  {
    std::cout << "line " << ctx->ID()->getSymbol()->getLine()
              << ": ref to " << *symtab_->resolve(ctx->ID()->getText()) << '\n';
  }



};

