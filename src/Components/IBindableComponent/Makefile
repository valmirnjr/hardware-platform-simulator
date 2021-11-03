CC = g++
TARGET = ibindablecomponent

all: $(OBJDIR)/$(TARGET).o

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CC) $(INCLUDE_PATHS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)$(wildcard *.o)
