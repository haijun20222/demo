#include "list.h"
#define E_OK       0
#define E_ERROR   -1

list_p head = NULL;
list_p create_node(int data)
{
      list_p new_list = NULL;
      new_list = (list_p)malloc(sizeof(list_t));
      new_list->data = data;
      new_list->next = NULL;
      return new_list;
}

int init_head(void)
{
    head = (list_p)malloc(sizeof(list_t));
    head->next = NULL;
    memset(head,0,sizeof(list_t));
    printf("list init successful\n");
    return E_OK;
}

int list_add(int data)
{
    list_p tmp =NULL;
    list_p new_list = NULL;
    new_list = create_node(data);
    tmp = head;
    while(tmp->next)
    {
       tmp = tmp->next;
    }
    tmp->next = new_list;
    list_traverse();
    return E_OK; 
}

int list_head_add(int* data,int max)
{
    int index = 0;
    list_p new_list = NULL;
    printf("list head add\n");
    for(index = 0;index < max;index++)
    {
        new_list = create_node(data[index]);
        new_list -> next = head->next;
        head->next = new_list;
    }
    list_traverse();
    return E_OK;
}

int list_tail_add(int* data,int max)
{
    int index = 0;
    list_p tail =NULL;
    list_p new_list =NULL;
    printf("list tail add \n");
    tail = head;
    
    for(index = 0;index<max;index++)
    {
        new_list = create_node(data[index]);
        tail->next = new_list;
        tail = new_list;
    }
    list_traverse();
    return E_OK;
}


int list_del(int data)
{
    list_p del = NULL;
    list_p tmp = NULL;
    printf("list del\n");
    if(NULL !=  head->next)
    {
        tmp = head;
    }
    while(tmp->next->data != data)
    {
        tmp = tmp->next;
        if(NULL == tmp->next)
        {
            printf("no find this data\n");
            return -1;
        }
    }
    if(tmp->next->data == data)
    {
         del = tmp->next;
         tmp->next = del->next;
         free(del);
         del = NULL;
    }
    list_traverse();
    return E_OK;
}

int list_insert_behind(int ori_data, int data)
{
    printf("list_insert_behind\n");
    list_p tmp = NULL;
    list_p cur_list = NULL;
    list_p new_list = NULL;
    new_list = create_node(data);
    tmp = head;
    if(NULL==head->next)
    {
        printf("no add data,error");
        return -1;
    }
    while(tmp->next)
    {
        if(tmp->next->data == ori_data)
        {
            break;
        }
        tmp = tmp->next;
        if(NULL == tmp->next)
        {
            printf("no find this data!!!\n");
            return -1;
        }
    }
    if(tmp->next->data == ori_data)
    {
        tmp = tmp->next;
        cur_list = tmp->next;
        tmp->next = new_list;
        new_list = cur_list;
    }
    list_traverse();
    return E_OK;
}

int list_modify(int ori_data,int data)
{
    list_p tmp = NULL;
    tmp = head;
    printf("list_modify list\n");
    if(NULL == head->next)
    {
        printf("no insert data!!!!\n");
        return -1;
    }

    while(tmp->next->data != ori_data)
    {
        tmp = tmp->next;
        if(NULL == tmp->next)
        {
           printf("no find this data,in list end\n");
           return -1;
        }
    }
    if(tmp->next->data == ori_data)
    {
         tmp->next->data = data;
         printf("modify data :%d -> %d successfully\n",ori_data,data);
    }
     list_traverse();
     return E_OK;
}

int list_traverse(void)
{
    printf("list traverse\n");
    list_p tmp = NULL;
    tmp = head;
    if(NULL == tmp->next)
    {
        printf("no add data,error!!!\n");
        return -1;
    }
    printf("data:  ");
    while(NULL!= tmp->next)
    {
        printf("%d   ",tmp->next->data);
        tmp = tmp->next;
    }
    printf("\n");
    return E_OK;
}


int list_traverse_bak(list_p list)
{
    list_p tmp = NULL;
    tmp = list;
    if(NULL == tmp->next)
    {
        printf("no add data,error!!!\n");
        return -1;
    }
    printf("data:  ");

    while(NULL!= tmp->next)
    {
        printf("%d   ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return E_OK;
}

int list_sort(void)
{
    printf("list_sort\n");
    list_p i_tmp = NULL;
    list_p j_tmp = NULL;
    int tmp = 0;
    i_tmp = head;
    if(NULL == i_tmp->next)
    {
        printf("no add list error!!!\n");
        return E_ERROR;
    }
    for(i_tmp= head->next;i_tmp->next !=NULL;i_tmp = i_tmp->next)
    {
        for(j_tmp = head->next;j_tmp->next!=NULL;j_tmp = j_tmp->next)
        {
            if(j_tmp->data > j_tmp->next->data)
            {
                tmp = j_tmp->data;
                j_tmp->data = j_tmp->next->data;
                j_tmp->next->data = tmp;
            }
        }
    }
    list_traverse();
    return E_OK;
}

int list_overturn(list_p*tmp)
{
    printf("list overturn\n");
    *tmp = head->next;
    list_p list_first = head->next;
    list_p cur_list =head;

    while(*tmp)
    {     
         head->next = (*tmp)->next;
         (*tmp)->next = cur_list;
         cur_list  = (*tmp);
         if(!head->next)
         {
             break;
         }
         (*tmp) = head->next;
    }
    list_traverse_bak(*tmp);
    return E_OK;
}


list_p list_overturn_digui(list_p head)
{
    list_p tmp_list;
    if(!head || !head->next)
    {
        return head;
    }
   list_p list_head = list_overturn_digui(head->next);
   head->next->next = head;
   head->next = NULL;
   return list_head;
}

int list_del_all()
{
    printf("list del all\n");
    list_p tmp = NULL;
    list_p del_list = NULL;
    tmp = head;
    if(NULL== tmp->next)
    {
        printf("no add list error!!\n");
        return E_ERROR;
    }  
    while(NULL !=tmp->next)
    {
         del_list = tmp->next; 
         tmp->next = del_list->next;
         free(del_list);
         del_list =NULL;
    }
     list_traverse();
}

int list_create_loop_link()
{
   list_p new_list = NULL;
   list_p tmp = head;
   int loop_data = 2;
   int array[5] = {1,2,3,4,5};
   int len = sizeof(array)/sizeof(array[0]);
   list_tail_add(array,len);
   new_list = create_node(loop_data);
   while(tmp->next)
   {
      if(tmp->next->data ==loop_data)
      {
           tmp->next->next = new_list;
           new_list->next =  tmp->next;
           break;
      }
      tmp = tmp->next;  
   }
   return E_OK;
}

int list_check_loop()
{
    list_p low_tmp = head;
    list_p fast_tmp = head;
    list_p  tmp = head;
    while(tmp->next)
    {    
        if(NULL != low_tmp|| NULL != fast_tmp->next)
        {
            low_tmp = low_tmp->next;
            fast_tmp = low_tmp->next->next;
        }
        if(low_tmp == fast_tmp)
        {
            printf("i am in loop\n");
            break;
        }
        tmp = tmp->next;
    }
    return E_OK;
}

int list_apply()
{
   list_p list_head;
   int array[] = {1,2,3,4,5};
   int len = sizeof(array)/sizeof(array[0]);
   init_head();
   list_tail_add(array,len);
   list_traverse();
   list_head = list_overturn_digui(head);
   list_traverse_bak(list_head);
   #if 0
   list_create_loop_link(); 
   list_check_loop();
   #endif
   return 0;
}




