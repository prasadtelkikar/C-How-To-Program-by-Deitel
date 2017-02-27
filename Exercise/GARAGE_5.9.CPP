/*Calculations and printing data in tabular form*/
#include<stdio.h>
#include<conio.h>

void CalculateCharge(int count);
float Charges(float hrs);
void main(){
	int custCount;
	clrscr();
	printf("\nEnter number of Customer");
	scanf("%d", &custCount);
	CalculateCharge(custCount);
	getch();
}

void CalculateCharge(int n){
	int i;
	float charge, hrs, totalHrs = 0, totalCharges = 0;
	if(hrs > 24)
		printf("Program is compatible to 24hrs");
	else{
	for(i = 0; i < n; i++){
		printf("\nEnter hours:");
		scanf("%f", &hrs);
		totalHrs += hrs;
		charge = Charges(hrs);
		totalCharges += charge;
		printf("\n%d\t%0.2f\t%0.2f", i + 1, hrs, charge);
		}
	printf("\nTotal\t%0.2f\t%0.2f", totalHrs, totalCharges);

	}
}

float Charges(float hrs){

	if(hrs <= 3)
		return (float)2;
	else if(hrs == 24)
		return (float) 10;
	else{
		hrs -= 1;
		return (2 + (hrs * 0.5));
	}
}