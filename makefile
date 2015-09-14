#Makefile script

#Compiler settings
CC = cc
CFLAGS = -std=c99 -g

SOURCES = \
	tohex.c \
	cli.c \
	file.c

#Targets
all: tohex

tohex: $(SOURCES)
	$(CC) $(CFLAGS) -o tohex tohex.c