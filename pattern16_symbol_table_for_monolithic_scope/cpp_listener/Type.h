#pragma once

#include <memory>
#include <string>

struct Type
{
  virtual ~Type() = default;
  virtual std::string get_name() const = 0;
};

typedef std::shared_ptr<Type> TypePtr;

