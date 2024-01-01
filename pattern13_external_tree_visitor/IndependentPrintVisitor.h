#pragma once

#include "VecMathNode.h"

#include <stdexcept>

namespace IndependentPrintVisitor
{

struct UnknownNodeTypeException : std::runtime_error
{
  using std::runtime_error::runtime_error;
};

void print(VecMathNode const& node);

} // namespace IndependentPrintVisitor
