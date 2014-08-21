#include <stdio.h>
#include <stdarg.h>

int vfprintf( FILE *stream, const char *format, va_list arg ){
	int slen = strlen( format );
	int ret = 0;

	unsigned un;
	char c, *str;
	int buf, i;

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
					break;

				case 'u':
					break;

				case 'x':
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
