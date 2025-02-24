#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, result;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &a);
    printf("Enter an operator (+, -, *, /, ^): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%lf", &b);

    switch (operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                printf("Error: Division by zero.\n");
                return 1;
            }
            break;
        case '^':
            result = pow(a, b);
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;
    }

    printf("Result: %.2lf\n", result);
    return 0;
}
