#pragma once

#include "Token.h"

#include <iosfwd>
#include <string>
#include <vector>

class Ast
{
  Token token_;
  std::vector<Ast> children_;

  void to_string_tree(std::ostream& ostrm) const;

public:

  Ast() {}

  Ast(Token const& token) :
    token_(token)
  {}

  Ast(int token_type) :
    token_(token_type)
  {}

  int get_node_type() const { return token_.get_type(); }

  void add_child(Ast const& ast)
  {
    children_.push_back(ast);
  }

  bool is_nil() const { return get_node_type() == INVALID_TOKEN_TYPE; }

  std::string const& to_string() const
  {
    static std::string const nil = "nil";
    return is_nil() ? nil : token_.get_text();
  }

  std::string to_string_tree() const;
};
