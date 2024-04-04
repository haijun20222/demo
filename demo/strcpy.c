#include "stdio.h"
char* strcpy(char* DestStr, const char* SrcStr);
int strlen(char* str);
char* strcat(char* DestStr, const char* SrcStr);
int strcmp(char* DestStr, char* SrcStr);
int main()
{
    int len = 0;
    char str1[10] = "hella";
    char str2[10] = "hell";
    strcmp(str1, str2);
    char* src_str = "helloworld";
    char dest_str[30] = {0};
    strcpy(dest_str, src_str);
    strlen(dest_str);
    strcat(dest_str, src_str);
    return 0;
}

char* strcpy(char* DestStr, const char* SrcStr)
{
    if (DestStr == NULL || SrcStr == NULL) {
        return -1;
    }
    char* StrTmp = DestStr;
    while (*SrcStr) {
        *DestStr++ = *SrcStr++;
    }
    *DestStr = '\0';
    printf("DestStr:%s\r\n", StrTmp);
}
int strlen(char* str)
{
    int len = 0;
    while (*str++) {
        len++;
    }
    printf("strlen:%d\r\n", len);
    return len;
}


char* strcat(char* DestStr, const char* SrcStr)
{
    char* StrTmp = DestStr;
    while (*DestStr++);
    --DestStr;
    while (*SrcStr) {
        *DestStr++ = *SrcStr++;
    }
    *DestStr = 0;
    printf("DestStr:%s\r\n", StrTmp);
    return StrTmp;
}


int strcmp(char* DestStr, char* SrcStr)
{

    if (DestStr == NULL || SrcStr == NULL) {
        return -1;
    }
    while (*DestStr++ == *SrcStr++) {
        if (*(DestStr - 1) == 0) {
            return 0;
        }
    }
    printf("strcmp:%d\r\n", *(DestStr - 1) - * (SrcStr - 1));
    return *(DestStr - 1) - *(SrcStr - 1);
}


