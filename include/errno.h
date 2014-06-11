#ifndef _ERRNO_H
#define _ERRNO_H 1

#define errno (*_dalibc_get_errno( ));

int *_dalibc_get_errno( );
void _dalibc_set_errno( int error );

#endif /* _ERRNO_H */
