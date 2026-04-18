%option noyywrap
%{
#include <stdio.h>
%}

%%

(\+|\-|\*|\/|%)              { printf("Arithmetic Operator: %s\n", yytext); }

(<=|>=|==|!=|<|>)           { printf("Relational Operator: %s\n", yytext); }

(\+=|\-=|\*=|\/=|%=|\+\+|\-\-|=)   { printf("Assignment Operator: %s\n", yytext); }

[ \t\n]+                    ;     /* ignore spaces */

.                           ;     /* ignore other characters */

%%

int main()
{
    printf("Enter operators (Ctrl+Z then Enter to stop):\n");
    yylex();
    return 0;
}