CC = g++
TARGET = fileimporter

all: $(OBJDIR)/$(TARGET).o

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJDIR)$(wildcard *.o)
