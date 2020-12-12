#include "queue.h"
#include <stdlib.h>

Queue *create(int length) {
    Queue *new = malloc(sizeof(Queue));
    new->last = malloc(sizeof(Unit));
    new->last->prev = NULL;
    Unit *l = new->last;
    for (int i = 1; i < length; i++) {
        l->next = malloc(sizeof(Unit));
        l->next->prev = l;
        l = l->next;
        l->value = 0;
        l->next = NULL;
    }
    new->first = l;
    return new;
}

void update(Unit *unit, int value) {
    unit->value = value;
}

Queue *pop(Queue *q) {
    Unit *l = q->first;
    q->first = q->first->prev;
    free(l);
    return q;
}

Queue *push(Queue *q, int value) {
    Unit *new = malloc(sizeof(Unit));
    new->next = q->last;
    new->next->prev = new;
    new->prev = NULL;
    new->value = value;
    q->last = new;
    return q;
}

int length(Queue *q) {
    int i = 0;
    for (Unit *u = q->last; u != q->last; u = u->next) i++;
    return i;
}

void freeQueue(Queue *q) {
    Unit *l = q->first;
    while (l != NULL) {
        Unit *old = l;
        l = l->next;
        free(old);
    }
    free(q);
}