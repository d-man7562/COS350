
# makefile for smsh
#
all: wc1 wc2 wc3
CC=gcc
CFLAGS=-g -pthread
wc3: wc3.o
	$(CC) $(CFLAGS) -o wc3 wc3.o
wc2: wc2.o
	$(CC) $(CFLAGS) -o wc2 wc2.o
wc1: wc1.o 
	$(CC) $(CFLAGS) -o wc1 wc1.o 
clean:
	rm wc1 wc1.o wc2 wc2.o

