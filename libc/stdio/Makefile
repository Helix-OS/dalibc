SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(OBJDIR)/stdio.o

$(OBJDIR)/stdio.o: $(OBJ)
	@echo "[libc stdio] LD -o $@ *.o"
	@$(LD) $(LDFLAGS) -r -o $@ *.o

.c.o:
	@echo "[libc] CC $<"
	@$(CC) $(CFLAGS) -c $<

clean:
	@-rm -f *.o

.PHONY: all
