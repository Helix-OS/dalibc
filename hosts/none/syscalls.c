#include <errno.h>
#include <dalibc/syscalls.h>

void _exit( int error ){
	// This can't possibly end well
	return;
}

int _spawn( char *name, char **argv, char **envp ){
	errno = ENOMEM;
	return -1;
}

int open( const char *name, int flags ){
	return -1;
}

int close( int descript ){
	return -1;
}

int read( int descript, void *ptr, int len ){
	return 0;
}

int write( int descript, const void *ptr, int len ){
	return 0;
} 

void *sbrk( int increment ){
	errno = ENOMEM;
	return (void *)-1;
}
