#include "Token.h"
#include "Ast.h"
#include "AddNode.h"
#include "IntNode.h"
#include "VectorNode.h"

#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    Token plus(PLUS, "+");
    Token one(INT, "1");
    Token two(INT, "2");
    AstPtr root(std::make_shared<AddNode>(
      std::make_shared<IntNode>(one), plus, std::make_shared<IntNode>(two)));
    std::cout << root->to_string_tree() << std::endl;
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}



