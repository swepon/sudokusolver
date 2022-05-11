#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int solved(int sudoku[9][9])
{
   //check rows
   for (int i = 0; i < 9; i++)
   {
	   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	   for (int j = 0; j < 9; j++)
	   {
		    if(sudoku[i][j] == 0)
		    {
			    return 0;
		    }
		    else if (sudoku[i][j] != arr[(sudoku[i][j]) - 1])
		    {
			    return 0;
		    }
		    arr[(sudoku[j][i]) - 1] = -1;
	   }
   }
   
    //check columns
	for (int i = 0; i < 9; i++)
    {
		int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for (int j = 0; j < 9; j++)
		{
			if(sudoku[j][i] == 0)
			{
		 	   return 0;
		    }
		    else if (sudoku[j][i] != arr[(sudoku[j][i]) - 1])
		    {
				return 0;
		    }
			arr[(sudoku[j][i]) - 1] = -1;
	    }
    }
   return 1;
   
}

int notrepeateddigit(int digit, int sudoku[9][9], int i, int j)
{
	for (int x = 0; x < 9; x++)
	{
		if (sudoku[i][x] == digit) //check if the digit is already in that row
		{
			return 0;
		}
		if (sudoku[x][j] == digit) //check if the digit is already in that column
		{
			return 0;
		}
	}
	
	int a = i - i%3;
	int b = j - j%3;
	for (int x = a; x < a+3; x ++) 
	{
	    for (int y = b; y < b+3; y ++)
	    {
			//check if the digit is already in the 3x3 square 
			if (sudoku[x][y] == digit) 
			{
				return 0;
			}
	    }
	}
	return 1;
}

int possible(int sudoku[9][9])
{
	int i = 0;
	int j = 0;	
    if (solved(sudoku) == 1)
	{
	    return 1;
    }
    for (i = 0; i < 9; i++)
    {
		for (j = 0; j < 9; j++)
	    {
			if (sudoku[i][j] == 0)
		    {
				int digit;
			    for (digit = 1; digit < 10; digit++)
			    {
				    if (notrepeateddigit(digit, sudoku, i, j) == 1)
				    {
						sudoku[i][j] = digit;
						if (possible(sudoku))
						{
							return 1;
						}
						else
						{
							sudoku[i][j] = 0;
						}
					}
			    }
				return 0;
		    }
	    }
	}
	return 1;
}


void solve_sudoku(int sudoku[9][9], int depth)
{
   int x = possible(sudoku);
}
