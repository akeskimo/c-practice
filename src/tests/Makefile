CC=gcc
CFLAGS=-Wall -ferror-limit=3
LFLAGS=-lCUnit
OBJDIR=../../obj
SRCDIR=.
SOURCES=$(wildcard $(SRCDIR)/*.c)
_OBJECTS=square.o $(patsubst %.c,%.o,$(notdir $(SOURCES)))
OBJECTS=$(addprefix $(OBJDIR)/,$(_OBJECTS))
EXECUTABLE=test_square

all: $(EXECUTABLE)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LFLAGS) -o $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm $(OBJECTS) || true

.PHONY: test all clean
