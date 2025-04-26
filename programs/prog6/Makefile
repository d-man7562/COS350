
# makefile for smsh
#
all: wc1 wc2
CC=gcc
CFLAGS=-g

wc2: wc2.o
	$(CC) $(CFLAGS) -o wc2 wc2.o
wc1: wc1.o 
	$(CC) $(CFLAGS) -o wc1 wc1.o 
clean:
	rm wc1 wc1.o wc2 wc2.o

