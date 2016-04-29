all: pl1

CC = gcc
CFLAGS  = -g -Wall
pl1: pl1.c test.h ;$(CC) $(CFLAGS) -o pl1 pl1.c  -lm
     
clean: ;rm pl1