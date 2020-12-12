#include "stack.h"
#include <stdlib.h>

Stack *create(void) {
    return malloc(sizeof(Stack));
}

Stack *push(Stack *top, int value) {
    Stack *new = malloc(sizeof(Stack));
    new->next = top;
    return new;
}

Stack *pop(Stack *top) {
    Stack *new = top->next;
    free(top);
    return new;
}

void free(Stack *top) {
    Stack *new = top;
    Stack *old;
    while (new != NULL) {
        old = new;
        new = new->next;
        free(old);
    }
}