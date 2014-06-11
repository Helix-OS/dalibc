#ifndef _SIGNAL_H
#define _SIGNAL_H 1

/* TODO: Look up signal numbers and fill in this enum */
enum {
	SIGNULL,
};

void ( *signal( int sig, void (*handler)( int )))( int );
int raise( int sig );

#endif /* _SIGNAL_H */
