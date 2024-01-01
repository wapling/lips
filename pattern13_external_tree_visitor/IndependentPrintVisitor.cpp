#include "IndependentPrintVisitor.h"

#include "AddNode.h"
#include "AssignNode.h"
#include "DotProductNode.h"
#include "ExprNode.h"
#include "IntNode.h"
#include "MultNode.h"
#include "PrintNode.h"
#include "StatListNode.h"
#include "StatNode.h"
#include "VarNode.h"
#include "VectorNode.h"

#include <iostream>
#include <sstream>

namespace
{

void print(ExprNodePtr node)
{
  IndependentPrintVisitor::print(*node);
}

void print(StatNodePtr node)
{
  IndependentPrintVisitor::print(*node);
}

void print(AddNode const& node)
{
  print(node.get_left());
  std::cout << " + ";
  print(node.get_right());
}

void print(AssignNode const& node)
{
  print(node.get_id());
  std::cout << " = ";
  print(node.get_value());
  std::cout << '\n';
}

void print(DotProductNode const& node)
{
  print(node.get_left());
  std::cout << " . ";
  print(node.get_right());
}

void print(IntNode const& node)
{
  std::cout << node.to_string();
}

void print(MultNode const& node)
{
  print(node.get_left());
  std::cout << " * ";
  print(node.get_right());
}

void print(PrintNode const& node)
{
  std::cout << "print ";
  print(node.get_value());
  std::cout << '\n';
}

void print(StatListNode const& node)
{
  for (auto const& element : node.get_elements())
    print(element);
}

void print(VarNode const& node)
{
  std::cout << node.to_string();
}

void print(VectorNode const& node)
{
  std::cout << '[';
  bool first_time = true;
  for (auto const& element : node.get_elements())
  {
    if (first_time)
      first_time = false;
    else
      std::cout << ' ';
    print(element);
  }
  std::cout << ']';
}

} // anonymous namespace

namespace IndependentPrintVisitor
{

void print(VecMathNode const& node)
{
  switch (node.token_.get_type())
  {
    case Token::PLUS      :  ::print(static_cast<AddNode const&>(node)); return;
    case Token::ASSIGN    :  ::print(static_cast<AssignNode const&>(node)); return;
    case Token::DOT       :  ::print(static_cast<DotProductNode const&>(node)); return;
    case Token::INT       :  ::print(static_cast<IntNode const&>(node)); return;
    case Token::MULT      :  ::print(static_cast<MultNode const&>(node)); return;
    case Token::PRINT     :  ::print(static_cast<PrintNode const&>(node)); return;
    case Token::STAT_LIST :  ::print(static_cast<StatListNode const&>(node)); return;
    case Token::ID        :  ::print(static_cast<VarNode const&>(node)); return;
    case Token::VEC       :  ::print(static_cast<VectorNode const&>(node)); return;
    default:
    {
      std::ostringstream oss;
      oss << "Node type " << node.token_.get_type()
          << " not handled\n.Text: '" << node.token_.get_text() << "'";
      throw UnknownNodeTypeException(oss.str());
    }
  }
}

} // namespace IndependentPrintVisitor
