#include "c_string.h"
#define E_OK 
#define E_ERROR -1

int string_check_null(void*para)
{
    if(!para)
    {
       printf("pointer is null\r\n");
       return -1;
    }
}
int string_strlen(char*str)
{  
    int len = 0;
    #if 0
    if(string_check_null(str))
    {
      return 0;
    }
    #endif
    while(*str++)
    {
      len++;
    }
    return len;
}

char* string_strcpy(char*src_str,char*dest_str)
{
  char*tmp =NULL;
  tmp = src_str;
  while(*src_str)
  {
      *dest_str++ = *src_str++;
  }
  *dest_str = '\0';
  dest_str = tmp;
  return dest_str;
}

int string_strcmp(char*src_str,char*dest_str)
{
    while(!(*src_str++ - *dest_str++))
    {
      if(!*src_str)
      {
          return 0;
      }
    }
    return *(src_str-1)-*(dest_str-1);
}

char* string_strcat(char*src_str,char*dest_str)
{
    char*tmp = src_str;
    while(*src_str++);
    src_str = src_str -1;
    while(*dest_str)
    {
         *src_str++ = *dest_str++;
    }
    return tmp;
}

char* string_digui(char*str)
{
    int len = 0;
    if(*str == '\0')
    {
      return NULL;
    }
    len = string_strlen(str);
    char tmp = *str;
    *str = *(str+len-1);
    *(str+len-1) = '\0';

    string_digui(str+1);
    *(str+len-1) = tmp;
    return str;
}

int string_apply()
{
 
  char src_str[] = "hello";
  char dest_str[] = "world";
  char*str;
  #if 0
  char* tmp = NULL; 
  int len = 0;
  tmp = string_strcpy(src_str,dest_str);
  string_strcpy("world",dest_str);
  printf("strcpy:tmp = %s\n",tmp);
  len = string_strcmp(src_str,dest_str);
  printf("strcmp:len = %d\n",len);
  tmp = string_strcat(src_str,dest_str);
  printf("strcat:tmp = %s\n",tmp);
  #endif
  int len = string_strlen(src_str);
  printf("str:%s\n",src_str);
  str = string_digui(src_str);
  printf("str:%s\n",str);
  return 0;
}



