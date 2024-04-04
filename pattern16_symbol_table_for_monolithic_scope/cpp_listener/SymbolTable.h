#pragma once

#include "Scope.h"
#include "Symbol.h"
#include "BuiltInTypeSymbol.h"

#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>


typedef std::unordered_map<std::string, SymbolPtr> SymbolMap;

std::ostream& operator<<(std::ostream& ostrm, SymbolMap const& data);

class SymbolTable : public Scope
{

  SymbolMap symbols_;

public:

  SymbolTable()
  {
    define(std::make_shared<BuiltInTypeSymbol>("int"));  
    define(std::make_shared<BuiltInTypeSymbol>("float"));
  }

  std::string const& get_scope_name() const
  {
    static std::string global = "global";
    return global;
  }

  ScopePtr get_enclosing_scope() const
  {
    return nullptr;
  }

  void define(SymbolPtr symbol)
  {
    symbols_[symbol->get_name()] = symbol;
  }

  SymbolPtr resolve(std::string const& name)
  {
    auto const& result = symbols_.find(name);
    if (result == symbols_.end())
      return nullptr;
    else
      return result->second;
  }

  std::string to_string() const;
};

typedef std::shared_ptr<SymbolTable> SymbolTablePtr;

