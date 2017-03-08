/*Static arrays are initialized to zero*/

#include<stdio.h>
#include<conio.h>
void staticArrayInit();
void automaticArrayInit();

void main(){
	clrscr();
	printf("\nFirst call of each functions");
	staticArrayInit();
	automaticArrayInit();
	printf("\n-----------------------------------------------");
	printf("\nSecond call of each functions");
	staticArrayInit();
	automaticArrayInit();

	getch();
}

void staticArrayInit(){
	static int arr[3];
	int i;
	printf("\nEntered into staticArrayInit function\n");
	for(i = 0; i < 3; i++)
		printf("\tarr[%d] = %d", i, arr[i]);  //static variable assigned to zero automatically

	printf("\nExiting from staticArrayInit function\n");
	for(i = 0; i < 3; i++)
		printf("\tarr[%d] = %d", i, arr[i] +=5);

}

void automaticArrayInit(){
	int arr[3] = {1, 2, 3};
	int i;
	printf("\nEnter into automaticArrayInit function\n");
	for(i = 0; i < 3; i++)
		printf("\tarr[%d] = %d", i, arr[i]);  //Automatic array contains garbage value

	printf("\nExiting from automaticArrayInit function\n");
	for(i = 0; i < 3; i++)
		printf("\tarr[%d] = %d",i, arr[i] += 5);
}