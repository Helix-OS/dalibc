#ifndef _CTYPE_H
#define _CTYPE_H 1

int isalpha( int c );
int isdigit( int c );
int isalnum( int c );

int iscntrl( int c );
int isgraph( int c );
int islower( int c );
int isupper( int c );
int isprint( int c );
int ispunct( int c );
int isspace( int c );
int isxdigit( int c );

int toupper( int c );
int tolower( int c );

#endif /* _CTYPE_H */
