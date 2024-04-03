#pragma once

#include "Symbol.h"

#include <memory>
#include <string>

struct Scope;

typedef std::shared_ptr<Scope> ScopePtr;

struct Scope
{
  virtual ~Scope() = default;

  virtual std::string const& get_scope_name() const = 0;

  virtual ScopePtr get_enclosing_scope() const = 0;

  virtual void define(SymbolPtr symbol) = 0;

  virtual SymbolPtr resolve(std::string const& name) = 0;
};

