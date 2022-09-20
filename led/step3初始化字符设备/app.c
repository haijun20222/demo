#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ioctl.h>

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

}
































