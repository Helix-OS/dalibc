#include <stdio.h>
#include <stdlib.h>

extern int main( int argc, char *argv[], char *envp[] );

void dalibc_helix_initialize( ){
	stdin  = fdopen( 0, "r" );
	stdout = fdopen( 1, "r" );
	stderr = fdopen( 2, "r" );

	// maybe possibly sort of properly do std* files
	//stdin  = fopen( "/test/devices/keyboard", "r" );
	//stdout = fopen( "/test/devices/console", "w" );
	//stderr = fopen( "/test/devices/console", "w" );

	if ( !stdin || !stdout || !stderr )
		*((int *)0xa0000000) = 1; // just crash
	    // abort( ); // This is what should be done
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
