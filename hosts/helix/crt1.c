#include <stdio.h>
#include <stdlib.h>
#include <dalibc/umalloc.h>

extern int main( int argc, char *argv[], char *envp[] );
extern uheap_t __global_heap;

void dalibc_helix_initialize( ){
	memset( &__global_heap, 0, sizeof( uheap_t ));

	stdin  = fdopen( 0, "r" );
	stdout = fdopen( 1, "w" );
	stderr = fdopen( 2, "w" );

	if ( !stdin || !stdout || !stderr )
		*((int *)0xa0000000) = 1; // just crash
	    // TODO: implement abort()
}

void dalibc_helix_deinitialize( ){
	fclose( stdin );
	fclose( stdout );
	fclose( stderr );
}

int dalibc_helix_enter_program( int argc, char *argv[], char *envp[] ){
	int ret;

	dalibc_helix_initialize( );
	ret = main( argc, argv, envp );
	dalibc_helix_deinitialize( );

	return ret;
}
