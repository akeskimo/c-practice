CC=gcc
CFLAGS=-Wall
OBJDIR=obj
SRCDIR=.
SOURCES=\
	test_sort.c \
	main.c
OBJ=$(patsubst %.c,%.o,$(notdir $(SOURCES)))

# External
INCLUDES=-I../algorithm
DOBJ=\
	../obj/sort.o

# Build
BUILDDIR=build
BUILDOBJ=$(addprefix $(BUILDDIR)/,$(OBJ))
BUILDEXE=$(BUILDDIR)/test

# Debug
DBGDIR=debug
DBGOBJ=$(addprefix $(DBGDIR)/,$(OBJ))
DBGEXE=$(DBGDIR)/test_sort
DBGFLAGS=-g -O0 -DDEBUG
DBGDOBJ=\
	../debug/sort.o

first: $(BUILDEXE)

$(BUILDEXE): $(OBJ) $(BUILDDIR)
	$(CC) $(DOBJ) $(OBJ) -o $(BUILDEXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJ)
	$(CC) $(DBGDOBJ) $(DBGOBJ) -o $(DBGEXE)

$(DBGDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

clean:
	rm $(OBJ) $(BUILDEXE) $(DBGOBJ) $(DBGEXE) || true

check: $(BUILDEXE)
	$(BUILDEXE)

.PHONY: first clean debug