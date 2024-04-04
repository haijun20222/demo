#include "tree.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <unistd.h>

int init_tree(tree **new_tree)
{
    *new_tree = malloc(sizeof(tree));
    (*new_tree)->data = 1;

    (*new_tree)->left_tree = malloc(sizeof(tree));
    (*new_tree)->left_tree->data = 2;

    (*new_tree)->right_tree = malloc(sizeof(tree));
    (*new_tree)->right_tree->data = 3;

    (*new_tree)->left_tree->left_tree = malloc(sizeof(tree));
    (*new_tree)->left_tree->left_tree->data = 4;

    (*new_tree)->left_tree->right_tree = malloc(sizeof(tree));
    (*new_tree)->left_tree->right_tree->data = 5;

    (*new_tree)->right_tree->left_tree = malloc(sizeof(tree));
    (*new_tree)->right_tree->left_tree->data = 6;

    (*new_tree)->right_tree->right_tree = malloc(sizeof(tree));
    (*new_tree)->right_tree->right_tree->data = 7;

    return 0;
}

int print_xian_digui(tree *Tree)
{

    if (!Tree)
    {
        return 0;
    }
    printf("%d\n", Tree->data);
    print_xian_digui(Tree->left_tree);
    print_xian_digui(Tree->right_tree);
    return 0;
}

int print_mid_digui(tree *Tree)
{

    if (!Tree)
    {
        return 0;
    }
    print_mid_digui(Tree->left_tree);
    printf("%d\n", Tree->data);
    print_mid_digui(Tree->right_tree);
    return 0;
}

int print_rear_digui(tree *Tree)
{

    if (!Tree)
    {
        return 0;
    }
    print_rear_digui(Tree->left_tree);
    print_rear_digui(Tree->right_tree);
    printf("%d\n", Tree->data);
    return 0;
}

#define NUM  100
typedef struct stack 
{
    tree* stack_tree[NUM];
    int top;
} Stack;


tree* get_tree(Stack* stack) 
{
    if(stack->top == -1) {
      printf("get_tree is err\n");
      return NULL;
    }
    return stack->stack_tree[stack->top];
}

void push_stack(Stack* stack, tree* tree) 
{
   stack->top++;
   stack->stack_tree[stack->top] = tree;
}

void pop_stack(Stack* stack) 
{
    if (stack->top == -1) {
        return ;
    }
    stack->top--;
}

void print_tree(tree* Tree) 
{
    if(!Tree) {
        printf("print_tree is err\n");
        return;
    }
    printf("%d\n",Tree->data);
}


int print_xian(tree *Tree) 
{
    if (!Tree) {
        return 0;
    }
    tree* tmp;
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    push_stack(stack, Tree);
    while (stack->top != -1) 
    {
        tmp = get_tree(stack);
        pop_stack(stack);
        while (tmp) 
        {
            sleep(1);
            if (tmp) {
                print_tree(tmp);
                if (tmp->right_tree) {
                    push_stack(stack, tmp->right_tree);
                }
                tmp = tmp->left_tree;
            }       
        }
    }
}


int print_mid(tree *Tree) 
{
    if (!Tree) {
        return 0;
    }
    tree* tmp;
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    // push_stack(stack, Tree);
    // tmp = get_tree(stack);
    tmp = Tree;
    while (tmp||stack->top != -1) 
    {
        if (tmp) {
            push_stack(stack, tmp);
            tmp = tmp->left_tree;
        } else {
            tmp = get_tree(stack);
            pop_stack(stack); 
            print_tree(tmp);
            sleep(1);
            tmp = tmp->right_tree;
        }
    }
}

#define NUM_REAR  100
typedef struct tag_tree 
{
    tree* tree;
    int tag;
} tag_tree;

typedef struct stack_rear 
{
    tag_tree stack_tree[NUM_REAR];
    int top;

    
} stack_rear;

void push_stack_rear(stack_rear* stack, tag_tree* tree) {
    ++stack->top;
    stack->stack_tree[stack->top].tree = tree->tree;
    stack->stack_tree[stack->top].tag = tree->tag;
}

void pop_stack_rear(stack_rear* stack) {
    if (stack->top == -1) {
       printf("stack is null\n"); 
       return;
    }
    --stack->top;
}

tag_tree* get_stack_rear(stack_rear* stack) {
    if (stack->top == -1) {
       printf("stack is null\n"); 
       return NULL;
    }
    return &(stack->stack_tree[stack->top]);
    
}

int print_rear(tree *Tree) 
{
    if (!Tree) {
        return 0;
    }
    stack_rear* stack = malloc(sizeof(stack_rear));
    stack->top = -1;

    tag_tree* tmp = malloc(sizeof(tag_tree));
    tmp->tree = Tree;
    tmp->tag  = 0;
    tag_tree* p;

    while (tmp->tree || stack->top != -1) {
        while (tmp->tree ) {
            if (tmp->tag == 1) {
                break;
            }
            tmp->tag = 0;
            push_stack_rear(stack, tmp);
            tmp->tree = tmp->tree->left_tree;
        }
        sleep(1);
        p = get_stack_rear(stack);
        // printf("tmp.tag: %d\n", p->tag);
        // printf("tmp.tree: %d\n", p->tree->data);
        if (p->tag == 0) {
            p->tag = 1;
            // pop_stack_rear(stack);
            // push_stack_rear(stack, tmp);
            tmp->tree = p->tree->right_tree;
            tmp->tag = 0;
        } else {
            print_tree(p->tree);
            pop_stack_rear(stack);
        }
    }
}

int test(void)
{
    tree *new_tree = NULL;
    init_tree(&new_tree);
    // print_xian_digui(new_tree);
    // print_mid_digui(new_tree);
    // print_rear_digui(new_tree);
   // print_xian(new_tree); 
  // print_mid(new_tree);
   print_rear(new_tree);
    return 0;



















}
