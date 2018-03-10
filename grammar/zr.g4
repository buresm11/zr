grammar zr;

parse
: top_block EOF
;

top_block
 : (function_decl | global_statement)*
 ;

block
 : statement* 
 ;

 global_statement
 : variable_def ';'
 | assignment ';'
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

function_call
 : Identifier '(' (expression (',' expression)*)? ')'
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
 : Type_identifier Identifier (',' func_decl_arg_list)*
 ;

expression
 : '-' expression                           #unaryMinusExpression
 | '!' expression                           #notExpression
 | expression '*' expression                #multiplyExpression
 | expression '/' expression                #divideExpression
 | expression '%' expression                #modulusExpression
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
 | Number                                   #numberExpression
 | Bool                                     #boolExpression
 | Identifier '(' (expression (',' expression)*)? ')'                     #functionCallExpression
 | Identifier                               #identifierExpression
 | String                                   #stringExpression
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
PrintLn   : 'println';

Or       : '||';
And      : '&&';
Equals   : '==';
NEquals  : '!=';
GTEquals : '>=';
LTEquals : '<=';
Pow      : '^';
Excl     : '!';
GT       : '>';
LT       : '<';
Add      : '+';
Subtract : '-';
Multiply : '*';
Divide   : '/';
Modulus  : '%';
OBrace   : '{';
CBrace   : '}';
OBracket : '[';
CBracket : ']';
OParen   : '(';
CParen   : ')';
SColon   : ';';
Assign   : '=';
Comma    : ',';
QMark    : '?';
Colon    : ':';

Type_identifier
 : 'int'
 | 'bool'
 ;

Bool
 : 'true' 
 | 'false'
 ;

Number
 : Int
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