#include <stdio.h>

int fgetc( FILE *stream ){
	char ret;

	fread( &ret, 1, 1, stream );

	return ret;
}

char *fgets( char *s, int n, FILE *stream );

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

int ungetc( int c, FILE *stream );
