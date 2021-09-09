/**********************************
* Name: Noah Watson
* Email: nwatson2@nd.edu
 * File Name: sudoku.c
 * Date Created: 9/8/21
 * File Contents: This file contains the function definitions
 *                for Programming Challenge 01
 **********************************/
//include header file
#include "sudoku.h"

void malloc_puzzle ( int** sudoku ){
  long unsigned int i = 0;
  // iterate through loop
  for( i = 0; i<COLS; ++i){
    sudoku[i] = (int*)malloc(COLS*sizeof(int));
  }
}

void free_puzzle ( int** sudoku ){
  long unsigned int i = 0;
  for(i=0; i<COLS; ++i){
    free(sudoku[i]);
  }
}

void read_puzzle(int** sudoku, FILE* filein){
  // row and col input
  long unsigned int rowin = 0;
  long unsigned int colin = 0;

  while(filein != NULL){
    //read integer from file
    int tempn;
    fscanf(filein, "%d\n", &tempn);
    // place integer into sudoku
    sudoku[rowin][colin] = tempn;
    // incriment row or col
    if(colin < COLS-1){
      colin++;
    }
    else{
      rowin++;
      colin=0;
    }
    // break loop at EOF
    if(filein->_IO_read_ptr == filein->_IO_read_end){
      break;
    }
  }
}

void print_puzzle(int** sudoku){
  // row and col iterater
  long unsigned int rowit;
  long unsigned int colit;
  // nested for loop to print all cells
  for(rowit=0; rowit < ROWS; ++rowit){
    for(colit=0; colit< COLS; ++colit){
      printf("%d ", sudoku[rowit][colit]);
    }
    printf("\n"); // separates rows when each col is filled
  }
}

unsigned int check_puzzle(int** sudoku){
  // row and col iterater
  long unsigned int rowit;
  long unsigned int colit;
  // nested for loop to check all cells and return output
  for(rowit=0; rowit < ROWS; ++rowit){
    for(colit=0; colit< COLS; ++colit){
      if(sudoku[rowit][colit] == 0){
        return 0;
      }
    }
  }
  return 1;
}

void insert_and_check_puzzle(int** sudoku){
  int val;
  long unsigned int row;
  long unsigned int col;
  // read in users choices
  printf("\nInsert the value, row, and column here:");
  scanf("%d %lu %lu", &val, &row, &col);

  if(val < 1 || val > 9){
    fprintf(stderr, "Error: value is outside of domain [1-9]\n");
    return;
  }
  if(row <= 0 || row > 8){
    fprintf(stderr, "Error: row is outside of domain [0-8]\n");
    return;
  }
  if(col <= 0 || col > 8){
    fprintf(stderr, "Error: col is outside of domain [0-8]\n");
    return;
  }

  // check rows and cols
  int i;
  for(i=0;i<ROWS; ++i){
    if(sudoku[i][col] == val){
      printf("%d is already being used at (%d, %lu)\n", val, i, col);
      return;
    }
  }

  for(i=0;i<COLS; ++i){
    if(sudoku[row][i] == val){
      printf("%d is already being used at (%lu, %d)\n", val, col, i);
      return;
    }
  }
  // solves middle box of each larger 3x3 box
  int midrow;
  int midcol;
  if(row <= 2 && col <=2){
    midrow = 1;
    midcol = 1;
  }
  else if(row <= 2 && col >= 3 && col <= 5){
    midrow = 1;
    midcol = 4;
  }
  else if(row <= 2 && col >= 6 && col <= 8){
    midrow = 1;
    midcol = 7;
  }
  else if(row >= 3 && row <= 5 && col <= 2){
    midrow = 4;
    midcol = 1;
  }
  else if(row >= 6 && row <= 8 && col <= 2){
    midrow = 7;
    midcol = 1;
  }
  else if(row >= 3 && row <= 5 && col <= 5 && col >= 3){
    midrow = 4;
    midcol = 4;
  }
  else if(row >= 3 && row <= 5 && col <= 8 && col >= 6){
    midrow = 4;
    midcol = 7;
  }
  else if(row >= 6 && row <= 8 && col <= 5 && col >= 3){
    midrow = 4;
    midcol = 7;
  }
  else if(row >= 6 && row <= 8 && col <= 8 && col >= 6){
    midrow = 7;
    midcol = 7;
  }

  // nested for loop to check boxes
  int j;
  for(i=midrow-1; i<midrow+2; ++midrow){
    for(j=midcol-1; j<midcol+2; ++midcol){
      if(sudoku[row][i] == val){
        return;
      }
    }
  }

  sudoku[row][col] = val;
  return;
}
