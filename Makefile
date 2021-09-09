# Name: Noah Watso
# Email: nwatson2@nd.edu
# File Name: Makefile
# Date Created: 9/8/21
# File Contents: This is the Makefile for compilation of Programming Challenge 01

# PP is for the gcc compiler for C
PP:= gcc

# CFLAGS are the required compiler flags for the CSE 20312 course
CFLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -std=c11 -Werror -lm -c

#make PC01
PC01.o: PC01.c
	$(PP) $(CFLAGS) -c PC01.c
#make sudoku
sudoku.o: sudoku.c
	$(PP) $(CFLAGS) -c sudoku.c
#PC01 objects
PC01_objs:= PC01.o sudoku.o
#executable
PC01: $(PC01_objs)
	$(PP) $(CFLAGS) -o PC01 $(PC01_objs)
# Make clean
clean:
	rm -rf *.o PC01
