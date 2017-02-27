/*Solved Excercise: Game of Chance*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int RollDice();

void main(){
	int sum, gameStatus, myPoints;
	clrscr();
	srand(time(NULL));

	sum = RollDice();
	switch(sum){
		case 7: case 11:
			gameStatus = 1;
		break;
		case 2: case 3: case 12:
			gameStatus = 2;
		break;
		default:
			gameStatus = 0;
			myPoints = sum;
			printf("\nMy Points: %d", myPoints);
		break;
	}

	while(gameStatus == 0){
		sum = RollDice();

		if(sum == myPoints)
			gameStatus = 1;
		else if(sum == 7)
			gameStatus = 2;

	}

	if(gameStatus == 1)
		printf("\nPlayer wins");
	else
		printf("\nPlayer loses");

	getch();
}

int RollDice(){
	int dice1 =0, dice2 =0, sum;

	dice1 = 1 + (rand() % 6);
	/*Formula for finding random value from a to n: a +(rand()%b) where a<= randValue <= b*/
	dice2 = 1 + (rand() % 6);
	sum = dice1 + dice2;
	printf("\nPlayer rolled %d + %d = %d", dice1, dice2, sum);

	return sum;
}