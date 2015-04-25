#include <stdio.h>
#include <stdlib.h>
#include <dalibc/syscalls.h>

FILE *stdin, *stdout, *stderr;

int dalibc_get_modeflags( const char *mode ){
	int ret;

	// Yet another TODO: Add the proper "mode" numbers here
	if ( strcmp( mode, "r" ) == 0 )		ret = 0;
	else if ( strcmp( mode, "w" ) == 0 )	ret = 0;
	else if ( strcmp( mode, "a" ) == 0 )	ret = 0;
	else if ( strcmp( mode, "r+" ) == 0 )	ret = 0;
	else if ( strcmp( mode, "w+" ) == 0 )	ret = 0;
	else if ( strcmp( mode, "a+" ) == 0 )	ret = 0;

	return ret;
}

FILE *fopen( const char *filename, const char *mode ){
	FILE *ret;
	int fd;
	int flags = 0;


	flags = dalibc_get_modeflags( mode );
	fd = open( filename, flags );

	if ( fd >= 0 ){
		ret = malloc( sizeof( FILE ));

		if ( ret ){
			ret->filedesc = fd;
			ret->readp = ret->writep = ret->unget = 0;
			ret->permissions = flags;

		} else {
			; //abort( );
		}
	}

	return ret;
}

/* POSIX-specific call */
FILE *fdopen( int fd, const char *mode ){
	FILE *ret;
	int flags;

	ret = malloc( sizeof( FILE ));

	if ( ret ){
		ret->filedesc = fd;
		ret->readp = ret->writep = ret->unget = 0;
		ret->permissions = dalibc_get_modeflags( mode );
	}

	return ret;
}

FILE *freopen( const char *filename, const char *mode, FILE *stream );
FILE *fflush( FILE *stream );
int  fclose( FILE *stream ){
	int ret = -1;

	if ( stream )
		ret = close( stream->filedesc );

	return ret;
}

size_t fread( void *ptr, size_t size, size_t nobj, FILE *stream ){
	size_t ret = 0;
	size_t i, amount_read;

	if ( stream ){
		for ( i = 0; i < size * nobj; i += amount_read ){
			amount_read = read( stream->filedesc, ptr + i, size * nobj - i );

			if ( !amount_read )
				break;
		}

		ret = i;
		//ret = read( stream->filedesc, ptr, size * nobj );
	}

	return ret;
}

size_t fwrite( const void *ptr, size_t size, size_t nobj, FILE *stream ){
	size_t ret = 0;

	if ( stream ){
		ret = write( stream->filedesc, ptr, size * nobj );
	}

	return ret;
}
