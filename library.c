#include <stdio.h>
#include <zconf.h>
#include "logger.h"
#include <time.h>
#include <fcntl.h>

int main(void)
{
	char file[10];
//	memcpy(file, "logger.log", sizeof("logger.log"));
//	logger_add_appender(file);
//	memset(file, '1', sizeof("logger.log"));
//	logger_add_appender(file);
//	logger_add_appender("logger.log");
int fd;

	clock_t start = clock();
	printf("");
	fd = open("CMakeFiles", O_CREAT | O_APPEND | O_RDWR, 0600);
	for (int i = 0; i < 10000; i++)
	{
		write(fd, "0", 1);
	}
	close(fd);
	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("%f", seconds);
}
