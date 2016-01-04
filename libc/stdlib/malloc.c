#include <stdlib.h>
#include <string.h>
#include <dalibc/syscalls.h>
#include <dalibc/umalloc.h>

// TODO: Implement an actual allocator, this is just for 
// debugging purposes

uheap_t __global_heap;

void *malloc( size_t size ){
	void *ret = NULL;

	ret = uheap_alloc( &__global_heap, size );

	return ret;
}

void *calloc( size_t nobj, size_t size ){
	void *ret = NULL;

	ret = malloc( nobj * size );
	if ( ret ){
		memset( ret, 0, nobj * size );
	}

	return ret;
}

void *realloc( void *p, size_t size ){
	void *ret = NULL;

	ret = uheap_realloc( &__global_heap, size );

	return ret;
}

void free( void *p ){
	uheap_free( &__global_heap, p );
}
