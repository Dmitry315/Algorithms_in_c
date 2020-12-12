#ifndef ALGNSTRUCTS_LIST_H
#define ALGNSTRUCTS_LIST_H

typedef struct List {
    int value;
    struct List *next, *prev;
} List;

List *createList(int length);
List *push_front(List *lst, int value);
List *push_back(List *lst, int value);
List *search(List *lst, int value);
List *delete(List *lst, int value);
void free(List *lst);

#endif //ALGNSTRUCTS_LIST_H
