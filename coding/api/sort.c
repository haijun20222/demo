#include "list.h"
int swap(int*i,int*j)
{
    int tmp =0;
    tmp = *i;
    *i = *j;
    *j = tmp;
    return 0;
}

int sort_paopao(int*array,int len)
{   
    int i = 0,j=0;
 
    sort_print(array,len);
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(&array[j],&array[j+1]);
            }
            
        }
    }
    sort_print(array,len);
}
int sort_print(int*array,int len)
{
    int i = 0;
    printf("data:   ");
    for(i=0;i<len;i++)
    {    
         printf("%d   ",array[i]);
    }
    printf("\n");
}
int sort_select(int*array,int len)
{
    int min = 0;
    int i = 0,j =0;
    sort_print(array,len);
    for(i=0;i<len-1;i++)
    {
        min = i;
        for(j=i;j<len-1;j++)
        {
            if(array[min]>array[j+1])
            {
                min = j+1;
            }
        }
        swap(&array[i],&array[min]);
    }
    sort_print(array,len);
}

#if 0
int sort_insert(int*array,int len)
{
    int i = 0,j =0;
    int tmp;
    sort_print(array,len);
    for(i=1;i<len;i++)
    {
        tmp = array[i];
        if(array[i-1]>array[i])
        {
             for(j=i;j>0;j--)
             {   
                 array[j]=array[j-1];
                 if(array[j-1]<tmp)
                 {
                   array[j]=tmp;
                   break;
                 }else if(j==1)
                 {
                    array[j-1]=tmp;
                 }
             }
        }
    }
    sort_print(array,len);
    return 0;
}
#endif
int sort_insert(int*array,int len)
{
    int i = 0,j =0;
    int tmp;
    for(i=1;i<len;i++)
    {
        tmp = array[i];
        if(array[i-1]>array[i])
        {    
             for(j=i;j>0 && array[j-1]>tmp;j--)
             {   
                array[j]=array[j-1];
             }
             array[j] = tmp;
        }
    }
    return 0;
}
//快速排序.
#if 0
int sort_quick(int*array,int start ,int end)
{
    int i=0,j=0;
    if(start>=end)
    {
        return 0;
    }
    int tmp = array[start];
    i = start;
    j = end;
    while( j!=i )
    {
        while(tmp<=array[j] && j>i)
        {
            j--;
        }
        while(tmp>=array[i] && i<j)
        {
            i++;
        }
        if(j>i)
        {
            swap(&array[i],&array[j]);
            printf("i = %d, j=%d \n",i,j);
            sleep(1);
        }
    } 
    swap(&array[start],&array[i]);
    sort_quick(array,start,i-1);
    sort_quick(array,i+1,end);
}
#endif

int sort_quick(int*array,int start ,int end)
{
    int i=0,j=0;
    if(start>=end)
    {
        return 0;
    }
    int tmp = array[start];
    i = start;
    j = end;
    while( j!=i )
    {
        while(tmp<=array[j] && j>i)
        {
            j--;
        }
        while(tmp>=array[i] && i<j)
        {
            i++;
        }
        if(j>i)
        {
            swap(&array[i],&array[j]);
            printf("i = %d, j=%d \n",i,j);
            sleep(1);
        }
    } 
    swap(&array[start],&array[i]);
    sort_quick(array,start,i-1);
    sort_quick(array,i+1,end);
}

#if 0
int sort_shell(int*arr,int len)
{
    int gap = len/2;
    int i,j,tmp;
    printf("len:%d\n",len);
    while(gap)
    {
        printf("gap:%d\n",gap);
        for(i=gap;i<len;i++)
        {
            tmp = arr[i];
            if(tmp<arr[i-gap])
            {
                for(j=i;j>=0;j=j-gap)
                {
                    arr[j] = arr[j-gap];
                    if(tmp>arr[j-gap])
                    {
                        arr[j] = tmp;
                        break;
                    }else if(j-gap<0)
                    {
                        arr[j] = tmp;
                    }
                }
            }
        }
        gap = gap/2;
    }
}
#endif
int sort_shell(int*arr,int len)
{
    int gap = len/2;
    int i,j,tmp;
    while(gap)
    {
        for(i=gap;i<len;i++)
        {
            tmp = arr[i];
            if(tmp<arr[i-gap])
            {
                printf("tmp:%d\n",tmp);
                for(j=i;j-gap>=0&&tmp<arr[j-gap];j=j-gap)//j-gap>=0;主要保证不越界 j=i 主要是偏移的第一个位置
                {
                    arr[j] = arr[j-gap];
                    printf("arr[%d]=%d\n",j,arr[j]);
                }
                arr[j] = tmp;
                sort_print(arr,len);
            }
        }
        gap = gap/2;
    }
}

int sort_apply()
{
    int array[] = {3,1,2,5,9,7,6,4,10,8};
    int len = sizeof(array)/sizeof(array[0]);
    //sort_paopao(a,len);
    //sort_select(array,len);
    //
    //sort_print(array,len);
    //sort_quick(array,0 ,len-1);
    sort_print(array,len);
    sort_shell(array,len);
    //sort_insert(array,len);
    sort_print(array,len);
    return 0;
}


