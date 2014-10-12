SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=

.c.o:
	@echo "[libc stdlib] CC $<"
	@$(CC) $(CFLAGS) -c $<

stdlib.o: $(OBJ)
	@echo "[libc stdlib] LD -o $@ *.o"
	@$(LD) $(LDFLAGS) -r -o $@ *.o
	@cp $@ ../stdlib_lib.o

all: stdlib.o

clean:
	@-rm -f *.o

.PHONY: all

