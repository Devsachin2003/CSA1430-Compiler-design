#include <stdio.h>
#include <string.h>

// Structure to represent a production rule in a grammar
typedef struct {
  char lhs;
  char rhs[100];
} ProductionRule;

// Function to check whether a given string can be parsed by a given grammar
int canParse(ProductionRule *rules, int numRules, char *str) {
  // If the string is empty, then it can be parsed by the grammar
  if (strlen(str) == 0) {
    return 1;
  }

  // Try to parse the string using each production rule in the grammar
  for (int i = 0; i < numRules; i++) {
    // If the LHS of the production rule matches the first character of the string,
    // then try to parse the rest of the string using the RHS of the production rule
    if (rules[i].lhs == str[0]) {
      if (canParse(rules, numRules, str + 1)) {
        return 1;
      }
    }
  }

  // If no production rule can be used to parse the string, then it cannot be parsed by the grammar
  return 0;
}

// Function to check whether a given grammar is ambiguous
int isAmbiguous(ProductionRule *rules, int numRules) {
  // If there exists a string that can be parsed by more than one production rule, then the grammar is ambiguous
  for (int i = 0; i < numRules; i++) {
    for (int j = i + 1; j < numRules; j++) {
      char str[100];
      strcpy(str, rules[i].rhs);
      strcat(str, rules[j].rhs);

      if (canParse(rules, numRules, str)) {
        return 1;
      }
    }
  }

  // If there is no string that can be parsed by more than one production rule, then the grammar is unambiguous
  return 0;
}

int main() {
  // Input the number of production rules in the grammar
  int numRules;
  printf("Enter the number of production rules in the grammar: ");
  scanf("%d", &numRules);

  // Allocate memory for the production rules
  ProductionRule rules[numRules];

  // Input the production rules
  for (int i = 0; i < numRules; i++) {
    printf("Enter production rule %d: ", i + 1);
    scanf("%c -> %s", &rules[i].lhs, rules[i].rhs);
  }

  // Check whether the grammar is ambiguous
  if (isAmbiguous(rules, numRules)) {
    printf("The grammar is ambiguous.\n");
  } else {
    printf("The grammar is unambiguous.\n");
  }

  return 0;
}
