ARCH=i386
HOST=none
PREFIX=/usr/local
INCLUDE=$(shell pwd)/include $(shell pwd)/$(ARCH)/include $(shell pwd)/$(HOST)/include

all:
	@cd hosts/$(HOST); make CC=$(CC) HOST=$(HOST) ARCH=$(ARCH)

clean:
	@echo Makefile stub

install:
	@echo Makefile stub

.PHONY: all
