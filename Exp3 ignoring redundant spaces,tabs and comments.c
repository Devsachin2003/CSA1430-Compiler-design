#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE *fp;
    char filename[100];
    char c;
    bool in_comment = false;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == '/') {
            c = fgetc(fp);
            if (c == '/') {
                while ((c = fgetc(fp)) != '\n') {}
            } else if (c == '*') {
                in_comment = true;
                while (in_comment) {
                    while ((c = fgetc(fp)) != '*') {
                        if (c == EOF) {
                            printf("Error: Unterminated comment\n");
                            return -1;
                        }
                    }
                    c = fgetc(fp);
                    if (c == '/') {
                        in_comment = false;
                    }
                }
            } else {
                printf("/");
                printf("%c", c);
            }
        } else if (c == ' ' || c == '\t') {
            while (c == ' ' || c == '\t') {
                c = fgetc(fp);
            }
            printf(" ");
            printf("%c", c);
        } else {
            printf("%c", c);
        }
    }

    fclose(fp);
    return 0;
}
