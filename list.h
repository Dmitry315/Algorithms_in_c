#ifndef ALGNSTRUCTS_LIST_H
#define ALGNSTRUCTS_LIST_H

typedef struct List {
    int value;
    struct List *next, *prev;
} List;

List *createList(int length);
List *push_front(List *lst, int value);
List *push_back(List *lst, int value);
List *searchList(List *lst, int value);
List *deleteList(List *lst, int value);
void freeList(List *lst);

#endif //ALGNSTRUCTS_LIST_H
