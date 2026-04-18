%{
#include <stdio.h>
%}

%%
[a-zA-Z]+   { printf("WORD: %s\n", yytext); }
.           { /* Ignore all other characters */ }
%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    yy_scan_string(argv[1]);  // Set input string for Flex
    yylex();  // Perform tokenization

    return 0;
}
