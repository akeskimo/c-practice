TARGETS:=first check clean profile debug benchmark
PROJECTS=\
	projects \

$(TARGETS): $(PROJECTS)

$(PROJECTS):
	make -C $@ $(MAKECMDGOALS)

.PHONY: $(TARGETS) $(PROJECTS)
