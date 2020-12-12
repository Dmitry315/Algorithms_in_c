#ifndef ALGNSTRUCTS_STACK_H
#define ALGNSTRUCTS_STACK_H

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

Stack *createStack(int length);
void updateStack(Stack *unit, int value);
Stack *pushStack(Stack *top, int value);
Stack *popStack(Stack *top);
int heightStack(Stack *top);
void freeStack(Stack *top);

#endif //ALGNSTRUCTS_STACK_H
