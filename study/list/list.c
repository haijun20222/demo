#include "stdio.h"
#include "stdlib.h"

typedef struct list {
int data;
struct list* list;
} list;

list* init_list(list* list_head) 
{
    list_head = malloc(sizeof(list)); 
    return list_head;
}




