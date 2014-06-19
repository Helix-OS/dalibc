#include <ctype.h>

int isalpha( int c ){
	return islower( c ) || isupper( c );
}

int islower( int c ){
	return c >= 'a' && c <= 'z';
}

int isupper( int c ){
	return c >= 'A' && c <= 'Z';
}
