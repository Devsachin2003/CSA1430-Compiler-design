#include <stdio.h>
#include <stdlib.h>

// Structure to represent a quadruple
struct Quadruple {
    char op;
    char arg1;
    char arg2;
    char result;
};

// Function to generate target code from quadruples
void generateTargetCode(struct Quadruple quadruples[], int quadCount) {
    printf("Target Code Generation:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%c %c %c %c\n", quadruples[i].op, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }
}

int main() {
    // Example quadruples
    struct Quadruple quadruples[100];
    int quadCount = 0;

    // Example quadruple generation (you can modify this based on your requirements)
    quadruples[quadCount].op = '*';
    quadruples[quadCount].arg1 = '2';
    quadruples[quadCount].arg2 = '3';
    quadruples[quadCount].result = 't1';
    quadCount++;

    quadruples[quadCount].op = '+';
    quadruples[quadCount].arg1 = 't1';
    quadruples[quadCount].arg2 = '4';
    quadruples[quadCount].result = 't2';
    quadCount++;

    // Calling the function for target code generation
    generateTargetCode(quadruples, quadCount);

    return 0;
}
