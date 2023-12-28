grammar VecMath;

statlist : stat+ ;

stat : ID '=' expr
     | 'print' expr
     ;

expr : multexpr ('+' multexpr)* ;

multexpr : primary (('*' | '.') primary)* ;

primary : INT
        | ID
        | '[' expr (',' expr)* ']'
        ;

ID  : 'a'..'z'+ ;
INT : '0'..'9'+ ;
WS  : (' '|'\r'|'\t'|'\n')+ {skip();} ;
 
