grammar Graphics;

file : command+; //file is one or more commands

command : 'line' 'from' point 'to' point ;

point : INT ',' INT ;

INT : '0'..'9'+ ;

WS : (' ' | '\t' | '\n' | '\r') {skip();} ;
