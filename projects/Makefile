PROJECTS=\
	tests

CC=gcc
CFLAGS=-Wall
OBJDIR=obj
SOURCES=\
	algorithm/sort.c
OBJECTS=$(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(wildcard $(SOURCES))))

first: $(OBJECTS) $(PROJECTS)
	make -C $(filter-out %.o,$^)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $^ -o $@

check: $(OBJECTS)
	make -C tests check

clean: $(PROJECTS)
	rm $(OBJECTS) || true
	make -C $^ clean

.PHONY: $(PROJECTS) tests
