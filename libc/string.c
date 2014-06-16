#include <string.h>

char *strcpy( char *dest, const char *src ){
	unsigned i;

	for ( i = 0; src[i]; i++ )
		dest[i] = src[i];

	dest[i] = 0;

	return dest;
}

char *strncpy( char *dest, const char *src, size_t n ){
	size_t i;

	for ( i = 0; src[i] && i < n; i++ )
		dest[i] = src[i];

	if ( i < n )
		dest[i] = 0;

	return dest;
}

char *strcat( char *dest, const char *src );
char *strncat( char *dest, const char *src, size_t n );

char *strchr( const char *haystack, int needle );
char *strrchr( const char *haystack, int needle );

char *strpbrk( const char *s, const char *accept );
char *strstr( const char *haystack, const char *needle );
char *strtok( char *str, const char *delim );

size_t strspn( const char *s, const char *accept );
size_t strcspn( const char *s, const char *reject );
size_t strlen( const char *s );
char *strerror( int error );

int strcmp( const char *a, const char *b ){
	int ret = 0;
	int i;

	for ( i = 0; a[i] == b[i]; i++ );

	if ( a[i] || b[i] )
		ret = ( a[i] > b[i] )? 1 : -1;

	return ret;
}

int strncmp( const char *a, const char *b, size_t n );

void *memcpy( void *dest, const void *src, size_t n );
void *memmove( void *dest, const void *src, size_t n );
int   memcmp( const void *a, const void *b, size_t n );
void *memchr( const void *s, int c, size_t n );
void *memset( const void *s, int c, size_t n );
