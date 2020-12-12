#include "list.h"
#include <stdlib.h>

List *createList(int length) {
    List *head = malloc(sizeof(List));
    head->value = 0;
    head->next = NULL;
    head->prev = NULL;
    List *l = head;
    for (int i = 1; i < length; i++) {
        l->next = malloc(sizeof(List));
        l->next->value = 0;
        l->next->next = NULL;
        l->next->prev = l;
        l = l->next;
    }
    return head;
}

List *push_back(List *lst, int value) {
    List *l = lst;
    for (; l->next != NULL; l = l->next);
    l->next = malloc(sizeof(List));
    l->next->prev = l;
    l->next->next = NULL;
    l->next->value = value;
    return lst;
}

List *push_front(List *lst, int value) {
    List *l = malloc(sizeof(List));
    l->prev = NULL;
    l->next = lst;
    l->prev = NULL;
    l->next->prev = l;
    return l;
}


List *searchList(List *lst, int value) {
    List *l = lst;
    for (; (l != NULL) || (l->value != value); l = l->next);
    return l;
}

List *deleteList(List *lst, int value) {
    List *l = searchList(lst, value);
    if (l == NULL)
        return lst;
    if (l == lst) {
        lst->next->prev = NULL;
        lst = lst->next;
        free(l);
        return lst;
    }
    l->prev->next = l->next;
    l->next->prev = l->prev;
    free(l);
    return lst;
}

void freeList(List *lst) {
    List *l = lst;
    while (l != NULL) {
        l = l->next;
        free(l->prev);
    }
}