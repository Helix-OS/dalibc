#include <stdlib.h>
#include <string.h>
#include <dalibc/syscalls.h>

// TODO: Implement an actual allocator, this is just for 
// debugging purposes

void *malloc( size_t size ){
	void *ret = NULL;

	ret = sbrk( size );

	return ret;
}

void *calloc( size_t nobj, size_t size ){
	void *ret = NULL;

	ret = sbrk( nobj * size );

	return ret;
}

void *realloc( void *p, size_t size ){
	void *ret = NULL;

	ret = sbrk( size );

	return ret;
}

void free( void *p ){
	return;
}
