/*Airlines reservation system*/
#include<stdio.h>
#include<conio.h>
#define SIZE 20
void AssignSeatsInSmokingZone(int seats[], int seatNumber);
void AssignSeatsInNonSmokingZone(int seats[], int seatNumber);

void main(){
	int choice, seatNumber;
	char ch;
	int seats[SIZE] = {0};
	clrscr();

	while(1){
		printf("\nPlease type 1 for smoking");
		printf("\nPlease type 2 for non smoking");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			printf("\nEnter your preferred seat number(1 to %d):", (SIZE)/2 - 1);
			scanf("%d", &seatNumber);
			AssignSeatsInSmokingZone(seats, seatNumber);
			break;
		case 2:
			printf("\nEnter your preferred seat number (%d to %d)", (SIZE)/2, SIZE);
			scanf("%d", &seatNumber);
			AssignSeatsInNonSmokingZone(seats, seatNumber);
			break;
		}

		printf("\nEnter Y or N to continue: ");
		scanf("%s", &ch);
		if(ch == 'N' || ch == 'n')
			break;
	}

	getch();
}

void AssignSeatsInSmokingZone(int seats[], int seatNumber){
	int i;
	if(seatNumber  > 0 && seatNumber < (SIZE)/2){
		if(seats[seatNumber] == 0){
			seats[seatNumber] = 1;
		}
		else{
			printf("\nSeat is already allocated, Checking for next available seat");

			for(i = 0; i < (SIZE)/2; i++){
				if(seats[i] == 0){
				  seats[i] = 1;
				  seatNumber = i;
				  break;
				}
				else{
					if(i == ((SIZE)/2 - 1)){
						printf("Smoking section is full. For reserving seat in non smoking zone check seats in Non smoking zone");
						printf("Next flight leave in 3 hours");
						break;
						}
					else
						printf("\n%d seat number is already reserved", i);
				}
			}

		}
	if(i != (SIZE)/2 -1)
		printf("\n\tBoarding pass:\n\t\tseat number:%d\tZone:%s\n", seatNumber,"Smoking zone");
	}
	else
		printf("\nYou Entered wrong input");
}
void AssignSeatsInNonSmokingZone(int seats[], int seatNumber){
	int i;
	if(seatNumber >= (SIZE)/2 && seatNumber <= SIZE){
		if(seats[seatNumber] == 0)
			seats[seatNumber] = 1;
		else{
			printf("Seat is already allocated. Checking for next available seat");
			for(i = (SIZE)/2; i < SIZE; i++){
				if(seats[i] == 0){
					seats[i] = 1;
					seatNumber = i;
					break;
				}
				else{
					if(i == SIZE - 1){
						printf("\nNon smoking section is full");
						printf("Next flight leave in 3 hours");
						break;
					}
					else
						printf("\n%d seat number is already reserved", i);

				}
			}
		}
			if(i != SIZE -1)
				printf("\n\tBoarding pass:\n\t\tseat number:%d\tZone:%s\n", seatNumber,"Non smoking zone");
	}
	else
		printf("\nYour entered wrong seat number");
}