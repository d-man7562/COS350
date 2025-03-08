CC = gcc
CFLAGS = -g -Wall

SRCS = zarchive.c

MAIN = zarchive

OBJS = $(SRCS:.c=.o)

# Build the final executable
$(MAIN): $(OBJS)
	$(CC) $(OBJS) -o $(MAIN)

# Build the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean to remove object files and the executable
clean:
	rm -f $(OBJS) $(MAIN)

.PHONY: clean