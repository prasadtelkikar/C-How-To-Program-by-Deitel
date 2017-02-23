/*Calculate siple interest*/
#include<stdio.h>
#include<conio.h>
void main(){
	int  days= 0;
	float principalAmount = 0, rate= 0;
	float SI = 0;
	clrscr();

	do{
		printf("\nEnter loan principal (-1 to end): ");
		scanf("%f", &principalAmount);
		if(principalAmount == -1)
			break;

		printf("\nEnter interest rate: ");
		scanf("%f", &rate);
		printf("\nEnter term of the loan in days: ");
		scanf("%d", &days);

		SI = principalAmount * rate * (days/ 365);
		printf("\nThe interest charge is $%f", SI);
	}while(principalAmount != -1);
	getch();
}
