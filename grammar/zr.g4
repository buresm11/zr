grammar zr;

parse
: top_block EOF
;

top_block
 : (function_decl | global_statement )*
 ;

block
 : statement* 
 ;

 global_statement
 : global_variable_def ';'
 ;

statement
 : variable_def ';'
 | assignment ';'
 | function_call ';'
 | if_statement
 | while_statement
 | return_statement ';'
 ;

 return_statement
 : Return expression
 ;

assignment
 : Identifier '=' expression
 ;

 variable_def
 : Type_identifier Identifier ('=' expression)?
 ;

 global_variable_def
 : Type_identifier Identifier ('=' (bool_lit | number))?
 ;

function_call
 : Identifier '(' (expression (',' expression)*)? ')'  #identifierFunctionCall
 | Print '(' expression ')'                            #printFunctionCall
 | Scan '(' ')'                             		   #scanFunctionCall
 ;

if_statement
 : if_stat else_if_stat* else_stat? End
 ;

if_stat
 : If expression Do block
 ;

else_if_stat
 : Else If expression Do block
 ;

else_stat
 : Else Do block
 ;

 while_statement
 : While expression Do block End
 ;

function_decl
 : Def Type_identifier Identifier '(' func_decl_arg_list? ')' block End
 ;

func_decl_arg_list
 : func_decl_arg  (',' func_decl_arg)*
 ;

 func_decl_arg
 : Type_identifier Identifier
 ;


 expression
 : expression binOp expression 				#binaryExpression
 | unOp expression 							#unaryExpression
 | Identifier '(' (expression (',' expression)*)? ')'                     #functionCallExpression
 | Scan '(' ')' 							#scanCallExpression
 | Identifier                               #identifierExpression
 | (bool_lit | number)                      #literalExpression	
 ;		

unOp
:	Excl
|	Minus 
;

binOp
:	Or
|   And
|	Equals
|	NEquals
|	GTEquals
|	LTEquals
|	Gt
|	Lt 
|	Add
|	Minus
|	Multiply
|	Divide
;

bool_lit
: (True | False)
;

number
: Integer
;

Integer
: Int
;

Def       : 'def';
If        : 'if';
Else      : 'else';
Return    : 'return';
While     : 'while';
To        : 'to';
Do        : 'do';
End       : 'end';
Print     : 'print';
Scan      : 'scan';
True      : 'true';
False     : 'false';

Or       : '||';
And      : '&&';
Equals   : '==';
NEquals  : '!=';
GTEquals : '>=';
LTEquals : '<=';
Excl     : '!';
Gt       : '>';
Lt       : '<';
Add      : '+';
Minus	 : '-';
Multiply : '*';
Divide   : '/';


Type_identifier
 : 'int'
 | 'bool'
 ;

Identifier
 : [a-zA-Z_] [a-zA-Z_0-9]*
 ;

String
 : ["] (~["\r\n] | '\\\\' | '\\"')* ["]
 | ['] (~['\r\n] | '\\\\' | '\\\'')* [']
 ;

Comment
 : ('//' ~[\r\n]* | '/*' .*? '*/') -> skip
 ;

 Space
 : [ \t\r\n\u000C] -> skip
 ;

fragment Int
 : [1-9] Digit*
 | '0'
 ;
  
fragment Digit 
 : [0-9]
 ;

