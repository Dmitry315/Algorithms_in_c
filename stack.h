#ifndef ALGNSTRUCTS_STACK_H
#define ALGNSTRUCTS_STACK_H

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

Stack *createStack(int length);
void update(Stack *unit, int value);
Stack *push(Stack *top, int value);
Stack *pop(Stack *top);
int height(Stack *top);
void freeStack(Stack *top);

#endif //ALGNSTRUCTS_STACK_H
