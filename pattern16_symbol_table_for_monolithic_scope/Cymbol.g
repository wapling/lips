grammar Cymbol;

@header {
  #include "Symbol.h"
  #include "SymbolTable.h"
  #include "Type.h"
  #include "VariableSymbol.h"

  #include <iostream>
  #include <memory>
}

@members {
  SymbolTablePtr symtab;
}

compilationUnit[SymbolTablePtr symtab]

@init {this->symtab = symtab;}
  : varDeclaration+
  ;

type returns [TypePtr tsym]
@after {
  std::cout << "line " << $ctx->start->getLine()
            << ": ref " << $tsym->get_name()
            << std::endl;
}
  : 'float' {$tsym = std::dynamic_pointer_cast<Type>(symtab->resolve("float"));}
  | 'int'   {$tsym = std::dynamic_pointer_cast<Type>(symtab->resolve("int"));}
  ;

varDeclaration
  : type ID ('=' expression)? ';'
    {
      std::cout << "line " << $ID->getLine()
                << ": def " << $ID->getText()
                << std::endl;
      SymbolPtr vs(std::make_shared<VariableSymbol>($ID->getText(), $type.tsym));
      symtab->define(vs);
    }
  ;

expression
  : primary ('+' primary)*
  ;

primary
  : ID
    {
      std::cout << "line " << $ID->getLine() 
                << ": ref to " << symtab->resolve($ID->getText())
                << std::endl;
    }
  | INT
  | '(' expression ')'
  ;

//Lexer

ID  : LETTER (LETTER | '0'..'9')* ;

fragment
LETTER : ('a'..'z' | 'A'..'Z') ;

INT : '0'..'9'+ ;

SL_COMMENT
  : '//' ~('\r'|'\n')* 'r'? '\n' {skip();}
  ;



