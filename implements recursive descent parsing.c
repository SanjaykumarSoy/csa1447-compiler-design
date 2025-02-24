#include <stdio.h>
#include <ctype.h>
const char *input;
char lookahead;
void nextChar() {
    lookahead = *input++;
}
void expr();
void term();
void factor();
void expr() {
    term();
    while (lookahead == '+' || lookahead == '-') {
        nextChar();
        term();
    }
}
void term() {
    factor();
    while (lookahead == '*' || lookahead == '/') {
        nextChar();
        factor();
    }
}

void factor() {
    if (isdigit(lookahead)) {
        nextChar();
    } else if (lookahead == '(') {
        nextChar();
        expr();
        if (lookahead == ')') nextChar();
    }
}

int main() {
    input = "3+(2*5)";
    nextChar();
    expr();
    if (lookahead == '\0') {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed!\n");
    }
    return 0;
}
