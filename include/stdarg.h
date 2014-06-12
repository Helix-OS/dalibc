#ifndef _STDARG_H
#define _STDARG_H 1

/* This implementation is specific to the x86 platform, 
 * TODO: Move this to arch/i386
 */

#define va_start( list, arg ) {\
	list = (char *)&arg;\
}

#define va_arg( list, type ) (\
	list += sizeof( type ),\
	*(type *)(list - sizeof( type ))\
)

#define va_end( list ) (list)

typedef char * va_list;

#endif /* _STDARG_H */
