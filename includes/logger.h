#ifndef LOGGER_H
# define LOGGER_H

# define LOGGER_MAX_APPENDERS	8
# define LOGGER_TIME
# define LOGGER_COLOR

/*
**	Description:
**	Just a simple logger for C-development.
**	A log request of level R in a logger with level L is enabled if R >= L.
**	Levels are ordered: ALL<TRACE<DEBUG<INFO<NOTICE<WARN<ERROR<FATAL<OFF.
**	All messages with a level less than or equal to NOTICE are sent to STDOUT.
**	All messages with a level greater than or equal to WARN are sent to STDERR.
*/

/*
**	Features:
**	Messages can be formatted as in the standard libc function printf.
**	The logger has the function of writing all logs to several names,
**	  no more than 8 by default.
**	If "quiet" mode is enabled, then logs are written only to the names,
**	  not to the standard output streams.
**	If LOGGER_COLOR macro is defined and "color" mode is enabled,
**	  output to standard streams is formatted with ansi colors (only for bash).
**	If a LOGGER_TIME macro is defined and a valid template is passed,
**	  includes time information in each message (man 3 strftime).
*/

enum	e_log_levels
{
	LOG_LEVEL_ALL,
	LOG_LEVEL_TRACE,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_NOTICE,
	LOG_LEVEL_WARN,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_FATAL,
	LOG_LEVEL_OFF
};

int		logger_add_appender(const char *path);
void	logger_close_appender(const char *path);
void	logger_close_file_last();

void	logger_set(int lvl, const char *time_pattern, int quiet, int color);
void	logger_set_quiet(int quiet);
void	logger_set_color(int color);
void	logger_set_time_pattern(const char *time_pattern);
void	logger_set_level(int lvl);

void	log_log(int lvl, const char *appender, char *fmt, ...);
void	log_all(int lvl, char *fmt, ...);//for stds and apps
void	log_trace(char *fmt, ...);//for stds
void	log_debug(char *fmt, ...);
void	log_info(char *fmt, ...);
void	log_notice(char *fmt, ...);
void	log_warn(char *fmt, ...);
void	log_error(char *fmt, ...);
void	log_fatal(char *fmt, ...);

void	logger_exit(void);

#endif
