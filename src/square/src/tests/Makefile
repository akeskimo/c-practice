
SUBDIRS=$(dir $(wildcard */))	

first: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) check -C $@

.PHONY: $(SUBDIRS) first
