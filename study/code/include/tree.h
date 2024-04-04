#ifndef _TREE_H_
#define _TREE_H_

typedef struct tree
{
    int data;
    struct tree* left_tree;
    struct tree* right_tree;
} tree;

int init_tree(tree** new_tree);
int print_xian_digui(tree *Tree);
int test(void);
int print_xian(tree *Tree);

#endif