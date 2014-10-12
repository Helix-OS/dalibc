SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=

SRCDIRS=stdio stdlib
SRCBUF=$(patsubst %, %.srcdir, $(SRCDIRS))

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $<

%.srcdir: %
	@cd "$<"; make CC=$(CC) HOST=$(HOST) ARCH=$(ARCH) CFLAGS="$(CFLAGS)"

libc.o: $(OBJ)
	@echo "[libc] LD -o libc.o *.o"
	@$(LD) $(LDFLAGS) -r -o libc.o *.o

all: $(SRCBUF) libc.o

clean:
	@-rm *.o
	@-for dir in $(SRCDIRS); do \
		cd $$dir; \
		make clean; \
		cd ..; \
	done;

install:
	@cp libc.o $(PREFIX)/lib

.PHONY: all

