#ifndef LOGGER_INTERNAL_H
#define LOGGER_INTERNAL_H

# include <stdarg.h>
# include <stdlib.h>
# include "logger.h"

typedef struct	s_log_event
{
	int			level;
	int			line;
	const char	*file;
	const char	*fmt;
	va_list		ap;
}				t_log_event;

typedef struct	s_appender
{
	int			level;
	int			quiet;
	int			color;
	int			fd;
	const char	*file;
	const char	*name;
}				t_appender;

typedef struct	s_logger
{
	int			level;
	int			quiet;
	int			color;
	t_appender	appenders[LOGGER_MAX_APPENDERS];
}				t_logger;

static const t_appender	g_stdout_appender = {
											.level = LOG_LEVEL_INFO,
											.fd = 1,
											.name = "STDOUT"
											};

static const t_appender	g_stderr_appender = {
											.level = LOG_LEVEL_WARN,
											.fd = 2,
											.name = "STDERR"
											};

static const t_logger	g_logger = {
									.level = LOG_LEVEL_INFO,
									.color = 0,
									.quiet = 0
									};

#endif
