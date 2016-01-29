#include <string.h>
#include <stdlib.h>

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

char *strcat( char *dest, const char *src ){
	char *ret = dest;
    size_t i;

	for ( i = 0; dest[i]; i++ );

    if ( i ) strcpy( dest + i - 1, src );
    else     strcpy( dest + i, src );

    dest[i] = 0;

	return ret;
}

char *strncat( char *dest, const char *src, size_t n ){
	char *ret = dest;
    size_t i;

	for ( i = 0; dest[i]; i++ );
	strncpy( dest + i, src, n );

    dest[i + n] = 0;

	return ret;
}

char *strchr( const char *haystack, int needle ){
	char *ret = NULL;
	unsigned i;
	int found = 0;

	for ( i = 0; haystack[i] && !found; i++ ){
		if ( haystack[i] == needle ){
			ret = haystack + i;
			found = 1;
		}
	}

	return ret;
}

char *strrchr( const char *haystack, int needle );

char *strpbrk( const char *s, const char *accept );

char *strstr( const char *haystack, const char *needle ){
	char *ret = NULL;
	int i, k;

	if ( haystack && needle ){
		for ( i = 0; haystack[i]; i++ ){
			for ( k = 0; haystack[i + k] && haystack[i + k] == needle[k]; k++ );

			if ( needle[k] == '\0' ){
				ret = (char *)haystack + i;
				break;
			}
		}
	}

	return ret;
} 

char *strtok( char *str, const char *delim );

size_t strspn( const char *s, const char *accept ){
	size_t i = 0;

	for ( ; s[i]; i++ ){
		size_t k;
		unsigned found = 0;

		for ( k = 0; accept[k]; k++ ){
			if ( accept[k] == s[i] ){
				found = 1;
				break;
			}
		}

		if ( !found )
			break;
	}

	return i;
}

size_t strcspn( const char *s, const char *reject );

size_t strlen( const char *s ){
	size_t ret = 0;

	if ( s )
		for ( ; s[ret]; ret++ );

	return ret;
}
	
char *strerror( int error );

int strcmp( const char *a, const char *b ){
	int ret = 0;
	int i;

	for ( i = 0; a[i] && b[i] && ( a[i] == b[i] ); i++ );

	if ( a[i] || b[i] )
		ret = ( a[i] > b[i] )? 1 : -1;

	return ret;
}

int strncmp( const char *a, const char *b, size_t n );

char *strdup( const char *s ){
	char *ret = malloc( strlen( s ) + 1 );
	strcpy( ret, s );
	return ret;
}

void *memcpy( void *dest, const void *src, size_t n ){
	char *dest_bytes = dest;
	const char *src_bytes = src;

	while (n--) {
		*(dest_bytes++) = *(src_bytes++);
	}

	return dest;
}

void *memmove( void *dest, const void *src, size_t n );
int   memcmp( const void *a, const void *b, size_t n );
void *memchr( const void *s, int c, size_t n );

void *memset( void *s, int c, size_t n ){
	char *dest = s;
	size_t i;

	for ( i = 0; i < n; i++ )
		dest[i] = (char)c;

	return dest;
}
