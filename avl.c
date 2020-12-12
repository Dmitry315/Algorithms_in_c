#include "avl.h"
#include <stdlib.h>

// AVL tree

void free_tree(TreeNode *node) {
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

// some helpful functions
int height(TreeNode *p) {
    return p ? p->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

TreeNode *findmin(TreeNode *p) {
    return p->left ? findmin(p->left) : p;
}

TreeNode *findmax(TreeNode *p) {
    return p->right ? findmin(p->right) : p;
}

// rotations
TreeNode *RotateLeft(TreeNode *k2) {
    TreeNode *k1;
    // rotate
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

TreeNode *RotateRight(TreeNode *k1) {
    TreeNode *k2;
    // rotate
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k2;
}

TreeNode *DoubleRotateLeft(TreeNode *k3) {
    k3->left = RotateRight(k3->left);
    return RotateLeft(k3);
}

TreeNode *DoubleRotateRight(TreeNode *k3) {
    k3->right = RotateLeft(k3->right);
    return RotateRight(k3);
}

// function to fix AVL tree
TreeNode *balance(TreeNode *head) {
    int diff = height(head->left) - height(head->right);
    if (diff == 2) {
        if (height(head->left->left) > height(head->left->right))
            head = RotateLeft(head);
        else
            head = DoubleRotateLeft(head);
    }
    if (diff == -2) {
        if (height(head->right->left) < height(head->right->right))
            head = RotateRight(head);
        else
            head = DoubleRotateRight(head);
    }
    head->height = max(height(head->left), height(head->right)) + 1;
    return head;
}

// search node in tree recursively
TreeNode *searchAVL(TreeNode *node, int key) {
    if (node == NULL)
        return NULL;
    if (node->key == key)
        return node;
    if (key < node->key)
        return searchAVL(node->left, key);
    else
        return searchAVL(node->right, key);
}

// add/update node in AVL tree recursively
TreeNode *add(TreeNode *head, int key, int data) {
    if (head == NULL) {
        head = malloc(sizeof(TreeNode));
        head->key = key;
        head->data = data;
        head->left = head->right = NULL;
    } else if (key == head->key) {
        head->data = data;
        return head;
    } else if (key < head->key) {
        head->left = add(head->left, key, data);
    } else if (key > head->key) {
        head->right = add(head->right, key, data);
    }
    return balance(head);
}

// remove minimal key from the AVL tree
TreeNode *removemin(TreeNode *head) {
    if (head->left == 0)
        return head->right;
    head->left = removemin(head->left);
    return balance(head);
}

// delete node from AVL tree
TreeNode *deleteAVL(TreeNode *head, int key) {
    if (head == NULL) {
        return head;
    }
    if (key == head->key) {
        TreeNode *l = head->left;
        TreeNode *r = head->right;
        if (r == NULL)
            return l;
        TreeNode *m = findmin(r);
        m->right = removemin(r);
        m->left = l;
        return balance(m);
    } else if (key < head->key) {
        head->left = deleteAVL(head->left, key);
    } else if (key > head->key) {
        head->right = deleteAVL(head->right, key);
    }
    return balance(head);
}