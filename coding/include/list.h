#ifndef _LIST_H_
#define _LIST_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>
struct list
{
    int data;
    struct list* next; 
};
typedef struct list*  list_p;
typedef struct list  list_t;

struct queue
{
    list_p front;
    list_p rear;
};
typedef struct queue  queue_t;
typedef struct queue*  queue_p;

//list
int list_traverse(void);
list_p create_node(int data);
int init_head(void);
int list_add(int data);
int list_head_add(int* data,int max);
int list_tail_add(int* data,int max);
int list_del(int data);
int list_insert_behind(int ori_data, int data);
int list_modify(int ori_data,int data);
int list_traverse(void);
int list_traverse_bak(list_p list);
int list_sort(void);
int list_overturn(list_p*tmp);
int list_del_all();
int list_check_loop();
int list_create_loop_link();
int list_apply();
//queue
int init_queue();
int push_queue(int data);
int pop_queue(int*data);
int queue_traverse();
int queue_apply();
//sort
int sort_paopao(int*array,int len);
int sort_select(int*array,int len);
int sort_insert(int*array,int len);
int sort_print(int*array,int len);
int sort_apply();
//string.h
int string_apply();
//double list
int double_list_apply();
#endif 