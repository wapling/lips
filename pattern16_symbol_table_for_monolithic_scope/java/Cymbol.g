grammar Cymbol;

@members {
  SymbolTable symtab;
}

compilationUnit[SymbolTable symtab]

@init { this.symtab = symtab; }
  : varDeclaration+ 
  ;

type returns [Type tsym]
@after {
  System.out.println("line " + $start.getLine() + ": ref " + $tsym.getName());
}
  : 'float' {$tsym = (Type)symtab.resolve("float");}
  | 'int'   {$tsym = (Type)symtab.resolve("int");}
  ;

varDeclaration
  : type ID ('=' expression)? ';'
    {
      System.out.println("line " + $ID.getLine() + ": def " + $ID.text);
      VariableSymbol vs = new VariableSymbol($ID.text, $type.tsym);
      symtab.define(vs);
    }
  ;

expression
    :   primary ('+' primary)*
    ;

primary
  : ID
    {
      System.out.println("line " + $ID.getLine() + ": ref to " + symtab.resolve($ID.text));
    }
  | INT
  | '(' expression ')'
  ;


ID  :   LETTER (LETTER | '0'..'9')*
    ;

fragment
LETTER  :   ('a'..'z' | 'A'..'Z')
    ;

INT :   '0'..'9'+
    ;

WS  :   (' '|'\r'|'\t'|'\n') -> skip 
    ;

SL_COMMENT
    :   '//' ~('\r'|'\n')* '\r'? '\n' -> skip 
    ;
