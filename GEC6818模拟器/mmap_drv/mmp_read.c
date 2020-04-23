#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

 int main(void)
 {
	int fd = open("/dev/ubuntu_lcd", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	
	char *paddr = (char *)mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, fd,  0);
	if(MAP_FAILED == paddr)
	{
		perror("mmap");
		exit(1);
	}
	char rbuf[128]={0};
	printf("\033[2J");
	while(1)
	{		
		memcpy(rbuf, paddr, 128);
		printf("\033[1;10H\033[0Jrbuf = %s\n", rbuf);
		memset(rbuf,0, 128);
		usleep(5000);
	}


 
	return 0;
	 
 }


