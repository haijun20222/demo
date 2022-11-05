#include "stdio.h"
#include "string.h"


int main()
{
    char a[15] = "helloworld\r\n";
    char b[10] = {0};
    a[9] = 'D';
    char *p =NULL;
    p =a;
    p[0] = 'a';
    printf("p=a:%s\n",p);
    printf("p=a:%x\n",p);
    p = "hello";
    printf("p=hello:%s\n",p);
    printf("p=a:%x\n",p);
    return 0;
}