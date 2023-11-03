#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;

    // Common subexpression elimination
    int common = a * b;

    int result1 = 4 * common;
    int result2 = 2 * common;

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}
