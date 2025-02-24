#include <stdio.h>
int main() {
    int a = 5, b = 10, c = 15;
    int result1, result2;
    int common = a * b + c;
    result1 = common;
    result2 = common * 2;
    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    return 0;
}
