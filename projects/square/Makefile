CC=gcc
CFLAGS=-Wall
SRCDIR=src
OBJDIR=obj
BUILDDIR=bin
EXECUTABLE=$(BUILDDIR)/square
SOURCES=$(notdir $(wildcard $(SRCDIR)/*.c))
OBJECTS=$(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(SOURCES)))

first: $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $< $(CFLAGS) -o $@

${EXECUTABLE}: ${OBJECTS}
	mkdir -p $(BUILDDIR)
	${CC} -o $(EXECUTABLE) $^

check: ${OBJECTS}
	$(MAKE) -C src/tests

clean:
	rm $(OBJDIR)/*.o $(BUILDDIR)/* || true

.PHONY: clean check first