CC = g++
TARGET = main
EXEC = hps.exe

# Directory paths
SRCDIR != pwd
PROJDIR = $(SRCDIR)/..
export OBJDIR = $(PROJDIR)/obj
SUBDIRS = FileImporter Components Common #$(wildcard */.)

all: $(SUBDIRS) $(OBJDIR)/$(TARGET).o

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CC) -c -o $@ $<
	$(CC) -o $(EXEC) $(OBJDIR)/*.o

.PHONY: $(SUBDIRS) clean
$(SUBDIRS):
	$(MAKE) -C $@

clean:
	rm -f $(OBJDIR)/*.o $(EXEC)
