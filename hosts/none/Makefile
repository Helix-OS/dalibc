SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

all: $(OBJ)
	@echo Host makefile stub

clean:
	@-rm *.o

.PHONY: all
