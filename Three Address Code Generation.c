#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateThreeAddressCode(char *expression) {
    char *token = strtok(expression, " ");
    char operands[2][10];
    char operator[10];
    int operandIndex = 0;
    int tempCount = 1;

    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            strcpy(operator, token);
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(operands[1], token);
                printf("t%d = %s %s %s\n", tempCount, operands[0], operator, operands[1]);
                sprintf(operands[0], "t%d", tempCount);
                tempCount++;
                operandIndex = 1;
            }

        } else {
            if (operandIndex < 2) {
                strcpy(operands[operandIndex], token);
                operandIndex++;
            }
        }
        token = strtok(NULL, " ");
    }
}
int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; 
    generateThreeAddressCode(expression);
    return 0;
}
