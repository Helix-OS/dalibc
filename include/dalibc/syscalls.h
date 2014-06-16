#ifndef _DALIBC_SYSCALLS_H
#define _DALIBC_SYSCALLS_H 1

void _exit( int error );
int _spawn( char *name, char **argv, char **envp );

int open( const char *name, int flags );
int close( int descript );
int read( int descript, void *ptr, int len );
int write( int descript, const void *ptr, int len );

void *sbrk( int increment );

#endif
