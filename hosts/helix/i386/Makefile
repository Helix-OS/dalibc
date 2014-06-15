CSRC = $(wildcard *.c)
SSRC = $(wildcard *.s)
COBJ = $(CSRC:.c=.o)
SOBJ = $(SSRC:.s=.o)
OBJ=$(COBJ) $(SOBJ)

.s.o:
	@echo AS $<
	@nasm -f elf32 $<

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

all: $(OBJ)

clean:
	@-rm *.o

.PHONY: all
