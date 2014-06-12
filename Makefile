ARCH 		= i386
HOST 		= none
PREFIX 		= /usr/local
INCLUDE 	= -I$(shell pwd)/include
INCLUDE 	+=-I$(shell pwd)/$(ARCH)/include -I$(shell pwd)/$(HOST)/include

CC=cc
LD=ld
CFLAGS=$(INCLUDE) -nodefaultlibs -nostdlib -nostartfiles -fno-builtin --sysroot=$(shell pwd)

all:
	@cd hosts/$(HOST); make CC=$(CC) HOST=$(HOST) ARCH=$(ARCH) CFLAGS="$(CFLAGS)"
	@cd libc; make CC=$(CC) HOST=$(HOST) ARCH=$(ARCH) CFLAGS="$(CFLAGS)"

clean:
	@-cd hosts/$(HOST); make clean HOST=$(HOST) ARCH=$(ARCH)
	@-cd libc; make clean HOST=$(HOST) ARCH=$(ARCH)

install:
	@echo Makefile stub

.PHONY: all
