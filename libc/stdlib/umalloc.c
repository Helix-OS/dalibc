/* dumb malloc implemention relying on sbrk() */

//#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <dalibc/umalloc.h>
#include <dalibc/syscalls.h>

static inline heap_block_t *uheap_get_memblock( void *ptr ){
	heap_block_t *temp = (heap_block_t *)((uintptr_t)ptr - sizeof( heap_block_t ));
	
	return temp;
}


void *uheap_alloc( uheap_t *heap, unsigned size ){
	unsigned adjusted = size + sizeof( heap_block_t );
	unsigned binnum = adjusted / BLOCK_SIZE + !!(adjusted % BLOCK_SIZE);
	void *ret = NULL;

	if ( binnum < NUM_BINS ){
		heap_block_t *temp;
		//printf( "Allocating %u bytes in bin %u\n", binnum * BLOCK_SIZE, binnum );

		if ( heap->bins[binnum] ){
			temp = heap->bins[binnum];
			heap->bins[binnum] = temp->next;

		} else {
			unsigned real_size = binnum * BLOCK_SIZE;

			temp = sbrk( real_size );
			temp->size = real_size;
			temp->next = NULL;
		}

		ret = (void *)((uintptr_t)temp + sizeof(heap_block_t));
	}

	return ret;
}

void uheap_free( uheap_t *heap, void *ptr ){
	if ( ptr ){
		//heap_block_t *temp = (heap_block_t *)((uintptr_t)ptr - sizeof( heap_block_t ));
		heap_block_t *temp = uheap_get_memblock( ptr );
		unsigned binnum = temp->size / BLOCK_SIZE;

		//printf( "Freeing block of size %u into bin %u\n", temp->size, binnum );

		temp->next = heap->bins[binnum];
		heap->bins[binnum] = temp;
	}
}

void *uheap_realloc( uheap_t *heap, void *ptr, unsigned size ){
	void *ret = NULL;

	if ( ptr ){
		heap_block_t *temp = uheap_get_memblock( ptr );

		if ( size != temp->size ){
			ret = uheap_alloc( heap, size );
			memcpy( ret, ptr, (size < temp->size)? size : temp->size );
			uheap_free( heap, ptr );

		} else {
			ret = ptr;
		}
	}

	return ret;
}
