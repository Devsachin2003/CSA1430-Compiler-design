#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '>' || ch == '<' || ch == '=' || ch == '!') {
        return true;
    }
    return false;
}

bool isKeyword(char* token) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", 
                            "double", "else", "enum", "extern", "float", "for", "goto", "if", 
                            "int", "long", "register", "return", "short", "signed", "sizeof", "static", 
                            "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int i;
    for (i = 0; i < 32; i++) {
        if (strcmp(keywords[i], token) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    FILE *fp;
    char file_name[25], token[50];
    int i, j = 0;

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", token) != EOF) {
        if (isalnum(token[0])) {
            for (i = 0; i < strlen(token); i++) {
                if (!isalnum(token[i])) {
                    printf("%s is not a valid identifier or keyword\n", token);
                    break;
                }
            }
            if (i == strlen(token)) {
                if (isKeyword(token))
                    printf("%s is a keyword\n", token);
                else
                    printf("%s is an identifier\n", token);
            }
        }
        else if (isdigit(token[0])) {
            for (i = 0; i < strlen(token); i++) {
                if (!isdigit(token[i])) {
                    printf("%s is not a valid constant\n", token);
                    break;
                }
            }
            if (i == strlen(token)) {
                printf("%s is a constant\n", token);
            }
        }
        else if (isOperator(token[0])) {
            if (strlen(token) == 1) {
                printf("%s is an operator\n", token);
            } else {
                printf("%s is not a valid operator\n", token);
            }
        }
    }

    fclose(fp);
    return 0;
}
