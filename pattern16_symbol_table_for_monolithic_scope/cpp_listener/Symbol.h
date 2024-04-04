#pragma once

#include "Type.h"

#include <iosfwd>
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

  virtual std::string get_name() const { return name_; }

  virtual std::string to_string() const;
};

typedef std::shared_ptr<Symbol> SymbolPtr;

std::ostream& operator<<(std::ostream& ostrm, Symbol const& data);

