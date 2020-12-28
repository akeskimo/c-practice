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

test: all
	cd src/tests && $(MAKE) test

clean:
	rm $(OBJDIR)/*.o $(BUILDDIR)/* || true

.PHONY: clean test all