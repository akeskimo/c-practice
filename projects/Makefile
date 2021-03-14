CC=gcc
CFLAGS=-Wall

PROJECTS=\
	tests

OBJDIR=obj
SOURCES=\
	algorithm/sort.c
OBJ=\
	sort.o

# Debug
DBGDIR=debug
DBGOBJ=$(addprefix $(DBGDIR)/,$(OBJ))
DBGFLAGS=-g -O0 -DDEBUG

first: $(OBJ)

debug: $(DBGOBJ)

$(DBGOBJ): $(SOURCES)
	mkdir -p $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

$(OBJ): $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

check: $(OBJ)
	make -C tests check

clean: $(PROJECTS)
	rm $(OBJ) $(DBGDOBJ) || true
	make -C $^ clean

.PHONY: $(PROJECTS) tests debug
