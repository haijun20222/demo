#include"stdlib.h"
#include"stdio.h"
#include<pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;
int a = 0;
int b = 0;


void fun_a()
{
    while (1)
    {
    pthread_mutex_lock(&mutex_a);
    //pthread_mutex_lock(&mutex_b);
    a++;
    printf("a:%d \r\n",a);
    //pthread_mutex_unlock(&mutex_a);
    usleep(1000);
    }
    return 0;
}


void fun_b()
{
    while (1)
    {
        pthread_mutex_lock(&mutex_a);
        a++;
        printf("a:%d \r\n",a);
        pthread_mutex_unlock(&mutex_a);
        usleep(1000);
    }
    return 0;
}



void test_lock()
{

    pthread_t pt_a;
    pthread_t pt_b;

    pthread_mutex_init(&mutex);
    pthread_create(&pt_a,NULL,fun_a,NULL);
    pthread_create(&pt_a,NULL,fun_b,NULL);

    pthread_join(pt_a,NULL);
    pthread_join(pt_b,NULL);

}



int main()
{
    test_lock();


}
