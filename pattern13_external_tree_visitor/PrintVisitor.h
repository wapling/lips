#pragma once

#include "VecMathVisitor.h"

#include <iostream>

struct PrintVisitor : VecMathVisitor
{
  void visit(AddNode const& node) const override
	{
    node.get_left()->visit(*this);
    std::cout << " + ";
    node.get_right()->visit(*this);
	}

  void visit(AssignNode const& node) const override
	{
    node.get_id()->visit(*this);
    std::cout << " = ";
    node.get_value()->visit(*this);
    std::cout << '\n';
	}

  void visit(DotProductNode const& node) const override
	{
    node.get_left()->visit(*this);
    std::cout << " . ";
    node.get_right()->visit(*this);
	}

  void visit(IntNode const& node) const override
	{
    std::cout << node.to_string();
	}

  void visit(MultNode const& node) const override
	{
    node.get_left()->visit(*this);
    std::cout << " * ";
    node.get_right()->visit(*this);
	}

  void visit(PrintNode const& node) const override
	{
    std::cout << "print ";
    node.get_value()->visit(*this);
    std::cout << '\n';
	}

  void visit(StatListNode const& node) const override
	{
    for (auto const& element : node.get_elements())
      element->visit(*this);
	}

  void visit(VarNode const& node) const override
	{
    std::cout << node.to_string();
	}

  void visit(VectorNode const& node) const override
	{
    std::cout << '[';
    bool first_time = true;
    for (auto const& element : node.get_elements())
    {
      if (first_time)
        first_time = false;
      else
        std::cout << ' ';
      element->visit(*this);
    }
    std::cout << ']';
	}

};

