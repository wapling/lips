grammar VecMath;

prog: stat+ ;
stat: ID '=' expr  # stat_equal // -> ^('=' ID expr)
    | 'print' expr # stat_print // -> ('print' expr)
    ;

expr: multExpr ('+' multExpr)* ;

multExpr: primary (('*'|'.') primary)* ;

primary : INT                       # primary_int
        | ID                        # primary_id
        | '[' expr (',' expr)* ']'  # primary_vec    // -> ^(VEC expr+)
        ;

ID  : 'a'..'z'+ ;
INT : '0'..'9'+ ;
WS  : (' '|'\r'|'\n'|'\t')+ {skip();} ;

