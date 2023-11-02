#include <stdio.h>
#include <stdlib.h>

// Structure to represent a triple
struct Triple {
    char op;
    char arg1;
    char arg2;
};

// Function to print a triple
void printTriple(struct Triple t) {
    printf("<%c, %c, %c>\n", t.op, t.arg1, t.arg2);
}

int main() {
    struct Triple triples[100]; // Array to store triples
    int tripleCount = 0; // Keep track of the number of triples

    // Example expression: a = b + c * d

    // Triple 1: Multiply c and d
    triples[tripleCount].op = '*';
    triples[tripleCount].arg1 = 'c';
    triples[tripleCount].arg2 = 'd';
    tripleCount++;

    // Triple 2: Add b and the result of the previous multiplication
    triples[tripleCount].op = '+';
    triples[tripleCount].arg1 = 'b';
    triples[tripleCount].arg2 = triples[tripleCount - 1].arg1; // Result from Triple 1
    tripleCount++;

    // Triple 3: Store the result in a
    triples[tripleCount].op = '=';
    triples[tripleCount].arg1 = 'a';
    triples[tripleCount].arg2 = triples[tripleCount - 1].arg1; // Result from Triple 2
    tripleCount++;

    // Printing the triples
    for (int i = 0; i < tripleCount; i++) {
        printf("Triple %d: ", i + 1);
        printTriple(triples[i]);
    }

    return 0;
}
