#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<string.h>


#define  LED_IMAGIC  'L'
#define LED_ON    _IOW(LED_IMAGIC,1,int)
#define LED_OFF   _IOW(LED_IMAGIC,2,int)

int main()
{
	int fd = 0;
	char  buff[] = "let's go";
	fd = open("/dev/uart",O_RDWR);
	if(fd<0)
	{
        	perror("open fail");
		exit(1);
	}
	printf("led open ok\n");

	write(fd,buff,sizeof(buff));
	printf("write buf %s\n",buff);
	memset(buff,0,sizeof(buff));
	read(fd,buff,sizeof(buff));
	//printf("read buf %s\n",buff);

	
      return 0;
}
































