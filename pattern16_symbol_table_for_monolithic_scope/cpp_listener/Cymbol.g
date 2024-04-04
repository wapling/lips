grammar Cymbol;

//@header {
//  #include "Symbol.h"
//  #include "SymbolTable.h"
//  #include "Type.h"
//  #include "VariableSymbol.h"
//
//  #include <iostream>
//  #include <memory>
//}

//@members {
//  SymbolTablePtr symtab_;
//}

compilationUnit //[SymbolTablePtr symtab]
//@init {this->symtab_ = symtab;}
  : varDeclaration+
  ;

type //returns [TypePtr tsym]
//@after {
//  std::cout << "line " << $ctx->start->getLine()
//            << ": ref " << $tsym->get_name()
//            << std::endl;
//}
  : 'float' //{$tsym = std::dynamic_pointer_cast<Type>(symtab_->resolve("float"));}
  | 'int'   //{$tsym = std::dynamic_pointer_cast<Type>(symtab_->resolve("int"));}
  ;

varDeclaration
  : type ID ('=' expression)? ';'
//    {
//      std::cout << "line " << $ID->getLine()
//                << ": def " << $ID->getText()
//                << std::endl;
//      SymbolPtr vs(std::make_shared<VariableSymbol>($ID->getText(), $type.tsym));
//      symtab_->define(vs);
//    }
  ;

expression
  : primary ('+' primary)*
  ;

primary
  : ID                  # primary_id
//    {
//      std::cout << "line " << $ID->getLine() 
//                << ": ref to " << *symtab_->resolve($ID->getText())
//                << std::endl;
//    }
  | INT                 # primary_int
  | '(' expression ')'  # primary_parens
  ;

//Lexer

ID  : LETTER (LETTER | '0'..'9')* ;

fragment
LETTER : ('a'..'z' | 'A'..'Z') ;

INT : '0'..'9'+ ;

WS  : (' '| '\r' | '\n' | '\t' ) {skip();}
    ;

SL_COMMENT
  : '//' ~('\r'|'\n')* 'r'? '\n' {skip();}
  ;



