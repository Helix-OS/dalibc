#ifndef _DALIBC_SYSCALLS_H
#define _DALIBC_SYSCALLS_H 1

typedef enum {
	SEEK_SET,
	SEEK_CUR,
	SEEK_END,
} file_seek_t;

enum {
	F_NOP,
	F_GETFL,
	F_SETFL,
};

enum {
	O_READ     = 1,
	O_WRITE    = 2,
	O_CREATE   = 4,
	O_TRUNCATE = 8,
	O_NONBLOCK = 16,
};

enum {
	POLLIN    = 1,
	POLLPRI   = 2,
	POLLOUT   = 4,
	POLLRDHUP = 8,
	POLLERR   = 16,
	POLLNVAL  = 32,
};

typedef struct pollfd {
	int fd;
	unsigned short events;
	unsigned short revents;
} pollfd_t;

void _exit( int error );
int _spawn( char *name, char **argv, char **envp, int fds[3] );

int open( const char *name, int flags );
int close( int descript );
int read( int descript, void *ptr, int len );
int write( int descript, const void *ptr, int len );

void *sbrk( int increment );
int lseek( int fd, long offset, int whence );
int pipe( int fds[2] );
int fcntl( int fd, int command, int arg );
int poll( pollfd_t *fds, unsigned nfds, int timeout );

#endif
