#ifndef _STDARG_H
#define _STDARG_H 1

/* Use the gcc built-in stdarg for now */

#define va_start(v,l) __builtin_va_start(v,l)
#define va_arg(v,l)   __builtin_va_arg(v,l)
#define va_end(v)     __builtin_va_end(v)
#define va_copy(d,s)  __builtin_va_copy(d,s)
#define va_list	      __builtin_va_list

/* This implementation is specific to the x86 platform, 
 * TODO: Move this to arch/i386
 */

/*
#define va_start( list, arg ) {\
	list = (char *)&arg;\
}

#define va_arg( list, type ) (\
	list += sizeof( type ),\
	*(type *)(list - sizeof( type ))\
)

#define va_end( list ) (list)

typedef char * va_list;
*/

#endif /* _STDARG_H */
