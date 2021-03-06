CC=gcc
CFLAGS=-Wall
SRCDIR=.
HEADERS=\
	structs.h
SOURCES=\
	test_sort.c \
	main.c
OBJ=$(patsubst %.c,%.o,$(notdir $(SOURCES)))

# Tested sources/libraries
INCLUDES=-I../algorithm -I.
DOBJ=\
	../obj/sort.o

# Build
BUILDDIR=build
OBJDIR=obj
BUILDOBJ=$(addprefix $(OBJDIR)/,$(OBJ))
BUILDEXE=$(BUILDDIR)/test

# Debug
DBGDIR=debug
DBGOBJ=$(addprefix $(DBGDIR)/,$(OBJ))
DBGEXE=$(DBGDIR)/test_sort
DBGFLAGS=-g -O0 -DDEBUG
DBGDOBJ=\
	../debug/sort.o

# Profile
PROFDIR=prof
PROFOBJ=$(addprefix $(PROFDIR)/,$(OBJ))
PROFEXE=$(PROFDIR)/test_sort
PROFLDFLAGS=-pg -g
PROFDOBJ=\
	../prof/sort.o

# Benchmark
BMSRC=\
	benchmark.c
BMEXE=$(BUILDDIR)/benchmark

first: $(BUILDEXE)

check: $(BUILDEXE)
	$(BUILDEXE)

$(BUILDEXE): $(BUILDOBJ) $(DOBJ)
	$(CC) $(DOBJ) $(BUILDOBJ) -o $(BUILDEXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJ) $(DOBJ) $(HEADERS)
	$(CC) $(DBGDOBJ) $(DBGOBJ) -o $(DBGEXE)

$(DBGDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

profile: $(PROFEXE)
	$(PROFEXE)
	gprof $(PROFEXE) gmon.out

$(PROFEXE): $(PROFOBJ)
	$(CC) $(PROFLDFLAGS) $(PROFDOBJ) $(PROFOBJ) -o $(PROFEXE)

$(PROFDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(PROFDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

benchmark: $(BMEXE)
	$(BUILDDIR)/benchmark

$(BMEXE): $(DOBJ) $(BMSRC)
	$(CC) $(CFLAGS) $(DOBJ) $(BMSRC) -o $(BMEXE)

clean:
	rm $(BUILDOBJ) $(BUILDEXE) $(DBGOBJ) $(DBGEXE) $(PROFEXE) $(PROFOBJ) || true

.PHONY: first clean debug profile
