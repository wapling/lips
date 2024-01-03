#pragma once

#include "Scope.h"
#include "Symbol.h"

#include <memory>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, SymbolPtr> SymbolMap;

std::ostream& operator<<(std::ostream& ostrm, SymbolMap const& data);

class SymbolTable : public Scope
{

  SymbolMap symbols_;

protected:
  
  virtual void init_type_system()
  {
    define(std::make_shared<Symbol>("int"));  
    define(std::make_shared<Symbol>("float"));  
  }

public:

  SymbolTable()
  {
    init_type_system();
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
    auto result = symbols_.find(name);
    if (result == symbols_.end())
      return nullptr;
    else
      return result.->second();
  }

  std::string to_string() const;
};

typedef std::shared_ptr<SymbolTable> SymbolTablePtr;

