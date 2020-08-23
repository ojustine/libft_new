#include <time.h>
#include "time_internal.h"

time_t		time_get_unix(time_t *timer)
{
	return time(timer);
}

struct tm	*time_get_utc(const time_t *timer, struct tm *restrict tmbuf)
{
	const int				day_seconds = (int)(*timer % SECS_DAY);
	register unsigned long	days;
	register int			year;

	days = (unsigned long) *timer / SECS_DAY;
	tmbuf->tm_sec = day_seconds % 60;
	tmbuf->tm_min = (day_seconds % 3600) / 60;
	tmbuf->tm_hour = day_seconds / 3600;
	tmbuf->tm_wday = (int)((days + DAY0) % 7);
	year = EPOCH_YR;
	while (days >= (unsigned long) time_year_size(year))
		days -= time_year_size(year++);
	tmbuf->tm_year = year - YEAR0;
	tmbuf->tm_yday = (int)days;
	tmbuf->tm_mon = 0;
	while (days >= (unsigned long)_ytab[time_is_leap_year(year)][tmbuf->tm_mon])
	{
		days -= _ytab[time_is_leap_year(year)][tmbuf->tm_mon];
		tmbuf->tm_mon++;
	}
	tmbuf->tm_mday = (int)days + 1;
	tmbuf->tm_isdst = 0;
	tmbuf->tm_gmtoff = 0;
	tmbuf->tm_zone = "UTC";
	return (tmbuf);
}

struct tm	*time_get_local(const time_t *timer, struct tm *restrict tmbuf)
{
	time_t time;

	tzset();
	time = *timer - timezone;
	return (time_get_utc(&time, tmbuf));
}
