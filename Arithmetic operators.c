#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 100
void validate_operator(char *input) {
    if (strcmp(input, "+") == 0 || strcmp(input, "-") == 0 || 
        strcmp(input, "*") == 0 || strcmp(input, "/") == 0) {
        printf("Valid operator: %s\n", input);
    } else {
        printf("Invalid operator: %s\n", input);
    }
}
int main() {
    char input[MAX_LEN];
    printf("Enter an operator: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    validate_operator(input);
    return 0;
}
