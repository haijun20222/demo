#include "list.h"
typedef struct Node
{
    int data;
    struct Node*pre;
    struct Node*next;
}Node_t,*Node_p;

Node_p head_double =NULL;
int double_list_init()
{
    head_double = (Node_p)malloc(sizeof(Node_t));
    head_double->data = 0;
    head_double->next = NULL;
    head_double->pre =NULL;
    return 0;
}

int double_list_print()
{
    Node_p tmp = head_double->next;
    printf("data: ");
    while(tmp->next)
    {
        printf("%d  ",tmp->data);
        tmp = tmp->next;
    }
    printf("%d  ",tmp->data);
    printf("\n");
    return 0;
}


Node_p double_list_get_newnode(int data)
{
    Node_p new_node = (Node_p)malloc(sizeof(Node_t));
    new_node->data  = data;
    new_node->pre   = NULL;
    new_node->next  = NULL;
    return new_node;
}

int double_list_head_insert_data(int data)
{
    Node_p new_node =  double_list_get_newnode(data);
    if(!head_double)
    {
        printf("head_double is NULL\n");
        return 0;
    }
    if(!head_double->next)
    {
         head_double->next = new_node;
         new_node->pre = head_double;
    }else
    {
         new_node->pre = head_double;
         new_node->next = head_double->next;
         new_node->next->pre = new_node;
         head_double->next = new_node;
    }

    return 0;
}

int double_list_tail_insert_data(int data)
{
    Node_p new_node =  double_list_get_newnode(data);
    Node_p tmp_node = head_double;
    while(tmp_node->next)
    {
        tmp_node=tmp_node->next;
    }
    tmp_node->next = new_node;
    new_node->pre =  tmp_node;
    return 0; 
}

int double_list_insert_data(int ori_data,int new_data)
{
    Node_p new_node =  double_list_get_newnode(new_data);
    Node_p tmp_node = head_double; 
    while(tmp_node->data != ori_data)
    {
        tmp_node = tmp_node->next; 
    }
    new_node->pre = tmp_node;
    new_node->next = tmp_node->next;
    tmp_node->next->pre = new_node;
    tmp_node->next = new_node;
    return 0;
}

int double_list_delete_data(int ori_data)
{
    Node_p tmp_node = head_double; 
    Node_p del_node = NULL;
    while(tmp_node->next->data != ori_data)
    {
        tmp_node = tmp_node->next; 
    }
    del_node = tmp_node->next;
    tmp_node->next = del_node->next;
    del_node->next->pre = tmp_node;
    free(del_node);
    return 0;
}

int double_list_apply()
{
    int i = 0;
    int array[] = {1,2,3,4,5,6};
    int len = sizeof(array)/sizeof(array[0]);
    double_list_init();
    for(i=0;i<len;i++)
    {
       // double_list_head_insert_data(array[i]);
        double_list_tail_insert_data(array[i]);
    }
    double_list_insert_data(1,7);
    double_list_print();
    double_list_delete_data(7);
    double_list_print();
    return 0;
}






