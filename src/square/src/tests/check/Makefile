CC=gcc
CFLAGS=-Wall
LFLAGS=-lCheck
OBJDIR=obj
SRCDIR=.
BUILDDIR=bin
SOURCES=$(wildcard $(SRCDIR)/*.c)
_OBJECTS=$(patsubst %.c,%.o,$(notdir $(SOURCES)))
OBJECTS=$(addprefix $(OBJDIR)/,$(_OBJECTS))
EXECUTABLE=$(BUILDDIR)/test_square
DOBJDIR=../../../obj
_DOBJECTS=square.o
DOBJECTS=$(addprefix $(DOBJDIR)/,$(_DOBJECTS))

first: $(EXECUTABLE)

check: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(DOBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) $^ $(LFLAGS) -o $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) || true

.PHONY: check first clean
