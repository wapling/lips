grammar VecMathAST;
options {output-AST;}
tokens {VEC;}

statlist : stat+ ;

stat : ID '=' expr  -> ^('=' ID expr)
     | 'print' expr -> ^('print' expr)
     ;

expr : multexpr ('+'^ multexpr)* ;

multexpr : primary (('*'^ | '.'^) primary)* ;

primary : INT
        | ID
        | '[' expr (',' expr)* ']' -> ^(VEC expr+)
        ;

ID  : 'a'..'z'+ ;
INT : '0'..'9'+ ;
WS  : (' '|'\r'|'\t'|'\n')+ {skip();} ;
 
