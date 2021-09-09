# Name: Noah Watso
# Email: nwatson2@nd.edu
# File Name: Makefile
# Date Created: 9/8/21
# File Contents: This is the Makefile for compilation of Programming Challenge 01

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20312 course
CFLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -std=c11 -Werror -lm -c

# Command: make sudoku
sudoku: sudoku.o
	$(CC) $(CFLAGS) -o sudoku sudoku.o

sudoku.o: sudoku.c
	$(CC) $(CFLAGS) -c sudoku.c

# Command: make PC01
PC01: PC01.o
	$(CC) $(CFLAGS) -o PC01 PC01.o

PC01.o: PC01.c
	$(CC) $(CFLAGS) -c PC01.c

# PC01 Objects
PC01_objs:= PC01.o sudoku.o

# Make clean
clean:
	rm -rf *.o PC01
