#Makefile script

#Compiler settings
CC = cc
CFLAGS = -std=c99 -g

#Targets
all: tohex

tohex: tohex.c cli.c
	$(CC) $(CFLAGS) -o tohex tohex.c
