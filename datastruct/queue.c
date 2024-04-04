#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef enum {PUSH_QUEUE = 1, POP_QUEUE, PRINT} QUEUE;
int NUM = 1;
int cur_num = 0;
struct queue {
    int data;
    struct queue* next;
};

struct linkqueue {
    struct queue* front;
    struct queue* rear;
    int count;
};

struct queue* queue;
struct linkqueue* linkqueue;

int init_queue(void)
{
    linkqueue = (struct linkqueue*)malloc(sizeof(struct linkqueue));
    if (queue == NULL) {
        return -1;
    }
    linkqueue->front = NULL;
    linkqueue->rear =  NULL;
    linkqueue->count = 1;
    return 0;
}

int push_queue()
{
    struct queue* new = (struct queue*) malloc(sizeof(struct queue));
    if (new == NULL) {
        return -1;
    }

    new->data = NUM;
    new->next = NULL;

    if (linkqueue->front == NULL) {
        linkqueue->front = new;
        linkqueue->rear = new;
    } else {
        linkqueue ->rear->next = new;
    }
    NUM++;
    linkqueue->rear = new;
    linkqueue->count++;
    printf("hellowrld\r\n");

    printf("目前还有%d 人：\r\n", linkqueue->count);
    printf("目前挂号的号码%d\r\n", linkqueue->front->data);
    return 0;
}

int pop_queue()
{
    struct queue* del;
    if (linkqueue->front == NULL) {
        printf("目前没有人办理业务\r\n");
        return 0;
    }
    del = linkqueue->front;
    if (linkqueue->front != linkqueue->rear) {
        linkqueue->front = del->next;
    } else {
        linkqueue->front = NULL;
        linkqueue->rear = NULL;
    }
    if (del != NULL) {
        free(del);
        del = NULL;
    }
    linkqueue->count--;
    NUM++;
    printf("目前还有%d 人：\r\n", linkqueue->count);
    if (linkqueue->front == NULL) {
        printf("目前没有人办理业务\r\n");
        return 0;
    } else {
        printf("目前挂号的号码%d\r\n", linkqueue->front->data);
    }
    return 0;
}


void print_info(void)
{
    struct queue* ptmp;
    ptmp = linkqueue->front;
    printf("**********打印出所有的信息*****************\r\n");
    while (ptmp != NULL) {
        printf("seqnum:%d\r\n", ptmp->data);
        ptmp = ptmp->next;
    }
}

int main()
{
    init_queue();
    while (1) {
        QUEUE queue;
        printf("挂号输入1,离开输入2, 打印请输入3:\r\n");
        scanf("%d", &queue);
        getchar();
        switch (queue) {
        case PUSH_QUEUE:
            push_queue();
            break;
        case POP_QUEUE:
            pop_queue();
            break;
        case PRINT:
            print_info();
            break;
        default:
            printf("输入错误,请重新输入\r\n");
            break;
        }
    }
    return 0;
}