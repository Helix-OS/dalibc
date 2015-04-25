#include <stdio.h>
#include <stdarg.h>

void print_num( unsigned input, char *out ){
	unsigned i, a;
	char buf[32];

	if ( !input ){
		//buf[0] = '0';
		//write_serial( buf, 1 );
		out[0] = '0';
		out[1] = 0;
		return;
	}

	for ( i = 0, a = input; a; a = a / 10 ){
		buf[i++] = a % 10 + '0';
	}

	for ( a = 0; i--; a++ ){
		out[a] = buf[i];
	}
	out[a] = 0;
}

void print_hex( unsigned input, char *out ){
	unsigned i, a;
	char *hextab = "0123456789abcdef";
	char buf[32];

	if ( !input ){
		out[0] = '0';
		out[1] = 0;
		//buf[0] = '0';
		//write_serial( buf, 1 );
		return;
	}

	for ( i = 0, a = input; a; a = a / 16 ){
		buf[i++] = hextab[ a % 16 ];
	}

	for ( a = 0; i--; a++ ){
		out[a] = buf[i];
	}
	out[a] = 0;
}


int vfprintf( FILE *stream, const char *format, va_list arg ){
	int slen = strlen( format );
	int ret = 0;

	unsigned un;
	char c, *str;
	int buf, i;
	char num[32];

	for ( i = 0; i < slen; i++ ){
		if ( format[i] == '%' ){
			switch( format[++i] ){
				case '%':
					ret += fwrite( "%", 1, 1, stream );
					break;

				case 'c':
					c = va_arg( arg, int );
					ret += fwrite( &c, 1, 1, stream );
					break;

				case 's':
					str = va_arg( arg, char * );
					ret += fwrite( str, strlen( str ), 1, stream );
					break;

				case 'd':
					un = va_arg( arg, unsigned );
					print_num( un, num );
					fwrite( num, strlen( num ), 1, stream );
					break;

				case 'u':
					un = va_arg( arg, unsigned );
					print_num( un, num );
					fwrite( num, strlen( num ), 1, stream );
					break;

				case 'x':
					un = va_arg( arg, unsigned );
					print_hex( un, num );
					fwrite( num, strlen( num ), 1, stream );
					break;

				default:
					break;
			}

		} else {
			ret += fwrite( format + i, 1, 1, stream );
		}
	}

	return ret;
}


int vprintf( const char *format, va_list arg ){
	return vfprintf( stdout, format, arg );
}

int vsprintf( char *s, const char *format, va_list arg );
int vsnprintf( char *s, const char *format, va_list arg );

int fprintf( FILE *stream, const char *format, ... ){
	int ret;
	va_list ap;

	va_start( ap, format );
	ret = vfprintf( stream, format, ap );
	va_end( ap );

	return ret;
}

int printf( const char *format, ... ){
	int ret;
	va_list ap;

	va_start( ap, format );
	ret = vfprintf( stdout, format, ap );
	va_end( ap );

	return ret;
}
	
int sprintf( char *s, const char *format, ... );
int snprintf( char *s, const char *format, ... );
