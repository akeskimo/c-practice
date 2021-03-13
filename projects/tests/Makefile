CC=gcc
BUILDDIR=build
OBJDIR=obj
SRCDIR=.
SOURCES=\
	test_sort.c \
	main.c
OBJECTS=$(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SOURCES)))
EXECUTABLE=$(BUILDDIR)/test

# Dependencies
INCLUDES=-I../algorithm
DOBJECTS=\
	../obj/sort.o

first: $(EXECUTABLE)

clean:
	rm $(OBJECTS) $(EXECUTABLE) || true

check: $(EXECUTABLE)
	$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(BUILDDIR)
	$(CC) $(DOBJECTS) $(OBJECTS) -o $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJDIR) $(BUILDDIR):
	mkdir -p $@

.PHONY: first clean