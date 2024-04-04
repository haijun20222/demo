#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void resverse(char* str)
{
    char tmp = *str;
    int len = strlen(str);
    *str = *(str + len - 1);
    *(str + len - 1) = '\0';
    if (strlen(str + 1) >= 2) {
        resverse(str + 1);
    }
    *(str + len - 1) = tmp;
}
void sort(void)
{
    int i, j, tmp;
    int a[9] = {0, 2, 3, 5, 4, 6, 7, 9};
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8 - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

            }
        }
    }

    for (i = 0; i < 9; i++) {
        printf("a[%d]=%d\r\n", i, a[i]);
    }
}

int main()
{
//   char str[15] = "123456";
//   resverse(str);
    //  printf("str:%s\r\n",str);
    sort();
}