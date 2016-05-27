FILESOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=)

# Special Cases

SOURCES := $(FILESOURCES)
SOURCES := $(filter-out externA.c,$(SOURCES))
SOURCES := $(filter-out externB.c,$(SOURCES))
OTHERS += extern

all: $(OBJECTS) $(OTHERS)

externA.o: externA.c
	$(CC) -c $<

externB.o: externB.c
	$(CC) -c $<

extern: externA.o externB.o
	$(CC) -g -o $@ $?

# Normal cases

$(OBJECTS): %: %.c
	$(CC) -g -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(OTHERS)

makedebug:
	# FILESOURCES $(FILESOURCES)
	# SOURCES $(SOURCES)
	# OBJECTS $(OBJECTS)
	# OTHERS $(OTHERS)
