#include <errno.h>
#include <dalibc/syscalls.h>
#include <helix_syscalls.h>


DEFN_SYSCALL0( int, test, SYSCALL_TEST );
DEFN_SYSCALL1( int, exit, SYSCALL_EXIT, int );
DEFN_SYSCALL2( int, open, SYSCALL_OPEN, const char *, int );
DEFN_SYSCALL1( int, close, SYSCALL_CLOSE, int );
DEFN_SYSCALL3( int, read, SYSCALL_READ, int, void *, int );
DEFN_SYSCALL3( int, write, SYSCALL_WRITE, int, const void *, int );
DEFN_SYSCALL4( int, spawn, SYSCALL_SPAWN, int, char **, char **, int );
DEFN_SYSCALL3( int, readdir, SYSCALL_READDIR, int, dirent_t *, int );
DEFN_SYSCALL3( int, waitpid, SYSCALL_WAITPID, unsigned, int *, int );
DEFN_SYSCALL1( void *, sbrk, SYSCALL_SBRK, int );
DEFN_SYSCALL1( int, chroot, SYSCALL_CHROOT, const char * );
DEFN_SYSCALL1( int, chdir, SYSCALL_CHDIR, const char * );
DEFN_SYSCALL3( int, sysinfo, SYSCALL_SYSINFO, unsigned, unsigned, void * );

void _exit( int error ){
	syscall_exit( error );
	return;
}

int _spawn( char *name, char **argv, char **envp ){
	int fd = open( name, 1 );
	int ret = -1;
	if ( fd >= 0 )
		ret = syscall_spawn( fd, argv, envp, 0 );

	return ret;
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

int write( int descript, const void *ptr, int len ){
	return syscall_write( descript, ptr, len );
} 

void *sbrk( int increment ){
	return syscall_sbrk( increment );
}
