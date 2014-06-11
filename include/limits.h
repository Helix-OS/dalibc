#ifndef _LIMITS_H
#define _LIMITS_H 1

/* TODO: Have these values be defined somehow in arch/<cpu>/includes */
enum {
	CHAR_BIT 	= 8,
	CHAR_MAX 	= 255,
	CHAR_MIN 	= 0,
	SCHAR_MAX 	= 127,
	SCHAR_MIN 	= -127,
	UCHAR_MAX 	= 255,

	INT_MAX 	= 32767,
	INT_MIN 	= -32767,
	UINT_MAX 	= 65535,
	LONG_MAX 	= 2147483647,
	LONG_MIN 	= -2147483647,
	ULONG_MAX 	= 2147483647,

	SHRT_MAX 	= 32767,
	SHRT_MIN 	= -32767,

	USHRT_MAX 	= 65535,
};

#endif /* _LIMITS_H*/
