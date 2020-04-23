#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>


void mem_set(unsigned int *p, unsigned int color)
{
	for(int i=0; i<800*480; i++)
	{
		memcpy(p+i, &color, 4);		
	}
}

 int main(void)
 {
	int fd = open("/dev/ubuntu_lcd", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	unsigned int *paddr = (unsigned int *)mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, fd,  0);
	if(MAP_FAILED == paddr)
	{
		perror("mmap");
		exit(1);
	}
	//char *test_data = "hello world";
	//memcpy(paddr+4000, test_data, strlen(test_data));
 
	//测试是否成功
	//sleep(1);
	char wbuf[128]={0};
	unsigned int red=0x00ff0000;
	unsigned int green = 0x0000ff00;
	unsigned int blue = 0x000000ff;
	while(1)
	{
		//scanf("%s", wbuf);
		//if(strcmp(wbuf,"red") == 0)
		{
			mem_set(paddr,red);
			usleep(50000);
		}//else if(strcmp(wbuf, "green")==0)
		{
			mem_set(paddr,green);
			usleep(50000);
		}//else
		{
			mem_set(paddr,blue);
			usleep(50000);
		}
		//memcpy(paddr, wbuf, strlen(wbuf));
	}

 
	return 0;
	 
 }


