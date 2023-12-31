#pragma once

#include "Token.h"

#include <memory>
#include <string>
#include <vector>

struct HeteroAST;

typedef std::shared_ptr<HeteroAST> HeteroASTPtr;
typedef std::vector<HeteroASTPtr> HeteroASTPtrs;

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
  virtual ~HeteroAST() = default;

  virtual std::string to_string() const { return token_.get_text(); }
  virtual std::string to_string_tree() const { return to_string(); }
};

