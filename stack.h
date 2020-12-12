#ifndef ALGNSTRUCTS_STACK_H
#define ALGNSTRUCTS_STACK_H

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

Stack *create(void);
Stack *push(Stack *top, int value);
Stack *pop(Stack *top);
void free(Stack *top);

#endif //ALGNSTRUCTS_STACK_H
