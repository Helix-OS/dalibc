SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

stdlib: $(OBJ)
	@echo LD -o $@.o *.o
	$(LD) $(LDFLAGS) -r -o $@.o *.o
	@mv $@.o ..

all: stdlib

clean:
	@-rm *.o

.PHONY: stdlib

