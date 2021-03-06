#ifndef _STDLIB_H
#define _STDLIB_H 1
#include <stddef.h>

typedef struct div {
	int quot;
	int rem;
} div_t;

typedef struct ldiv {
	long quot;
	long rem;
} ldiv_t;

double atof( const char *s );
int    atoi( const char *s );
long   atol( const char *s );
double strtod( const char *s, char **endp );
long   strtol( const char *s, char **endp, int base );
unsigned long strtoul( const char *s, char **endp, int base );

int rand( void );
int srand( unsigned int seed );

void *calloc( size_t nobj, size_t size );
void *malloc( size_t size );
void *realloc( void *p, size_t size );
void free( void *p );

void abort( void );
void exit( int status );
int atexit( void (*fcn)( void ));
int system( const char *s );
char *getenv( const char *name );

char *hsearch( const void *key, const void *base, size_t n, size_t size, 
		int (*cmp)( const void *keyval, const void *datum ));
void qsort( void *base, size_t n, size_t size, int (*cmp)( const void *, const void * ));

int abs( int n );
long labs( long n );
div_t div( int num, int denom );
ldiv_t ldiv( long num, long denom );

#endif /* _STDLIB_H */
