#ifndef ALGNSTRUCTS_QUEUE_H
#define ALGNSTRUCTS_QUEUE_H

typedef struct Unit {
    int value;
    struct Unit *next, *prev;
} Unit;

typedef struct Queue {
    Unit *first, *last;
} Queue;

Queue *createQueue(int length);
void updateQueue(Unit *unit, int value);
Queue *popQueue(Queue *q);
Queue *pushQueue(Queue *q, int value);
int lengthQueue(Queue *q);
void freeQueue(Queue *q);

#endif //ALGNSTRUCTS_QUEUE_H
