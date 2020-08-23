#include "logger.h"
#include "logger_internal.h"
#include <fcntl.h>
#include <stdio.h>//todo del

//int	logger_add_appender(const char *path)
//{
//	int fd;
//	int i;
//
//	fd = open(path, O_CREAT | O_APPEND | O_WRONLY);
//	if (fd < 0)
//	{
//		printf("[ERROR] <%s:%d> cannot open file %s\n", __FILE__, __LINE__, path);
//		return (-1);
//	}
//	i = 0;
//	while (g_logger.fds[i] > 0 && i < LOGGER_MAX_APPENDERS)
//	{
//		if (strcmp(g_logger.names[i], path) == 0)
//		{
//			printf("[WARN] file %s already added in logger\n", path);
//			return (0);
//		}
//		i++;
//	}
//	if (i == LOGGER_MAX_APPENDERS)
//	{
//		printf("[WARN] max names count is %i, cannot log to %s\n", LOGGER_MAX_APPENDERS, path);
//		return (0);
//	}
//	g_logger.fds[i] = fd;
//	g_logger.names[i] = path;
//	return (1);
//}
