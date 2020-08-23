#include <time.h>
#include "time_internal.h"

int	time_is_leap_year(unsigned year)
{
	return (!((year) % 4) && (((year) % 100) || !((year) % 400)));
}

int	time_year_size(unsigned year)
{
	return (time_is_leap_year(year) ? 366 : 365);
}
