%{
#include <stdio.h>

int macroCount = 0;
int headerCount = 0;
%}

%%
^#define        { macroCount++; }
^#include       { headerCount++; }
.|\n            { /* Ignore everything else */ }

%%

int main() {
    yylex();
    printf("Number of Macros defined: %d\n", macroCount);
    printf("Number of Header files included: %d\n", headerCount);

    return 0;
}
