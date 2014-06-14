#include <errno.h>
#include <dalibc/syscalls.h>
#include <linux_syscalls.h>

DEFN_SYSCALL1( int, exit, SYSCALL_EXIT, int );
DEFN_SYSCALL2( int, open, SYSCALL_OPEN, const char *, int );
DEFN_SYSCALL1( int, close, SYSCALL_CLOSE, int );
DEFN_SYSCALL3( int, read, SYSCALL_READ, int, void *, int );
DEFN_SYSCALL3( int, write, SYSCALL_WRITE, int, void *, int );
DEFN_SYSCALL1( void *, brk, SYSCALL_BRK, void * );

void _exit( int error ){
	syscall_exit( error );
	return;
}

int _spawn( char *name, char **argv, char **envp ){
	errno = ENOMEM;
	return -1;
}

int open( const char *name, int flags ){
	return syscall_open( name, flags );
}

int close( int descript ){
	return syscall_close( descript );
}

int read( int descript, void *ptr, int len ){
	return syscall_read( descript, ptr, len );
}

int write( int descript, void *ptr, int len ){
	return syscall_write( descript, ptr, len );
} 

static char *initial_placement = 0;
void *sbrk( int increment ){
	char *new_placement;
	void *ret;

	if ( initial_placement ){
		new_placement += increment;

		if ( initial_placement == (void *)syscall_brk( initial_placement )){
			ret = (void *)-1;
			errno = ENOMEM;
		} else {
			ret = new_placement;
		}

	} else {
		initial_placement = ret = (void *)syscall_brk( (void *)-1 );
	}

	return ret;
}
