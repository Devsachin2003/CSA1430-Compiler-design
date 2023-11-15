%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct WordCount {
    char word[50];
    int count;
};

struct WordCount wordList[MAX_WORDS];
int numWords = 0;
%}

%%
[a-zA-Z]+ {
    int found = 0;
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordList[i].word, yytext) == 0) {
            found = 1;
            wordList[i].count++;
            break;
        }
    }
    if (!found) {
        if (numWords < MAX_WORDS) {
            strcpy(wordList[numWords].word, yytext);
            wordList[numWords].count = 1;
            numWords++;
        } else {
            fprintf(stderr, "Too many unique words. Increase MAX_WORDS.\n");
            exit(EXIT_FAILURE);
        }
    }
}

.|\n { /* Ignore everything else */ }

%%

int main() {
    yylex();

    printf("Word Frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return 0;
}
