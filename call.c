#include"stdio.h"
#include"stdlib.h"
void fun(char*mac);
int main()
{
    char mac[6] = {0x01,0x0f,0x0d,0x05,0x22,0x05};
    const int a =10;
    int*p =&a;
    *p =20;
    printf("a=%d\n",a);

}


void fun(char*mac)
{
  int i;
   char a[6] ={0};
   for(i=0;i<6;i++)
   {
     a[i] = mac[i];
   }
   for(i=0;i<6;i++)
   {
     printf("a[%d]=%x\n",i,a[i]);
   }
}
