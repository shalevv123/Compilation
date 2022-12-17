%{

/* Declarations section */
#include <stdio.h>
#include "Node.hpp"
#include "parser.tab.hpp"
#include "hw3_output.hpp"
%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([\t\n\r ])

%%
void                                                    return VOID;
int                                                     return INT;
byte                                                    return BYTE;
b                                                       return B;
bool                                                    return BOOL;
and                                                     return AND;
or                                                      return OR;
not                                                     return NOT;
true                                                    return TRUE;
false                                                   return FALSE;
return                                                  return RETURN;
if                                                      return IF;
else                                                    return ELSE;
while                                                   return WHILE;
break                                                   return BREAK;
continue                                                return CONTINUE;
;                                                       return SC;
,                                                       return COMMA;
\(                                                      return LPAREN;
\)                                                      return RPAREN;
\{                                                      return LBRACE;
\}                                                      return RBRACE;
=                                                       return ASSIGN;
[<>]=?                                                  {yylval = new Relop(yytext);
                                                         return RELOP;
                                                        }
!=|==                                                   {yylval = new Equal(yytext);
                                                         return EQUAL;
                                                        }
[\+\-]                                                  {yylval = new PlusMinus(yytext);
                                                         return PLUS_MINUS;
                                                        }
[/\*]                                                   {yylval = new MulDiv(yytext);
                                                         return MUL_DIV;
                                                        }
\/\/[^\n\r]*[\r|\n|\r\n]?                               ;
{letter}({letter}|{digit})*                             {yylval = new Id(yytext); 
                                                         return ID;
                                                        }      
0|([1-9]{digit}*)		                                {yylval = new Num(yytext);
                                                         return NUM;
                                                        }     
\"([^\n\r\\\"]|\\.)*\"                                  {yylval = new String(yytext);
                                                         return STRING;}
{whitespace}                                            ;
.                                                       {output::errorLex(yylineno); exit(0);}
%%

