#ifndef _TIME_H
#define _TIME_H 1
#include <stddef.h>

/* TODO: Move these to <sys/types.h> */
typedef unsigned long clock_t;
typedef unsigned long clock_t;

struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int isdst;
};

clock_t clock( void );
time_t time( time_t *tp );
double difftime( time_t time2, time_t time1 );
time_t mktime( struct tm *tp );
char *asctime( const struct tm *tp );
char *ctime( const time_t *tp );
struct tm *gmtime( const time_t *tp );
struct tm *localtime( const time_t *tp );
size_t strftime( char *s, size_t smax, const char *fmt, 
		const struct tm *tp );

#endif /* _TIME_H */
