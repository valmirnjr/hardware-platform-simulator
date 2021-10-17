CC = g++
TARGET = component
SUBDIRS = Platform Bus CPU Memory Display #$(wildcard */.)
export OBJDIR

all: $(SUBDIRS) $(OBJDIR)/$(TARGET).o

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CC) -c -o $@ $<

.PHONY: $(SUBDIRS) clean
$(SUBDIRS):
	$(MAKE) -C $@

clean:
	rm -f $(OBJDIR)$(wildcard *.o)
