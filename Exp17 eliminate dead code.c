#include <stdio.h>

int main() {
    int flag = 0; // This variable is not used anywhere

    // Some code that is never executed
    if (flag == 1) {
        printf("Flag is set.\n");
    } else {
        printf("Flag is not set.\n");
    }

    return 0;
}
