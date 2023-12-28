#pragma once

#include "Token.h"

#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

class Ast;

typedef std::shared_ptr<Ast> AstPtr;
typedef std::vector<AstPtr> AstPtrs;

class Ast
{
protected:

  Token token_;
  AstPtrs children_;

  void to_string_tree(std::ostream& ostrm) const;

public:

  Ast() = default;

  Ast(Token const& token) :
    token_(token)
  {}

  Ast(int token_type) :
    token_(token_type)
  {}

  virtual ~Ast() = default;

  int get_node_type() const { return token_.get_type(); }

  void add_child(AstPtr ast)
  {
    children_.push_back(ast);
  }

  bool is_nil() const { return get_node_type() == INVALID_TOKEN_TYPE; }

  virtual std::string to_string() const
  {
    static std::string const nil = "nil";
    return is_nil() ? nil : token_.get_text();
  }

  virtual std::string to_string_tree() const;
};
