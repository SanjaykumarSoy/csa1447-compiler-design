#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Symbol {
    char name[50];
    int value;
    struct Symbol* next;
} Symbol;

Symbol* table[TABLE_SIZE] = {NULL};

unsigned int hash(char* name) {
    unsigned int hash = 0;
    while (*name) hash = (hash << 5) + *name++;
    return hash % TABLE_SIZE;
}

void insert(char* name, int value) {
    unsigned int index = hash(name);
    Symbol* newSymbol = malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    newSymbol->value = value;
    newSymbol->next = table[index];
    table[index] = newSymbol;
}

Symbol* lookup(char* name) {
    unsigned int index = hash(name);
    Symbol* symbol = table[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) return symbol;
        symbol = symbol->next;
    }
    return NULL;
}

void delete(char* name) {
    unsigned int index = hash(name);
    Symbol* symbol = table[index];
    Symbol* prev = NULL;
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            if (prev) prev->next = symbol->next;
            else table[index] = symbol->next;
            free(symbol);
            return;
        }
        prev = symbol;
        symbol = symbol->next;
    }
}

int main() {
    insert("x", 10);
    Symbol* s = lookup("x");
    if (s) printf("Found: %s = %d\n", s->name, s->value);
    delete("x");
    return 0;
}
