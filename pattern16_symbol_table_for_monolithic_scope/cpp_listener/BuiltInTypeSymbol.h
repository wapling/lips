#pragma once

#include "Symbol.h"
#include "Type.h"

#include <string>

struct BuiltInTypeSymbol : Symbol, Type
{
  BuiltInTypeSymbol(std::string const& name) :
    Symbol(name)
  {}

  virtual ~BuiltInTypeSymbol() = default;

  std::string get_name() const override
  {
    return Symbol::get_name();
  }
};

