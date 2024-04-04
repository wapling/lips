#pragma once

#include "Symbol.h"
#include "Type.h"

#include <string>

struct VariableSymbol : Symbol
{
  VariableSymbol(std::string const& name, TypePtr type) :
    Symbol(name, type)
  {}

  virtual ~VariableSymbol() = default;
};

