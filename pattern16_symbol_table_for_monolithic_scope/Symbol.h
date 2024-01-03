#pragma once

#include "Type.h"

#include <memory>
#include <string>

class Symbol
{
  std::string name_;
  TypePtr type_;

public:

  Symbol(std::string const& name) :
    name_(name)
  {}

  Symbol(std::string const& name, TypePtr type) :
    name_(name),
    type_(type)
  {}

  virtual ~Symbol() = default;

  std::string const& get_name() { return name_; }

  std::string to_string();
};

typedef std::shared_ptr<Symbol> SymbolPtr;

