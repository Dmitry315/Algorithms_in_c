#ifndef ALGNSTRUCTS_QUEUE_H
#define ALGNSTRUCTS_QUEUE_H

typedef struct Unit {
    int value;
    struct Unit *next, *prev;
} Unit;

typedef struct Queue {
    Unit *first, *last;
} Queue;

Queue *create(int length);
void update(Unit *unit, int value);
Queue *pop(Queue *q);
Queue *push(Queue *q, int value);
int length(Queue *q);
void freeQueue(Queue *q);

#endif //ALGNSTRUCTS_QUEUE_H
