SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

stdio: $(OBJ)
	@echo LD -o $@.o *.o
	$(LD) $(LDFLAGS) -r -o $@.o *.o
	@mv $@.o ..

all: stdio

clean:
	@-rm *.o

.PHONY: stdio

