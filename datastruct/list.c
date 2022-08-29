#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void traverse_node(void);
struct node
{
    int data;
    struct node*pnext;
};
struct node* phead = NULL;

void creat_head()
{
    printf("*************头节点创建*****************\r\n");
    phead = (struct node*)malloc(sizeof(struct node));
    phead->pnext = NULL;
    traverse_node();
}

void add_node(int data)
{
    struct node* pnew = (struct node*)malloc(sizeof(struct node));
    struct node* ptmp = phead;
    printf("*************增加节点data:%d*****************\r\n",data);
    while(ptmp->pnext !=NULL)
    {
        ptmp =  ptmp->pnext;
    }
    ptmp->pnext = pnew;
    pnew->pnext =NULL;
    pnew->data=data;
    traverse_node();
}

void insert_node(int sdata,int data)
{
    struct node* pnew = (struct node*)malloc(sizeof(struct node));
    struct node* ptmp = phead->pnext;
    printf("*************插入节点sdata:%d,data:%d*****************\r\n",sdata,data);
    while(ptmp->data !=sdata)
    {
        ptmp =  ptmp->pnext;
    }

    pnew ->pnext = ptmp->pnext;
    ptmp->pnext = pnew;
    pnew->data = data;
    traverse_node();
}

void del_node(int data)
{
    struct node* pdel;
    struct node* ptmp = phead;
    printf("*************删除节点data:%d*****************\r\n",data);
    while(ptmp->pnext->data !=data)
    {
        ptmp=  ptmp->pnext;
    }
    pdel = ptmp->pnext;
    printf("data:pdel:%d\r\n",pdel->data);
    ptmp->pnext  = ptmp->pnext->pnext;
    free(pdel);
    pdel = NULL;
    printf("ptmp data:%d\r\n",ptmp->data);
    traverse_node();
}


/*
void del_node(int data)

{
    struct node* pdel;
    struct node* ptmp = phead->pnext;
    printf("*************删除节点data:%d*****************\r\n",data);
    while(ptmp->data !=data)
    {
        ptmp=  ptmp->pnext;
    }
    pdel = ptmp;
    ptmp  = ptmp ->pnext;
    free(pdel);\
    pdel = NULL;
    traverse_node();
}
*/

void change_node(int sdata,int data)
{
    struct node* ptmp;
    ptmp = phead->pnext;
    printf("*************改变节点sdata:%d:data:%d*****************\r\n",sdata,data);
    while(ptmp->data != sdata)
    {
        ptmp = ptmp->pnext;
    }
    ptmp->data = data;
    traverse_node();
}

void traverse_node(void)
{
    struct node* ptmp;
    ptmp = phead->pnext;
    printf("**********打印出所有的节点*****************\r\n");
    while(ptmp!= NULL)
    {
        printf("node:%d\r\n",ptmp->data);
        ptmp = ptmp->pnext;
    }
}
void sort_node(void)
{
    struct node* ptmp;
    int len = 0;
    int i,j,tmp;
    ptmp = phead->pnext;
    while(ptmp!=NULL)
    {
        ptmp =ptmp->pnext;
        len++;
    }

    printf("**********冒泡排序*****************\r\n");
    for(i =0;i<len-1;i++)
    {
        ptmp = phead->pnext;
        for(j=0;j<len-1-i;j++)
        {
           if((ptmp->data)>(ptmp->pnext->data))
           {
                 tmp = ptmp->data;
                 ptmp->data = ptmp->pnext->data;
                 ptmp->pnext->data = tmp;

           }
           ptmp = ptmp->pnext;
        }
    }
    traverse_node();
}


void free_node(void)
{
    struct node* ptmp;
    struct node* pdel;
    ptmp = phead;
    printf("**********删除所有节点*****************\r\n");
    while(ptmp->pnext!=NULL)
    {
        pdel = ptmp->pnext;
        printf("data:pdel:%d\r\n",pdel->data);
        ptmp->pnext  = ptmp->pnext->pnext;
        free(pdel);
        pdel = NULL;
    }
    traverse_node();
}


int main()
{
    creat_head();
    add_node(10);
    add_node(100);
    add_node(3);
    add_node(2);
    add_node(1);
    
    add_node(8);
    del_node(100);
    insert_node(10,3);
    change_node(8,11);
    sort_node();
    free_node();
    return 0;
}