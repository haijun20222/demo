#include "list.h"
#define E_OK 0;
#define E_ERROR -1;
queue_p queue_info;
int init_queue()
{
    queue_info = (queue_p)malloc(sizeof(queue_t));
    queue_info->front = NULL;
    queue_info->rear  = NULL;
    return E_OK;
}

int push_queue(int data)
{
    list_p new_list = NULL;
    new_list = create_node(data);
    if(!queue_info->front)
    {
         queue_info->front = new_list;
         queue_info->rear  = new_list;
    }else
    {
        queue_info->rear->next = new_list;
        queue_info->rear = new_list;
    }
    return E_OK;
}

int pop_queue(int*data)
{
    list_p queue_del = NULL;
    if(!queue_info->front)
    {
        return E_OK;
    }
    *data = queue_info->front->data;
    queue_del = queue_info->front;
    queue_info->front = queue_info->front->next;
    free(queue_del);
    return E_OK;
}

int queue_traverse()
{
    list_p tmp = NULL;
    tmp = queue_info->front;
    if(!tmp)
    {
        return E_OK;
    }
    printf("data: ");
    while(tmp)
    {
        printf("%d  ",tmp->data); 
        tmp = tmp->next;
    }
    printf("\n");
}

int queue_apply()
{   
    int index = 0;
    int get_data[] = {0};
    int data[] = {0,1,2,3,4,5,6,7,8,9};
    init_queue();
    for(index = 0;index < 10; index++)
    {
       push_queue(data[index]);
       queue_traverse();
    }
    for(index = 0;index < 10; index++)
    {
       pop_queue(&get_data[index]);
       queue_traverse();
    }
    for(index = 0;index < 10; index++)
    {
        printf("get_data:%d  \n",get_data[index]);
    }
    return E_OK;
}