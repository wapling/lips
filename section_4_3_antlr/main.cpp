#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "antlr4-common.h"
#include "CharStream.h"
#include "CommonTokenStream.h"
#include "ANTLRFileStream.h"
#include "ANTLRInputStream.h"

#include "GraphicsLexer.h"
#include "GraphicsParser.h"

using namespace antlr4;

int main(int argc, char* argv[])
{
  try
  {
  
    if (argc > 2)
      throw std::runtime_error("Too many arguments");

    std::unique_ptr<CharStream> input = 
      (argc > 1) ? std::make_unique<ANTLRFileStream>(ANTLRFileStream(argv[1]))
                 : std::make_unique<ANTLRInputStream>(ANTLRInputStream(std::cin));

    GraphicsLexer lex(input.get());
    CommonTokenStream tokens(&lex);
    GraphicsParser parser(&tokens);
    parser.file();

  }
  catch (std::exception const& ex)
  {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
  }
}



