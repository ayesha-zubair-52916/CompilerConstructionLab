%option noyywrap
%{
#include <stdio.h>

int line = 1;
int start = 1;   // to print line number once per line
%}

%option noyywrap
%x COMMENT

%%

"//".*              ;                       /* remove single line comment */

"/*"                { BEGIN(COMMENT); }     /* start multi-line comment */

<COMMENT>[^*\n]*    ;                       /* ignore text */

<COMMENT>"*"+[^*/\n]* ;

<COMMENT>\n         ;                       /* ignore newline in comment */

<COMMENT>"*"+"/"    { BEGIN(INITIAL); }     /* end comment */

\n                  {
                        printf("\n");
                        line++;
                        start = 1;
                    }

.                   {
                        if(start){
                            printf("Line %d: ", line);
                            start = 0;
                        }
                        printf("%s", yytext);
                    }

%%

int main()
{
	printf("Enter code (Ctrl+Z then Enter to stop):\n");
    yylex();
    return 0;
}