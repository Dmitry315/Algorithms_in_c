#include "rb-tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef int key_type;
typedef int data_type;
#define RED 1
#define BLACK 0

typedef struct Node Node;
struct Node{
    unsigned long  parent_color; // pointer on parent, color in last bit,
    // red = 1, black = 0
    struct Node *right;
    struct Node *left;
    key_type key;
    data_type data;
};

Node *root = NULL;

void left_balancing(Node *n);
void right_balancing(Node *n);

Node *new_Node(Node *parent, key_type key, data_type data){
    Node *n = malloc(sizeof(Node));
    n->parent_color = (unsigned long) parent; // black by default
    n->left = NULL;
    n->right = NULL;
    n->key = key;
    n->data = data;
    return n;
}

int color(Node *n){
    if (!n) return 0;
    return n->parent_color & 1;
}

Node *parent(Node *n){
    return (Node *) (n->parent_color & ~1);
}

void set_parent(Node *n, Node *p){
    if (n)
        n->parent_color = (unsigned long) p + color(n);
}

void paint(Node *n, int color){
    n->parent_color = (n->parent_color & ~1) + color;
}

Node *uncle(Node *n)
{
    Node *p = parent(n);
    Node *g = parent(p);
    if (!g)
        return NULL; // No grandparent means no uncle
    if (p == g->left)
        return g->right;
    else
        return g->left;
}

void small_left_rotate(Node *n){
    Node *p = parent(n);
    Node *g = parent(p);

    p->right = n->left;
    set_parent(p->right, p);
    n->left = p;
    set_parent(p, n);
    if (p == root){
        root = n;
    } else {
        if (g->left == p)
            g->left = n;
        else
            g->right = n;
        set_parent(n, g);
    }
}

void small_right_rotate(Node *n){
    Node *p = parent(n);
    Node *g = parent(p);

    p->left = n->right;
    set_parent(p->left, p);
    n->right = p;
    set_parent(p, n);
    if (p == root){
        root = n;
    } else {
        if (g->right == p)
            g->right = n;
        else
            g->left = n;
        set_parent(n, g);
    }
}

void big_right_rotation(Node *n){
    Node *p = parent(n);
    Node *g = parent(p);
    Node *grand_grand = parent(g);

    g->left = p->right;
    set_parent(g->left, g);
    p->right = g;
    set_parent(g, p);

    set_parent(p, grand_grand);
    if (g == root)
        root = p;
    else if (grand_grand->left == g)
        grand_grand->left = p;
    else
        grand_grand->right = p;

    paint(p, BLACK);
    paint(g, RED);
}

void big_left_rotation(Node *n){
    Node *p = parent(n);
    Node *g = parent(p);
    Node *grand_grand = parent(g);

    g->right = p->left;
    set_parent(g->right, g);
    p->left = g;
    set_parent(g, p);

    set_parent(p, grand_grand);
    if (g == root)
        root = p;
    else if (grand_grand->left == g)
        grand_grand->left = p;
    else
        grand_grand->right = p;

    paint(p, BLACK);
    paint(g, RED);
}

void add_fix(Node *n){
    if (n == root){
        paint(root, BLACK);
        return;
    }

    Node *p = parent(n); // parent
    if (color(p) == BLACK)
        return;

    Node *g = parent(p); // grandparent
    Node *u = uncle(n); // uncle

    if (color(p) == RED && color(u) == RED){
        paint(p, BLACK);
        paint(u, BLACK);
        paint(g, RED);
        add_fix(g);
        return;
    }

    // now parent is red and uncle is black
    if (p == g->left && n == p->right){
        small_left_rotate(n);
        p = n;
        n = n->left;
    } else if (p == g->right && n == p->left){
        small_right_rotate(n);
        p = n;
        n = n->right;
    }

    // parent and n on one side
    if (p == g->left && n == p->left){
        big_right_rotation(n);
    } else{ // p == g->right && n == p->right
        big_left_rotation(n);
    }
}

void add(key_type key, data_type data){
    if (!root){ // rb tree is empty
        root = new_Node(NULL, key, data);
        return;
    }

    Node *parent = root;
    Node *n = root;
    while (n){
        if (n->key == key){
            n->data = data;
            return;
        }
        parent = n;
        if (n->key < key)
            n = n->right;
        else
            n = n->left;
    }

    n = new_Node(parent, key, data);
    paint(n, RED); // new node is red
    if (parent->key < key)
        parent->right = n;
    else
        parent->left = n;

    add_fix(n);
}

void right_balancing(Node *n){
    if (color(n->right) == RED){
        paint(n->right, BLACK);
        return;
    }
    Node *bro = n->left;
    if (color(bro) == RED){
        paint(n, RED);
        paint(bro, BLACK);
        small_right_rotate(bro);
        right_balancing(n);
        return;
    }
    if (color(bro->right) == BLACK && color(bro->left) == BLACK){
        paint(bro, RED);
        if (color(n) == RED)
            paint(n, BLACK);
        else if (n != root){
            if (parent(n)->right == n)
                right_balancing(parent(n));
            else
                left_balancing(parent(n));
        }
        return;
    }
    if (color(bro->left) == BLACK){
        paint(bro, RED);
        paint(bro->right, BLACK);
        small_left_rotate(bro->right);
        right_balancing(n);
        return;
    }
    // bro->left is red
    paint(bro, color(n));
    paint(bro->left, BLACK);
    paint(n, BLACK);
    small_right_rotate(bro);
}

void left_balancing(Node *n){
    if (color(n->left) == RED){
        paint(n->left, BLACK);
        return;
    }
    Node *bro = n->right;
    if (color(bro) == RED){
        paint(n, RED);
        paint(bro, BLACK);
        small_left_rotate(bro);
        left_balancing(n);
        return;
    }
    if (color(bro->left) == BLACK && color(bro->right) == BLACK){
        paint(bro, RED);
        if (color(n) == RED)
            paint(n, BLACK);
        else if (n != root){
            if (parent(n)->left == n)
                left_balancing(parent(n));
            else
                right_balancing(parent(n));
        }
        return;
    }
    if (color(bro->right) == BLACK){
        paint(bro, RED);
        paint(bro->left, BLACK);
        small_right_rotate(bro->left);
        left_balancing(n);
        return;
    }
    // bro->right is red
    paint(bro, color(n));
    paint(bro->right, BLACK);
    paint(n, BLACK);
    small_left_rotate(bro);
}

void delete(key_type key){
    Node *n = root;
    while (n && n->key != key)
        if (n->key < key)
            n = n->right;
        else
            n = n->left;
    if (!n) return; // There's no such key in the tree

    if (n->left && n->right){ // swap n with node wiht less than one child
        Node *sacrifice = n->right;
        while (sacrifice->left)
            sacrifice = sacrifice->left;
        n->key = sacrifice->key;
        n->data = sacrifice->data;
        n = sacrifice;
    }

    // now n has less than 2 children
    if (n == root){
        if (n->left){
            root = n->left;
            set_parent(n->left, NULL);
        } else if (n->right){
            root = n->right;
            set_parent(n->right, NULL);
        } else
            root = NULL;
        free(n);
        if (root)
            paint(root, BLACK);
        return;
    }

    Node *p = parent(n);

    if (color(n) == RED){ // n has no children
        if (p->left == n)
            p->left = NULL;
        else
            p->right = NULL;
    } else { // n is black
        if (n->right){
            n->key = n->right->key;
            n->data = n->right->data;
            n = n->right;
            parent(n)->right = NULL;
        } else if (n->left){
            n->key = n->left->key;
            n->data = n->left->data;
            n = n->left;
            parent(n)->left = NULL;
        } else { // n is black without children :(
            if (p->left == n){
                p->left = NULL;
                left_balancing(p);
            } else {
                p->right = NULL;
                right_balancing(p);
            }
        }
    }
    free(n);
}

void search(key_type key){
    Node *n = root;
    while (n && n->key != key)
        if (n->key < key)
            n = n->right;
        else
            n = n->left;
    if (!n) return; // there's no such key in the tree
    printf("%d %d\n", key, n->data);
}

void rb_free(Node *n){
    if (n){
        rb_free(n->left);
        rb_free(n->right);
        free(n);
    }
}