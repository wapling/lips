#include "Token.h"
#include "AssignNode.h"
#include "PrintNode.h"
#include "DotProductNode.h"
#include "MultNode.h"
#include "VarNode.h"
#include "AddNode.h"
#include "VecMathNode.h"
#include "ExprNode.h"
#include "VectorNode.h"
#include "IntNode.h"
#include "StatListNode.h"
#include "StatNode.h"

#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    // x = 3 + 4
    StatNodePtrs stats;

    Token plus(Token::PLUS, "+");

    ExprNodePtr a = std::make_shared<AddNode>(
      std::make_shared<IntNode>(3),
      plus, 
      std::make_shared<IntNode>(4));
   
    VarNodePtr x = std::make_shared<VarNode>(Token(Token::ID, "x"));
    StatNodePtr assign = std::make_shared<AssignNode>(
      x, Token(Token::ASSIGN, "="), a);
    
    stats.push_back(assign);


    // print x * [2, 3, 4]

    Token mult(Token::MULT, "*");

    ExprNodePtrs elements;
    elements.push_back(std::make_shared<IntNode>(2));
    elements.push_back(std::make_shared<IntNode>(3));
    elements.push_back(std::make_shared<IntNode>(4));
    ExprNodePtr v = std::make_shared<VectorNode>(Token(Token::VEC), elements);
    ExprNodePtr xref = std::make_shared<VarNode>(Token(Token::ID, "x"));
    ExprNodePtr pv = std::make_shared<MultNode>(xref, mult, v);
    StatNodePtr p = std::make_shared<PrintNode>(Token(Token::PRINT, "print"), pv);

    stats.push_back(p);
    
    StatListNode statlist(stats);
    statlist.print();
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}



