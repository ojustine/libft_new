#include "logger_internal.h"
#include <stdio.h>//todo del

void	log_trace(char *mess, ...)
{
	t_log_event	event;

	event.fmt = mess;
	event.line = 0;
	event.file = NULL;
	event.level = LOG_LEVEL_TRACE;
	va_start(event.ap, mess);
	vprintf(mess, event.ap);
}
