SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

all: $(OBJ)

clean:
	@-rm *.o

.PHONY: all
