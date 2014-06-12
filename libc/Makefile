SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

all: $(OBJ)
	@echo LD -o libc.o *.o
	$(LD) $(LDFLAGS) -r -o libc.o *.o

clean:
	@-rm *.o

.PHONY: all

