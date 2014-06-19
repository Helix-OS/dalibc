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

int isdigit( int c ){
	return c >= '0' && c <= '9';
}

int isalnum( int c ){
	return isalpha( c ) || isdigit( c );
}

int isspace( int c ){
	return  c == ' '  || c == '\n' || c == '\r' || c == '\t' ||
		c == '\v' || c == '\f';
}

int isprint( int c ){
	return c >= ' ' && c != 0x7f;
}

int ispunct( int c ){
	return isprint( c ) && !isalnum( c ) && !isspace( c );
}

int isgraph( int c ){
	return isprint( c ) && !isspace( c );
}

int isxdigit( int c ){
	return isdigit( c ) ||
		( c >= 'a' && c <= 'f' ) ||
		( c >= 'A' && c <= 'F' );
}

int toupper( int c ){
	int ret = c;

	if ( islower( c ))
		ret = c + 0x20;

	return ret;
}

int tolower( int c ){
	int ret = c;

	if ( isupper( c ))
		ret = c - 0x20;

	return ret;
}
