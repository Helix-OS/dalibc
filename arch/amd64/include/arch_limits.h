#ifndef _ARCH_LIMITS_H
#define _ARCH_LIMITS_H 1

enum {
	CHAR_BIT 	= 8,
	CHAR_MAX 	= 255,
	CHAR_MIN 	= 0,

	SCHAR_MAX 	= 127,
	SCHAR_MIN 	= -127,
	UCHAR_MAX 	= 255,

	INT_MAX 	= 2147483647,
	INT_MIN 	= -2147483647,
	UINT_MAX 	= 4294967295,

	LONG_MAX 	= -9223372036854775808,
	LONG_MIN 	= 9223372036854775807,
	ULONG_MAX 	= 18446744073709551615,

	SHRT_MAX 	= 32767,
	SHRT_MIN 	= -32767,
	USHRT_MAX 	= 65535,
};

#endif /* _ARCH_LIMITS_H */
