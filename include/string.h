#ifndef _STRING_H
#define _STRING_H 1
#include <stddef.h>

char *strcpy( char *dest, const char *src );
char *strncpy( char *dest, const char *src, size_t n );
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
int strcmp( const char *a, const char *b );
int strncmp( const char *a, const char *b, size_t n );

void *memcpy( void *dest, const void *src, size_t n );
void *memmove( void *dest, const void *src, size_t n );
int   memcmp( const void *a, const void *b, size_t n );
void *memchr( const void *s, int c, size_t n );
void *memset( void *s, int c, size_t n );

#endif /* _STRING_H */
