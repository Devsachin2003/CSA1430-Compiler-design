%{
#include <stdio.h>
int commentLineCount = 0;
%}

%%
"/*"            { commentLineCount++; while(strstr(yytext, "*/") == NULL) { yylex(); } }
"//".*          { commentLineCount++; }
\n              { /* Increment line count for single-line comments */ }

.|\n            { /* Ignore everything else */ }

%%

int main() {
    yylex();
    printf("Number of comment lines: %d\n", commentLineCount);
    return 0;
}
