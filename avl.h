//
// Created by ACER on 05.12.2020.
//

#ifndef ALGNSTRUCTS_AVL_H
#define ALGNSTRUCTS_AVL_H

typedef struct TreeNode {
    int key;
    int data;
    int height;
    struct TreeNode *left, *right;
} TreeNode;

void free_tree(TreeNode *node);
int height(TreeNode *p);
TreeNode *findmin(TreeNode *p);
TreeNode *findmax(TreeNode *p);
TreeNode *search(TreeNode *node, int key);
TreeNode *add(TreeNode *head, int key, int value);
TreeNode *del(TreeNode *head, int key)


#endif //ALGNSTRUCTS_AVL_H
