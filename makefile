#Makefile script

#Compiler settings
CC = cc
CFLAGS = -std=c99 -g

#File lists
#Source files
SOURCES = \
	tohex.c \
	cli.c \
	file.c \
	stdin.c

#Cleaning files
CLEANUP = \
	tohex \
	a.out

#Targets
all: tohex

clean:
	rm -f $(CLEANUP)

tohex: $(SOURCES)
	$(CC) $(CFLAGS) -o tohex tohex.c 