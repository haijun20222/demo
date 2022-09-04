#include "stdio.h"
#include "stdlib.h"
int main()
{
    char*p ="hello world";
    printf("p指向你好世界的地址为:%x\r\n",p);
    p ="i am zhu";
    printf("p指向我是猪的地址为:%x\r\n",p);
    printf("p=%s\r\n",p);

}