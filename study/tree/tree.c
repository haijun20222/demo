#include "stdio.h"
#include "stdlib.h"

typedef struct tree
{
    int data;
    struct tree* left_tree;
    struct tree* right_tree;
} tree;

int creat_tree(tree* new_tree) {
     new_tree = malloc(tree);


}