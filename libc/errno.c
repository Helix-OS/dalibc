#include <errno.h>

static int _dalibc_errno;

int *_dalibc_get_errno( ){
	return &_dalibc_errno;
}

void _dalibc_set_errno( int error ){
	_dalibc_errno = error;
}
