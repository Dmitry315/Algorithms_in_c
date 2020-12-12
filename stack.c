#include "stack.h"
#include <stdlib.h>

Stack *createStack(int length) {
    Stack *new = malloc(sizeof(Stack));
    new->next = NULL;
    new->value = 0;
    Stack *l = new;
    for (int i = 1; i < length; i++) {
        new->next = malloc(sizeof(Stack));
        new = new->next;
        new->value = 0;
        new->next = NULL;
    }
    return new;
}

void updateStack(Stack *unit, int value) {
    unit->value = value;
}

Stack *pushStack(Stack *top, int value) {
    Stack *new = malloc(sizeof(Stack));
    updateStack(new, value);
    new->next = top;
    return new;
}

Stack *popStack(Stack *top) {
    Stack *new = top->next;
    free(top);
    return new;
}

int heightStack(Stack *top) {
    int i = 0;
    for (Stack *new = top;new != NULL; new = new->next) i++;
    return i;
}

void freeStack(Stack *top) {
    Stack *new = top;
    Stack *old;
    while (new != NULL) {
        old = new;
        new = new->next;
        free(old);
    }
}