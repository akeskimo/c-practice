CC=gcc
CFLAGS=-Wall -ferror-limit=3
SRCDIR=src
OBJDIR=obj
BUILDDIR=bin
EXECUTABLE=$(BUILDDIR)/square
SOURCES=$(wildcard ${SRCDIR}/*.c)
OBJECTS=$(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(notdir $(SOURCES))))

all: $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

${EXECUTABLE}: ${OBJECTS}
	${CC} -o $(EXECUTABLE) $^

check: all
	$(MAKE) -C src/tests

clean:
	rm $(OBJDIR)/*.o $(BUILDDIR)/* || true

.PHONY: clean test all