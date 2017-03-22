// CardDealingProblem.cpp : Card dealing problem
//

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

void Shuffle(int wDeck[][13]);
void Deal(int wDeck[][13], char *suit[], char *face[]);
int main()
{
	char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	char *face[13] = { "Ace", "Deuce", "Three", "Four",
					  "Five", "Six", "Seven", "Eight",
					  "Nine", "Ten", "Jack", "Queen", "King" };
	int deck[4][13] = { 0 };
	srand(time(NULL));
	Shuffle(deck);
	Deal(deck, suit, face);
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
	}
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
					printf("%5s of %-8s%c", face[column], suit[row], card % 2 == 0 ? '\n' : '\t');
		}
	}
}