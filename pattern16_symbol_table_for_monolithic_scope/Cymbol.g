grammar Cymbol;

@deaders {
  #include <iostream>
}

@members {
  SymbolTable symtab;
}

compilationUnit[SymbolTable symtab]

@init {this.symtab = symtab;}
  : varDeclaration+
  ;

type returns [Type tsym]
@after {
  std::cout << "line " << $ctx.start.getLine()
            << ": ref " << $tsym.getName()
            << std::endl;
}
  : 'float' {$tsym = (Type)symtab.resolve("float");}
  | 'int'   {$tsym = (Type)symtab.resolve("int");}
  ;

varDeclaration
  : type ID ('=' expression)? ';'
    {
      std::cout << "line " << $ID.getLine()
                << ": def " << $ID.text()
                << std::endl;
      VariableSymbol vs($ID.text(), $type.tsym);
      symtab.define(vs);
    }
  ;

expression
  : primary ('+' primary)*
  ;

primary
  : ID
    {
      std::cout << "line " << $ID.getLine() 
                << ": ref to " << symtab.resolve($ID.text)
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



