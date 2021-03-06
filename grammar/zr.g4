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
 | break_statement ';'
 ;

 break_statement
 : Break
 ;

 return_statement
 : Return expression?
 ;

assignment
 : Identifier '=' expression
 ;

 variable_def
 : Type_identifier Identifier
 ;

 global_variable_def
 : Type_identifier Identifier
 ;

function_call
 : Identifier '(' exprList? ')'  #identifierFunctionCall
 | Print '(' expression ')'      #printFunctionCall
 | Scan '(' ')'                  #scanFunctionCall
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
 : Def (Type_identifier | Void) Identifier '(' func_decl_arg_list? ')' block End
 ;

func_decl_arg_list
 : func_decl_arg  (',' func_decl_arg)*
 ;

 func_decl_arg
 : Type_identifier Identifier
 ;

expression
 : Identifier '(' exprList? ')'             #functionCallExpression 
 | Scan '(' ')' 							#scanCallExpression
 | '-' expression                           #unaryMinusExpression
 | '!' expression                           #notExpression
 | expression '*' expression                #multiplyExpression
 | expression '/' expression                #divideExpression
 | expression '+' expression                #addExpression
 | expression '-' expression                #subtractExpression
 | expression '>=' expression               #gtEqExpression
 | expression '<=' expression               #ltEqExpression
 | expression '>' expression                #gtExpression
 | expression '<' expression                #ltExpression
 | expression '==' expression               #eqExpression
 | expression '!=' expression               #notEqExpression
 | expression '&&' expression               #andExpression
 | expression '||' expression               #orExpression
 | Identifier                               #identifierExpression
 | (bool_lit | number)                      #literalExpression
 | '(' expression ')'						#paranthesisExpression
 ;

exprList 
 : expression (',' expression)* 
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
Break     : 'break';
While     : 'while';
To        : 'to';
Do        : 'do';
End       : 'end';
Print     : 'print';
Scan      : 'scan';
True      : 'true';
False     : 'false';
Void      : 'void';

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
Lparen 	 : '(';
Rparen   : ')';

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

