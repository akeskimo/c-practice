CC=gcc
CFLAGS=-Wall

PROJECTS=\
	tests

SOURCES=\
	algorithm/sort.c
OBJDIR=obj
OBJ=\
	sort.o
BUILDOBJ=$(addprefix $(OBJDIR)/,$(OBJ))

# Debug
DBGDIR=debug
DBGOBJ=$(addprefix $(DBGDIR)/,$(OBJ))
DBGFLAGS=-g -O0 -DDEBUG

first: $(BUILDOBJ)

debug: $(DBGOBJ)

$(DBGOBJ): $(SOURCES)
	mkdir -p $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

check: $(BUILDOBJ)
	make -C tests check

clean: $(PROJECTS)
	rm $(BUILDOBJ) $(DBGOBJ) || true
	make -C $^ clean

.PHONY: $(PROJECTS) tests debug
