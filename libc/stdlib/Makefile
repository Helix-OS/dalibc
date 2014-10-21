SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(OBJDIR)/stdlib.o

$(OBJDIR)/stdlib.o: $(OBJ)
	@echo "[libc stdlib] LD -o $@ *.o"
	@$(LD) $(LDFLAGS) -r -o $@ *.o

.c.o:
	@echo "[libc stdlib] CC $<"
	@$(CC) $(CFLAGS) -c $<

clean:
	@-rm -f *.o

.PHONY: all

