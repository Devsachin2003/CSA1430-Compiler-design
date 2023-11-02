#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isComment(char *line) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        if (line[i] == '/' && line[i + 1] == '/') {
            return true;
        }
        if (line[i] == '/' && line[i + 1] == '*') {
            return true;
        }
    }
    return false;
}

int main() {
    FILE *fp;
    char ch, file_name[25], line[100];

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (isComment(line)) {
            printf("The line is a comment: %s", line);
        } else {
            printf("The line is not a comment: %s", line);
        }
    }

    fclose(fp);
    return 0;
}
