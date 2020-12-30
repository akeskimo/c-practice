CC=gcc
CFLAGS=-Wall -ferror-limit=3
SRCDIR=src
OBJDIR=obj
BUILDDIR=bin
EXECUTABLE=$(BUILDDIR)/square
SOURCES=$(notdir $(wildcard $(SRCDIR)/*.c))
OBJECTS=$(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(SOURCES)))

first: $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

${EXECUTABLE}: ${OBJECTS}
	${CC} -o $(EXECUTABLE) $^

check: ${OBJECTS}
	$(MAKE) -C src/tests

clean:
	rm $(OBJDIR)/*.o $(BUILDDIR)/* || true

.PHONY: clean check first