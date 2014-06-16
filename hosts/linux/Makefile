CSRC = $(wildcard *.c)
SSRC = $(wildcard *.s)
COBJ = $(CSRC:.c=.o)
SOBJ = $(SSRC:.s=.o)
OBJ=$(COBJ) $(SOBJ)

.s.o:
	@echo AS $<
	@echo "Warning: can't assemble \"$<\" at this level, move the file to an archetecture specific directory."

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -I$(shell pwd)/$(ARCH) -c $<

all: $(OBJ) archstuff

archstuff:
	@cd $(ARCH); make CC=$(CC) HOST=$(HOST) ARCH=$(ARCH) CFLAGS="$(CFLAGS) -I$(shell pwd)/$(ARCH)"

install:
	cp $(ARCH)/crt0.o $(PREFIX)/lib
	cp syscalls.o $(PREFIX)/lib

clean:
	@-rm *.o
	@-cd $(ARCH); make clean HOST=$(HOST) ARCH=$(ARCH)

.PHONY: all
