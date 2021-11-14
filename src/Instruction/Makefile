CC = g++
TARGET = instruction

all: $(OBJDIR)/$(TARGET).o

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CC) $(INCLUDE_PATHS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)$(wildcard *.o)
