/*Reverse integer*/
#include<stdio.h>
#include<conio.h>
int calculateReverse(int n);
void main(){
	int number, reverseNumber;
	clrscr();

	printf("\nEnter Number:");
	scanf("%d",&number);

	reverseNumber = calculateReverse(number);
	printf("\nReverse number=%d",reverseNumber);
	getch();
}

int calculateReverse(int number){
	int rem, rev = 0;
	while(number != 0){
		rem = number % 10;
		rev = (rev * 10)+ rem;
		number /= 10;
	}
	return rev;
}