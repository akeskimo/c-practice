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

# Profile
PROFDIR=prof
PROFOBJ=$(addprefix $(PROFDIR)/,$(OBJ))
PROFFLAGS=-pg

first: $(BUILDOBJ)

profile: $(PROFOBJ)

$(PROFOBJ): $(SOURCES)
	mkdir -p $(PROFDIR)
	$(CC) $(CFLAGS) $(PROFFLAGS) -c -o $@ $<

debug: $(DBGOBJ)
	make -C tests debug

$(DBGOBJ): $(SOURCES)
	mkdir -p $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

tests: $(BUILDOBJ)
	make -C tests

check: $(BUILDOBJ)
	make -C tests check

clean: $(PROJECTS)
	rm $(BUILDOBJ) $(DBGOBJ) $(PROFOBJ) || true
	make -C $^ clean

.PHONY: $(PROJECTS) tests debug
