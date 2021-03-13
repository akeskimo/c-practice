TARGETS:=first check clean
PROJECTS=$(wildcard src/*)

$(TARGETS): $(PROJECTS)

$(PROJECTS):
	make -C $@ $(MAKECMDGOALS)

.PHONY: $(TARGETS) $(PROJECTS)
