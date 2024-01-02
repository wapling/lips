tree grammar Printer;
options {
  tokenVocab=VecMath;       //use token vocabulary from VecMath.g
  ASTLabelType=CommonTree;  //use CommonTree
}

@headers {
#include <iostream>
#include <string>
}

@members {
  void print(std::string const& s)
  {
    std::cout << s;
  }
}

prog: stat+ ;

stat: ^('=' ID  {print($ID.text+" = ");} expr) {print("\n");}
    | ^('print' {print("print ");}       expr) {print("\n");}
    ;

expr: ^('+' expr {print("+");} expr)
    | ^('*' expr {print("*");} expr)
    | ^('.' expr {print(".");} expr)
    | ^(VEC {print("[");} expr ({print(", ");} expr)* {print("]");}
    | INT {print($INT.text);}
    | ID  {print($ID.text);}
    ;


