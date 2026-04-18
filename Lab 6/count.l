%{
#include <stdio.h>

int keyword_count = 0;
int identifier_count = 0;
int operator_count = 0;
int numeric_count = 0;
%}

%option noyywrap

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
INT     {DIGIT}+
FLOAT   {DIGIT}+"."{DIGIT}+

%%

(auto|break|case|char|const|int|float|double|if|else|while|for|return)  { keyword_count++; }

{FLOAT}   { numeric_count++; }

{INT}     { numeric_count++; }

{ID}      { identifier_count++; }

(==|!=|<=|>=|=|\+|\-|\*|\/|%)   { operator_count++; }

[ \t\n]+   ;

.         ;

%%

int main()
{
    printf("Enter code (Ctrl+Z then Enter to finish):\n");

    yylex();

    printf("\nKeywords: %d\n", keyword_count);
    printf("Identifiers: %d\n", identifier_count);
    printf("Operators: %d\n", operator_count);
    printf("Numeric literals: %d\n", numeric_count);

    return 0;
}