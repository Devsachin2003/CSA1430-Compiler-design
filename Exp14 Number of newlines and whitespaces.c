#include <stdio.h>

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int whitespace_count = 0;
    int newline_count = 0;
    int i = 0;

    while (input[i] != '\0') {
        if (input[i] == ' ') {
            whitespace_count++;
        } else if (input[i] == '\n') {
            newline_count++;
        }
        i++;
    }

    printf("Number of whitespaces: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);

    return 0;
}
