grammar Cymbol;

compilationUnit
//@init { this.symtab = symtab; }
  : varDeclaration+ 
  ;

type //returns [Type tsym]
//@after {
//  System.out.println("line " + $start.getLine() + ": ref " + $tsym.getName());
//}
  : 'float' //{$tsym = (Type)symtab.resolve("float");}
  | 'int'   //{$tsym = (Type)symtab.resolve("int");}
  ;

varDeclaration
  : type ID ('=' expression)? ';'
//    {
//      System.out.println("line " + $ID.getLine() + ": def " + $ID.text);
//      VariableSymbol vs = new VariableSymbol($ID.text, $type.tsym);
//      symtab.define(vs);
//    }
  ;

expression
    :   primary ('+' primary)*
    ;

primary
  : ID                  # primary_id
//    {
//      System.out.println("line " + $ID.getLine() + ": ref to " + symtab.resolve($ID.text));
//    }
  | INT                 # primary_int
  | '(' expression ')'  # primary_parens
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
