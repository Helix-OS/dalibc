SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS=
OBJDIR=$(shell pwd)/objs
ALLFLAGS="CC=$(CC) HOST=$(HOST) ARCH=$(ARCH) CFLAGS=$(CFLAGS) OBJDIR=$(OBJDIR)"

all: dirs libc.o

dirs:
	@mkdir -p objs

libc.o: $(OBJDIR)/stdio.o $(OBJDIR)/stdlib.o $(OBJ)
	@echo "[libc] LD -o libc.o *.o"
	@$(LD) $(LDFLAGS) -r -o libc.o $(OBJDIR)/*.o

$(OBJDIR)/stdio.o:
	@cd stdio; make CC="$(CC)" HOST="$(HOST)" ARCH="$(ARCH)" CFLAGS="$(CFLAGS)" OBJDIR="$(OBJDIR)"

$(OBJDIR)/stdlib.o:
	@cd stdlib; make CC="$(CC)" HOST="$(HOST)" ARCH="$(ARCH)" CFLAGS="$(CFLAGS)" OBJDIR="$(OBJDIR)"

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	@-rm $(OBJDIR)/*.o
	@-cd stdio; make clean
	@-cd stdlib; make clean

install:
	@cp libc.o $(PREFIX)/lib

.PHONY: all

