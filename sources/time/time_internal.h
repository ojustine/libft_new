#ifndef TIME_INTERNAL_H
#define TIME_INTERNAL_H

#define YEAR0					1900
#define DAY0					4
#define EPOCH_YR				1970
#define SECS_DAY				(24L * 60L * 60L)

const int _ytab[2][12] =
{
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int	time_is_leap_year(unsigned year);
int	time_year_size(unsigned year);

#endif
