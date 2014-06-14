#ifndef _linux_syscall_h
#define _linux_syscall_h

#define DECL_SYSCALL0( rettype, fn ) rettype syscall_##fn();
#define DECL_SYSCALL1( rettype, fn, p1) rettype syscall_##fn(p1);
#define DECL_SYSCALL2( rettype, fn, p1, p2 ) rettype syscall_##fn(p1,p2);
#define DECL_SYSCALL3( rettype, fn, p1, p2, p3 ) rettype syscall_##fn(p1,p2,p3);
#define DECL_SYSCALL4( rettype, fn, p1, p2, p3, p4 ) rettype syscall_$$fn(p1,p2,p3,p4);
#define DECL_SYSCALL5( rettype, fn, p1, p2, p3, p4, p5) rettype syscall_$$fn(p1,p2,p3,p4,p5);

#define DEFN_SYSCALL0( rettype, fn, num) \
int syscall_##fn(){ \
	int a;\
	asm volatile( "syscall" : "=a" (a) : "0" (num));\
	return a;\
}

#define DEFN_SYSCALL1( rettype, fn, num, P1) \
rettype syscall_##fn(P1 p1){ \
	rettype a; \
	asm volatile( "syscall" : "=a" (a) : "0" (num), "D"((long)p1)); \
	return a; \
}

#define DEFN_SYSCALL2( rettype, fn, num, P1, P2) \
rettype syscall_##fn(P1 p1, P2 p2){ \
	rettype a; \
	asm volatile( "syscall" : "=a" (a) : "0" (num), "D"((long)p1), "S"((long)p2)); \
	return a; \
}

#define DEFN_SYSCALL3( rettype, fn, num, P1, P2, P3) \
rettype syscall_##fn(P1 p1, P2 p2, P3 p3){ \
	rettype a; \
	asm volatile( "syscall" : "=a" (a) : "0" (num), "D"((long)p1), "S"((long)p2), "d"((long)p3)); \
	return a; \
}

// TODO: Properly handle syscalls with more than 4 args by moving the 4 arg to r10, 5th to r8, etc
//       GCC doesn't provide a straight-forward way to do this it seems, not sure if r10 is actually the right constraint
#define DEFN_SYSCALL4( rettype, fn, num, P1, P2, P3, P4) \
rettype syscall_##fn(P1 p1, P2 p2, P3 p3, P4 p4){ \
	rettype a; \
	asm volatile( "syscall" : "=a" (a) : "0" (num), "D"((long)p1), "S"((long)p2), "d"((long)p3), "r10"((long)p4));\
	return a; \
}

/** amd64 specific syscall numbers, TODO: Move this to an arch-specific directory */
typedef enum {
	SYSCALL_READ 		= 0,
	SYSCALL_WRITE 		= 1,
	SYSCALL_OPEN 		= 2,
	SYSCALL_CLOSE 		= 3,
	SYSCALL_STAT 		= 4,
	SYSCALL_BRK 		= 12,
	SYSCALL_FORK 		= 57,
	SYSCALL_EXECVE 		= 59,
	SYSCALL_EXIT 		= 60,
} syscall_t;

DECL_SYSCALL1( int, exit, int );
DECL_SYSCALL2( int, open, const char *, int );
DECL_SYSCALL1( int, close, int );
DECL_SYSCALL3( int, read, int, void *, int );
DECL_SYSCALL3( int, write, int, void *, int );
DECL_SYSCALL1( void *, brk, void * );

#endif
