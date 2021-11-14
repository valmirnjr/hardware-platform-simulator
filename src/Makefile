CC = g++
TARGET = main
EXEC = hps.exe
LOGLIB = spdlog

# Directory paths
SRCDIR != pwd
PROJDIR = $(SRCDIR)/..
export OBJDIR = $(PROJDIR)/obj
LIBDIR = $(PROJDIR)/lib
SUBDIRS = FileImporter Components Common Program Register Instruction #$(wildcard */.)
export INCLUDE_PATHS = -I$(LIBDIR)/$(LOGLIB)/include

# Spdlog libpath
LOGLIBPATH = $(LIBDIR)/$(LOGLIB)/build

all: $(SUBDIRS) $(OBJDIR)/$(TARGET).o $(EXEC)

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CC) $(INCLUDE_PATHS) -c -o $@ $<

$(EXEC):
	$(CC) -o $(EXEC) $(OBJDIR)/*.o -L$(LOGLIBPATH) -l$(LOGLIB)

.PHONY: $(SUBDIRS) clean
$(SUBDIRS):
	$(MAKE) -C $@

clean:
	rm -f $(OBJDIR)/*.o $(EXEC)

clean_target:
	rm -f $(OBJDIR)/$(TARGET).o $(EXEC)

clean_exec:
	rm -f $(EXEC)
