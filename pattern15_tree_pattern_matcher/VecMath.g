grammar VecMath;
options {output=AST;} //create ASTs
tokens { VEC }       //imaginary token for vector literal

prog: stat+ ;
stat: ID '=' expr -> ^('=' ID expr)
    | 'print' expr -> ^('print' expr)
    ;

expr: multExpr ('+'^ multExpr)* ;

multExpr: primary (('*'^|'.'^) primary)* ;

primary : INT
        | ID
        | '[' expr (',' expr)* ']' -> ^(VEC expr+)
        ;

ID  : 'a'..'z'+ ;
INT : '0'..'9'+ ;
WS  : (' '|'\r'|'\n'|'\t')+ {skip();} ]

