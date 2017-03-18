// 6.Arrays.cpp : Defines the entry point for the console application.
//Counting moves of knight on empty chess board.

#include <stdio.h>
#include <conio.h>

int main()
{
	int chessBoard[8][8] = { 0 };
	int i, j, flag = 1, counter = 1;
	int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int visited[8][8] = { 0 };
	int currentRow, currentColumn, moveKnightRow, moveKnightColumn;
	int moveNumber, occupied_counter;
	printf("Enter current row: ");
	scanf_s("%d", &currentRow);
	printf("Enter current column: ");
	scanf_s("%d", &currentColumn);
	moveKnightRow = currentRow;
	moveKnightColumn = currentColumn;

	visited[currentRow][currentColumn] = 1;
	while (flag)
	{
		occupied_counter = 0;
		for (moveNumber = 0; moveNumber < 8; moveNumber++)
		{
			currentColumn += horizontal[moveNumber];
			currentRow += vertical[moveNumber];
			if(currentRow >= 0 && currentColumn >= 0 && visited[currentRow][currentColumn] == 0 && (currentRow < 8 && currentColumn < 8))
			{
				counter++;
				visited[currentRow][currentColumn] = counter;
				moveKnightRow = currentRow;
				moveKnightColumn = currentColumn;
				//printf("\nVisited[%d][%d] = %d", currentRow, currentColumn, visited[currentRow][currentColumn]);
				
				break;
			}
			else
			{
				occupied_counter++;
				if (occupied_counter == 8)
					flag = 0;

				currentColumn = moveKnightColumn;
				currentRow = moveKnightRow;
			}
		}
	}
	for(i = 0; i < 8; i++)
	{
		printf("\n");
		for (j = 0; j < 8; j++)
			printf("\t%d", visited[i][j]);
	}
	printf("\n\n%d", counter);
	_getch();

    return 0;
}

