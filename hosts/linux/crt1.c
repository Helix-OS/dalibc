#include <stdio.h>
#include <stdlib.h>

extern int main( int argc, char *argv[], char *envp[] );

void dalibc_linux_initialize( ){
	stdin  = fdopen( 0, "r" );
	stdout = fdopen( 1, "r" );
	stderr = fdopen( 2, "r" );

	if ( !stdin || !stdout || !stderr )
		;// abort( );
}

void dalibc_linux_deinitialize( ){
	fclose( stdin );
	fclose( stdout );
	fclose( stderr );
}

int dalibc_linux_enter_program( int argc, char *argv[], char *envp[] ){
	int ret;

	dalibc_linux_initialize( );
	ret = main( argc, argv, envp );
	dalibc_linux_deinitialize( );

	return ret;
}
