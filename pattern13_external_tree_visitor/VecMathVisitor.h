#pragma once

class AddNode;
class AssignNode;
class DotProductNode;
struct IntNode;
class MultNode;
class PrintNode;
class StatListNode;
struct VarNode;
class VectorNode;

struct VecMathVisitor
{
  virtual void visit(AddNode const& node) const = 0;
  virtual void visit(AssignNode const& node) const = 0;
  virtual void visit(DotProductNode const& node) const = 0;
  virtual void visit(IntNode const& node) const = 0;
  virtual void visit(MultNode const& node) const = 0;
  virtual void visit(PrintNode const& node) const = 0;
  virtual void visit(StatListNode const& node) const = 0;
  virtual void visit(VarNode const& node) const = 0;
  virtual void visit(VectorNode const& node) const = 0;
};

