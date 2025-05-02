
# makefile for smsh
#
all: lc1 lc2 lc3
CC=gcc
CFLAGS=-g -pthread -O2
TARGET = lc1 lc2 lc3
lc3: lc3.o
	$(CC) $(CFLAGS) -o lc3 lc3.o
lc2: lc2.o
	$(CC) $(CFLAGS) -o lc2 lc2.o
lc1: lc1.o 
	$(CC) $(CFLAGS) -o lc1 lc1.o 
clean:
	rm $(TARGET) *.o
