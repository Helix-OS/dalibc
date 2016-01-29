#include <stdlib.h>
#include <dalibc/syscalls.h>

void exit( int status ){
	// TODO: do cleanup here
	_exit( status );
}

int atoi( const char *s ){
	int ret = 0;
	size_t i;

	for ( i = 0; s[i] && s[i] >= '0' && s[i] <= '9'; i++ ){
		ret *= 10;
		ret += s[i] - '0';
	}

	return ret;
}
