grammar Printer;

//options {
//  tokenVocab=VecMath;
//}

prog: stat+ ;

stat
  : (ID '=' expr)                 # stat_equals //{print($ID.text+" = ");} {print("\n");}
  | ('print' expr)                # stat_print  //{print("print ");} {print("\n");}
  ;


expr
  : multExpr ('+' multExpr)*                    //{print("+");}
  ;

multExpr
  : primary (('*'|'.') primary)*                //{print("*");} or {print(".");}
  ;

primary
    :   INT                       # primary_int //{print($INT.text);}
    |   ID                        # primary_id  //{print($ID.text);}
    |   '[' expr (',' expr)* ']'  # primary_vec //{print("[");} ({print(", ");} )* {print("]");}
    ;

ID  : 'a'..'z'+ ;
INT : '0'..'9'+ ;
WS  : (' '|'\r'|'\n'|'\t')+ {skip();} ;
