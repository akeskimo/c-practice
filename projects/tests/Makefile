CC=gcc
CFLAGS=-Wall
SRCDIR=.
SOURCES=\
	test_sort.c \
	main.c
OBJ=$(patsubst %.c,%.o,$(notdir $(SOURCES)))

# External
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

first: $(BUILDEXE)

check: $(BUILDEXE)
	$(BUILDEXE)

$(BUILDEXE): $(BUILDOBJ) $(DOBJ)
	$(CC) $(DOBJ) $(BUILDOBJ) -o $(BUILDEXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJ)
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

clean:
	rm $(BUILDOBJ) $(BUILDEXE) $(DBGOBJ) $(DBGEXE) $(PROFEXE) $(PROFOBJ) || true

.PHONY: first clean debug