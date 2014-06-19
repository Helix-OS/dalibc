#include <stdio.h>
#include <stdlib.h>

extern int main( int argc, char *argv[], char *envp[] );

void dalibc_linux_initialize( ){
	stdin  = malloc( sizeof( FILE ));
	stdout = malloc( sizeof( FILE ));
	stderr = malloc( sizeof( FILE ));

	if ( !stdin || !stdout || !stderr )
		;// abort( );

	memset( stdin, 0, sizeof( FILE ));
	memset( stdout, 0, sizeof( FILE ));
	memset( stderr, 0, sizeof( FILE ));

	stdin->filedesc = 0;
	stdout->filedesc = 1;
	stderr->filedesc = 2;
}

void dalibc_linux_deinitialize( ){
	free( stdin );
	free( stdout );
	free( stderr );
}

int dalibc_linux_enter_program( int argc, char *argv[], char *envp[] ){
	int ret;

	dalibc_linux_initialize( );
	ret = main( argc, argv, envp );
	dalibc_linux_deinitialize( );

	return ret;
}
