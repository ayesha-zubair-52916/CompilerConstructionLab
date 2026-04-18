%{
#include <stdio.h>
%}

%option noyywrap

DIGIT           [0-9]
LETTER          [a-zA-Z]
ID              {LETTER}({LETTER}|{DIGIT})*
INT_LITERAL     {DIGIT}+
FLOAT_LITERAL   {DIGIT}+"."{DIGIT}+
STRING_LITERAL  \"[^"\n]*\"
CHAR_LITERAL    \'[^'\n]\'

%%

("auto"|"break"|"case"|"char"|"const")   { printf("Keyword: %s\n", yytext); }

{ID}            { printf("Identifier: %s\n", yytext); }
{INT_LITERAL}   { printf("Integer Literal: %s\n", yytext); }
{FLOAT_LITERAL} { printf("Float Literal: %s\n", yytext); }
{STRING_LITERAL} { printf("String Literal: %s\n", yytext); }
{CHAR_LITERAL}  { printf("Character Literal: %s\n", yytext); }

"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"   { printf("Operator: %s\n", yytext); }

";"             { printf("Semicolon\n"); }
","             { printf("Comma\n"); }
"("             { printf("Left Parenthesis\n"); }
")"             { printf("Right Parenthesis\n"); }
"{"             { printf("Left Brace\n"); }
"}"             { printf("Right Brace\n"); }

[ \t\n]+        ;   /* ignore whitespace */
.               { printf("Unknown token: %s\n", yytext); }

%%

int main() {
    printf("Enter code (Ctrl+Z then Enter to finish):\n");
    yylex();
    return 0;
}


