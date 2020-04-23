#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <linux/input.h>



 int main(void)
 {
	int fd = open("/dev/ubuntu_event", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	
	struct input_event data;
	while(1)
	{
		read(fd, &data, sizeof(data));
		printf("type=%hd  code=%hd  value=%d\n", data.type, data.code, data.value);
	}

	close(fd);
 
	return 0;
	 
 }


