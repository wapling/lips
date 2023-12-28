#include "Token.h"
#include "Ast.h"

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
    Ast root(plus);
    root.add_child(one);
    root.add_child(two);
    std::cout << "1+2 tree: " << root.to_string_tree() << std::endl;

    Ast list;
    list.add_child(Ast(one));
    list.add_child(Ast(two));
    std::cout << "1 and 2 in list: " << list.to_string_tree() << std::endl;
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}



