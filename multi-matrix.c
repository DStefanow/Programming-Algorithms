#include <stdio.h>
#include <stdlib.h>

// First matrix info
size_t FIRST_ROWS;
size_t FIRST_COLS;
int **FIRST_MATRIX;

// Declare used functions
void get_user_info();
void get_matrix_info(char count, int ***matrix, size_t *rows, size_t *cols);
void destroy_matrix();
void print_matrix(int **matrix, size_t rows, size_t cols);

void main()
{
	get_user_info();

//	print_matrix(FIRST_MATRIX, FIRST_ROWS, FIRST_COLS);

	destroy_matrix(FIRST_MATRIX);

	return;
}

//Get matrices dimensions and members
void get_user_info()
{
	printf("------ Multi Matrix Program ------\n");

	get_matrix_info(1, &FIRST_MATRIX, &FIRST_ROWS, &FIRST_COLS);
}

void get_matrix_info(char count, int ***matrix, size_t *rows, size_t *cols)
{
	// Get rows and columns
	printf("Enter %d-st matrix rows count: ", count);
	scanf("%zu", &(*rows));
	printf("Enter 1-st matrix cols count: ");
	scanf("%zu", &(*cols));

	// Alocate memory for matrix
	*matrix = (int**)malloc(sizeof(int) * (*rows));
	for (size_t i = 0; i < (*rows); i++) {
		(*matrix)[i] = (int*)malloc(sizeof(int) * (*cols));
	}

	for(size_t i = 0; i < *rows; i++) {
		for(size_t j = 0; j < *cols; j++) {
			printf("Enter (%zu,%zu) for %d matrix: ", i, j, count);
			*matrix[i][j] = j;

			printf("%d", *matrix[i][j]);
//			scanf("%d", &matrix[i][j]);
		}
	}
}

void print_matrix(int **matrix, size_t rows, size_t cols)
{
	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			printf("Here\n");
			printf("%d ", matrix[row][col]);
		}
		printf("\n");
	}
}

void destroy_matrix(int *matrix)
{
	free(matrix);
}
