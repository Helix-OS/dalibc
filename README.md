DaLibc
======
A simple, portable C library.
Initially this library is aiming for ansi C (C89) compliance, with C99/C11 and POSIX being future goals. 
This is developed as part of Helix OS.

At the moment there's most of the needed headers, support for a few hosts, and a few basic functions,
the library is currently nowhere near finished yet.

Building
========
To build dalibc, you have to specify a host operating system and the target CPU.
For example, to build the library for amd64 linux,

    make ARCH=amd64 HOST=linux

For cross-compiling, you must specify the cross compiler and linker as well, e.g:

    make ARCH=i386 HOST=helix CC=$pathtocc/bin/i586-elf-gcc LD=$pathtocc/bin/i586-elf-ld

If nothing is specified at build time, ARCH defaults to "i386" and HOST defaults to "none".
The "none" host provides bare-bones syscall stubs needed for linking.

Porting
-------
To a new operating system
- - - - - - - - - - - - -


To a new CPU
- - - - - - -


Contributing
============
To contribute, fork the master branch of the repository, make whatever changes you want,
and submit a pull request for review and comments. If your code is doubleplusgoodlike,
it will most likely be merged in.
