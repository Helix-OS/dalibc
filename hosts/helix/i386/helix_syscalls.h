#ifndef _helix_syscall_h
#define _helix_syscall_h

#define DECL_SYSCALL0( rettype, fn ) rettype syscall_##fn();
#define DECL_SYSCALL1( rettype, fn, p1) rettype syscall_##fn(p1);
#define DECL_SYSCALL2( rettype, fn, p1, p2 ) rettype syscall_##fn(p1,p2);
#define DECL_SYSCALL3( rettype, fn, p1, p2, p3 ) rettype syscall_##fn(p1,p2,p3);
#define DECL_SYSCALL4( rettype, fn, p1, p2, p3, p4 ) rettype syscall_$$fn(p1,p2,p3,p4);
#define DECL_SYSCALL5( rettype, fn, p1, p2, p3, p4, p5) rettype syscall_$$fn(p1,p2,p3,p4,p5);

#define DEFN_SYSCALL0( rettype, fn, num) \
rettype syscall_##fn(){ \
	rettype a;\
	asm volatile( "int $0x50" : "=a" (a) : "0" (num));\
	return a;\
}

#define DEFN_SYSCALL1( rettype, fn, num, P1) \
rettype syscall_##fn(P1 p1){ \
	rettype a; \
	asm volatile( "int $0x50" : "=a" (a) : "0" (num), "b"((int)p1)); \
	return a; \
}

#define DEFN_SYSCALL2( rettype, fn, num, P1, P2) \
rettype syscall_##fn(P1 p1, P2 p2){ \
	rettype a; \
	asm volatile( "int $0x50" : "=a" (a) : "0" (num), "b"((int)p1), "c"((int)p2)); \
	return a; \
}

#define DEFN_SYSCALL3( rettype, fn, num, P1, P2, P3) \
rettype syscall_##fn(P1 p1, P2 p2, P3 p3){ \
	rettype a; \
	asm volatile( "int $0x50" : "=a" (a) : "0" (num), "b"((int)p1), "c"((int)p2), "d"((int)p3)); \
	return a; \
}

#define DEFN_SYSCALL4( rettype, fn, num, P1, P2, P3, P4) \
rettype syscall_##fn(P1 p1, P2 p2, P3 p3, P4 p4){ \
	rettype a; \
	asm volatile( "int $0x50" : "=a" (a) : "0" (num), "b"((int)p1), "c"((int)p2), "d"((int)p3), "S"((int)p4));\
	return a; \
}

typedef struct dirent {
	unsigned 	inode;
	unsigned 	offset;
	unsigned 	length;
	unsigned 	type;

	char 		name[256];
} dirent_t;

typedef enum {
	SYSCALL_TEST,
	SYSCALL_EXIT,
	SYSCALL_OPEN,
	SYSCALL_CLOSE,
	SYSCALL_READ,
	SYSCALL_WRITE,
	SYSCALL_SPAWN,
	SYSCALL_READDIR,
	SYSCALL_WAITPID,
	SYSCALL_SBRK,
	SYSCALL_CHROOT,
	SYSCALL_CHDIR,
	SYSCALL_SYSINFO,
	SYSCALL_LSEEK,
	SYSCALL_PIPE,
	SYSCALL_FCNTL,
	SYSCALL_POLL,
	//SYSCALL_FSTAT,
} syscall_t;

DECL_SYSCALL0( int, test );
DECL_SYSCALL1( int, exit, int );
DECL_SYSCALL2( int, open, const char *, int );
DECL_SYSCALL1( int, close, int );
DECL_SYSCALL3( int, read, int, void *, int );
DECL_SYSCALL3( int, write, int, const void *, int );
DECL_SYSCALL4( int, spawn, int, char **, char **, int * );
DECL_SYSCALL3( int, waitpid, unsigned, int *, int );
DECL_SYSCALL3( int, readdir, int, dirent_t *, int );
DECL_SYSCALL1( void *, sbrk, int );
DECL_SYSCALL1( int, chroot, const char * );
DECL_SYSCALL1( int, chdir, const char * );
DECL_SYSCALL3( int, sysinfo, unsigned, unsigned, void * );
DECL_SYSCALL3( int, lseek, int, long, int );
DECL_SYSCALL1( int, pipe, int * );
DECL_SYSCALL3( int, fcntl, int, int, int );
DECL_SYSCALL3( int, poll, void *, unsigned, int );

#endif
