TARGETS:=first check clean
PROJECTS=$(wildcard projects/*)

$(TARGETS): $(PROJECTS)

$(PROJECTS):
	make -C $@ $(MAKECMDGOALS)

.PHONY: $(TARGETS) $(PROJECTS)
