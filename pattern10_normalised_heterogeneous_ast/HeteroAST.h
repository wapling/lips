#pragma once

#include "Token.h"

#include <string>

struct HeteroAST
{
  Token token_;

  HeteroAST() = default;
  HeteroAST(Token const& token) :
    token_(token)
  {}
  HeteroAST(int token_type) :
    token_(token_type)
  {}

  virtual std::string to_string() const { return token_.to_string(); }
  virtual std::string to_string_tree() const { return to_string(); }
};

