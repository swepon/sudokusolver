#include"sudokusolver.c"
#include<string.h>


int main()
{
	int Sudoku[9][9]=
	{{1, 0, 0, 4, 0, 0, 5, 8, 0},
	{5, 9, 8, 0, 0, 0, 0, 3, 7},
	{7, 6, 0, 0, 0, 8, 0, 0, 0},
	{0, 0, 0, 0, 1, 3, 0, 6, 0},
	{9, 0, 0, 0, 0, 0, 2, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 9, 1},
	{0, 0, 1, 0, 4, 0, 0, 0, 0},
	{0, 0, 9, 0, 2, 6, 0, 0, 0},
	{0, 0, 6, 8, 9, 1, 0, 0, 4}};
	solve_sudoku(Sudoku);
	printf("Solved sudoku: \n");
	print_sudoku(Sudoku);
}