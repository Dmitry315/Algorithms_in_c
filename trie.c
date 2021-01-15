#include "trie.h"
#include <stdlib.h>
#include <string.h>
#define alph_size 28
#define def_val -1
typedef long long t_type;

typedef struct Node Node;
struct Node{
    Node *next[alph_size];
    char *stored;
    char have_child;
    t_type value;
};

Node *new_Node(void){
    Node *n = malloc(sizeof(Node));
    for (int i = 0; i < alph_size; i++)
        n->next[i] = NULL;
    n->stored = NULL;
    n->have_child = 0;
    n->value = def_val;
    return n;
}

void t_free(Node *n){
    if (!n)
        return;
    for (int i = 0; i < alph_size; i++)
        t_free(n->next[i]);
    free(n->stored);
    free(n);
}

int get_branch(char c){
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    if (c == '-')
        return 26;
    if (c == '.')
        return 27;
    return -1;
}

void t_add(Node *n, char *s, t_type value){
    if (n->stored){
        // push stored
        int stored_branch = get_branch(n->stored[0]);
        if (!n->next[stored_branch])
            n->next[stored_branch] = new_Node();
        t_add(n->next[stored_branch], n->stored + 1, n->value);
        free(n->stored);
        n->stored = NULL;
        n->value = def_val;
        n->have_child = 1;
    }

    if (s[0] == '\0'){
        n->value  =  value;
        return;
    }

    if (n->have_child || n->value != def_val){
        int branch = get_branch(s[0]);
        if (!n->next[branch])
            n->next[branch] = new_Node();
        t_add(n->next[branch], s + 1, value);
    } else {
        n->stored = malloc((strlen(s) + 1) * sizeof(char));
        strcpy(n->stored, s);
        n->value = value;
    }
}

t_type t_get(Node *n, char *s){
    if (!n)
        return def_val;

    if (n->stored){
        if (!strcmp(s, n->stored))
            return n->value;
        return def_val;
    }

    if (s[0] == '\0')
        return n->value;

    int branch = get_branch(s[0]);
    return t_get(n->next[branch], s + 1);
}