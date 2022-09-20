#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ioctl.h>


#define  LED_IMAGIC  'L'
#define LED_ON    _IOW(LED_IMAGIC,1,int)
#define LED_OFF   _IOW(LED_IMAGIC,2,int)

int main()
{
	int fd = 0;
	fd = open("/dev/led",O_RDWR);
	if(fd<0)
	{
        	perror("open fail");
		exit(1);
	}
	printf("led open ok\n");
	while(1)
	{
		ioctl(fd ,LED_ON);
		usleep(500000);
		ioctl(fd ,LED_OFF);
		usleep(500000);
	}
      
}
































