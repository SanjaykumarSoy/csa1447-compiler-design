#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int isValidGrammar(const char *str) {
    int length = strlen(str);
    if (length == 0) return 0;

   
    if (!isupper(str[0])) return 0;

    if (str[length - 1] != '.' && str[length - 1] != '?' && str[length - 1] != '!') return 0;

    for (int i = 1; i < length - 1; i++) {
        if (!isalnum(str[i]) && str[i] != ' ' && str[i] != ',') return 0;
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a sentence: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    if (isValidGrammar(input)) {
        printf("The sentence is grammatically correct.\n");
    } else {
        printf("The sentence is not grammatically correct.\n");
    }

    return 0;
}
