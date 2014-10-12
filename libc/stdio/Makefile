SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=

.c.o:
	@echo "[libc] CC $<"
	@$(CC) $(CFLAGS) -c $<

stdio.o: $(OBJ)
	@echo "[libc stdio] LD -o $@ *.o"
	@$(LD) $(LDFLAGS) -r -o $@ *.o
	@cp $@ ../stdio_lib.o

all: stdio.o

clean:
	@-rm -f *.o

.PHONY: all
