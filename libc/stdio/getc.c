#include <stdio.h>

int fgetc( FILE *stream ){
	char ret;
	int temp;

	if ( stream->has_unget == 1 ){
		ret = stream->unget;
		stream->has_unget = 0;

	} else {
		temp = fread( &ret, 1, 1, stream );
	}

	if ( temp < 0 ){
		ret = temp;
	}

	return ret;
}

char *fgets( char *s, int n, FILE *stream ){
	char *ret = NULL;
	int i;
	int c = 1;

	for ( i = 0; i < n && c != '\n' && c > 0; i++ ){
		c = fgetc( stream );
		s[i] = c;
	}

	s[i] = 0;

	ret = i? s : NULL;

	return ret;
}

int fputc( int c, FILE *stream ){
	fwrite( &c, 1, 1, stream );
	return c;
}

int fputs( const char *s, FILE *stream ){
	int ret = 1;

	ret += fwrite( s, strlen( s ), 1, stream );
	fputc( '\n', stream );

	return ret;
}
	
int getc( FILE *stream ){
	return fgetc( stream );
}

int getchar( void ){
	return fgetc( stdin );
}

char *gets( char *s );

int putc( int c, FILE *stream ){
	return fputc( c, stream );
}

int putchar( int c ){
	return fputc( c, stdout );
}

int puts( const char *s ){
	return fputs( s, stdout );
}

int ungetc( int c, FILE *stream ){
	stream->unget = c;
	stream->has_unget = 1;

	return c;
}
