/**********************************
 * Name: Noah Watso
 * Email: nwatson2@nd.edu
 * File Name: PC01.c
 * Date Created: 9/8/2021
 * File Contents: Contains the main driver function
 *                for Programming Challenge 01
 **********************************/

#include "sudoku.h"

int main( const int argc, const char* argv[] ){
	// check argc value
	if(argc != 2){
		fprintf(stderr, "Error: argc != 2\n");
		exit(EXIT_FAILURE); // exit program
	}
	//check file name value
	if(argv[1] == NULL){
		fprintf(stderr, "Error: File cannot be opened\n" );
		exit(EXIT_FAILURE); // exit program
	}

	// create file pointer for argv file input
	FILE* argpoint = fopen(argv[1], "r");

	// memory allocation for the the 2D array
	int** sudoku = (int **)malloc( ROWS * sizeof( int * ) );

	// allocate memory for the sudoku integer array
	malloc_puzzle(sudoku);

	// read through sudoku
	read_puzzle(sudoku, argpoint);

	// decare user option variable
	int choice;
	while(check_puzzle(sudoku) == 0){
		printf("Select from the following choices:\n1: Print the current puzzle\n2. Insert value into puzzle\n4. Exit the game\nInsert your choice here: ");
		scanf("%d", &choice); // get user option
		//call function based off input
		switch(choice){
			case 1:
				print_puzzle(sudoku);
				break;
			case 2:
				insert_and_check_puzzle(sudoku);
				break;
			case 4:
				fclose(argpoint);
				free_puzzle(sudoku);
				free(sudoku);
				return 1;
				break;
			default:
				printf("Error: please try again\n");
		}
	}
	// congratulate user and print completed puzzle
	printf("Congratulations! You have solved the puzzle!\n");
	print_puzzle(sudoku);

	// close pointer and free memory
	fclose(argpoint);
	free_puzzle(sudoku);
	free(sudoku);

	return 0;
}
