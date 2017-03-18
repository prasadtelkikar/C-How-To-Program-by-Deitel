// AccessibleKnight.cpp : Print 2-D array containing values of number of visiting squares on chessboard.
//

#include <stdio.h>
#include <conio.h>
int GetCountOfAccessibleSquares(int currentKnightsRow, int currentKightsColumn, int n);
int main()
{
	int i, j, n = 8;
	int accessibilityArray[8][8] = { 0 };

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			accessibilityArray[i][j] = GetCountOfAccessibleSquares(i, j, n);
		}
	}
	for (i = 0; i < 8; i++)
	{
		printf("\n");
		for (j = 0; j < 8; j++)
		{
			printf("%3d", accessibilityArray[i][j]);
		}
	}
	_getch();
	return 0;
}

int GetCountOfAccessibleSquares(int row, int column, int k)
{
	int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int move, count = 0;
	int currentRow = row;
	int currentColumn = column;
	for(move = 0; move < 8; move++)
	{
		currentRow += horizontal[move];
		currentColumn += vertical[move];
		if((currentRow >=0 && currentColumn >= 0) && (currentRow < 8 && currentColumn < 8))
		{
			count++;
		}
		currentRow = row;
		currentColumn = column;

	}
	return count;
}

