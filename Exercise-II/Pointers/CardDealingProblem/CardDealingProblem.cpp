// CardDealingProblem.cpp : Card dealing problem
//

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#define SIZE 5

void Shuffle(int wDeck[][13]);
void Deal(int wDeck[][13], char *suit[], char *face[]);
void GetCardsOfPokers(int wDeck[4][13], int pokers[4][13], int rowIndex[SIZE], int columnIndex[SIZE], int startingPoint);
int CheckForPair(int rowIndex[SIZE], int columnIndex[SIZE]);
int CheckForThreeKind(int column[SIZE]);
int CheckForSameSuit(int rowIndex[SIZE]);

int main()
{
	char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	char *face[13] = { "Ace", "Deuce", "Three", "Four",
					  "Five", "Six", "Seven", "Eight",
					  "Nine", "Ten", "Jack", "Queen", "King" };
	int deck[4][13] = { 0 };
	int hand1[4][13] = { 0 };
	int hand2[4][13] = { 0 };
	int rowIndex[SIZE] = { 0 }, columnIndex[SIZE] = { 0 };
	int startingPointH1 = 1, startingPointH2 = 6;
	int pairsH1, kindsH1, sameSuitH1;
	int pairsH2, kindsH2, sameSuitH2;
	srand(time(NULL));
	Shuffle(deck);

	GetCardsOfPokers(deck, hand1, rowIndex, columnIndex, startingPointH1);
	GetCardsOfPokers(deck, hand2, rowIndex, columnIndex, startingPointH2);
	printf("\n *********************Hand1***********************");
	pairsH1 = CheckForPair(rowIndex, columnIndex);
	kindsH1 = CheckForThreeKind(columnIndex);
	sameSuitH1 = CheckForSameSuit(rowIndex);
	printf("\n\nPairsH1 = %d\tKindsH1 = %d\tSameSuitH1 = %d\n\n", pairsH1, kindsH1, sameSuitH1);
	Deal(hand1, suit, face);

	printf("\n *********************Hand2***********************");
	pairsH2 = CheckForPair(rowIndex, columnIndex);
	kindsH2 = CheckForThreeKind(columnIndex);
	sameSuitH2 = CheckForSameSuit(rowIndex);
	printf("\n\nPairsH2 = %d\tKindsH2 = %d\tSameSuitH2 = %d\n\n", pairsH2, kindsH2, sameSuitH2);
	Deal(hand2, suit, face);
	_getch();
}

void Shuffle(int wDeck[][13])
{
	int card, row, column;
	for(card = 1; card <=52; card++)
	{
		row = rand() % 4;
		column = rand() % 13;
		
		while(wDeck[row][column]!=0)
		{
			row = rand() % 4;
			column = rand() % 13;
		}
		wDeck[row][column] = card;
	}/*
	wDeck[0][2] = 1;
	wDeck[0][9] = 2;
	wDeck[0][10] = 3;
	wDeck[0][5] = 4;
	wDeck[0][11] = 5;*/
}

void Deal(int wDeck[][13], char *suit[], char *face[])
{
	int card, row, column;
	for(card = 1; card <=52; card++)
	{
		for(row = 0; row < 4; row++)
		{
			for (column = 0; column < 13; column++)
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", face[column], suit[row], card % 2 == 0 ? '\n' : '\t');
//					printf("%5d of %-8d%c", column, row, card % 2 == 0 ? '\n' : '\t');
				}

		}
	}
}

void GetCardsOfPokers(int wDeck[4][13], int pokers[4][13], int rowIndex[5], int columnIndex[5], int startingPoint)
{
	int cards = 1, row, column, i = 0;
	for(cards = startingPoint; cards <= (startingPoint+ SIZE); cards++)
	{
		for (row = 0; row < 4; row++)
		{
			for (column = 0; column < 13; column++)
				if (wDeck[row][column] == cards)
				{
					pokers[row][column] = cards;
					rowIndex[i] = row;
					columnIndex[i] = column;
					i++;
				}
		}
	}
}
int CheckForPair(int rowIndex[SIZE], int columnIndex[SIZE])
{
	int i = 0, j = 0, suitIndex, faceIndex, isPairAvailable = 0;
	for (i = 0; i < SIZE; i++)
	{
		suitIndex = rowIndex[i];
		faceIndex = columnIndex[i];
		for (j = 0; j < SIZE; j++)
			if (rowIndex[j] != suitIndex && columnIndex[j] == faceIndex && i != j)
				isPairAvailable++;
	}

	if (isPairAvailable == 1 || isPairAvailable == 2)
		printf("\nPoker contain %d pairs\n", isPairAvailable);
	else
		printf("\nPoker doesn't contain any pair(s)\n");

	return isPairAvailable;
}

int CheckForThreeKind(int column[SIZE])
{
	int count = 0, columnIndex = 0, i, j, flag = 0;
	for(i = 0; i<SIZE; i++)
	{
		columnIndex = column[i];
		for(j = 0; j < SIZE; j++)
			if (columnIndex > 9 && columnIndex < 13 && j != i)
				if (columnIndex == column[j])
					count++; 

		if (count == 2 || count == 3)
		{
			flag = 1;
			printf("\Hand contain %d of a Kinds\n", count+1);
			break;
		}	
	}
	if(flag == 0)
		printf("\hand doesn't contain 3 or 4 of a kind\n");

	return count;
}

int CheckForSameSuit(int rowIndex[SIZE])
{
	int suit = rowIndex[0], i, flag = 1;
	for (i = 1; i < SIZE; i++)
		if (suit != rowIndex[i])
		{
			flag = 0;
			break;
		}

	if (flag == 1)
		printf("\nHand contains flush\n");
	else
		printf("\nHand does not contains flush\n");

	return flag;
}