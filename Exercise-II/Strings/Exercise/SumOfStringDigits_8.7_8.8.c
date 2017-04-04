#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 4

int GetSumOfInt();
float GetSumOfFloat();

int main(){
	int sum = 0, ch, exit;
	float sumFloat = 0;
	do{
		printf("\n1. Sum of Int");
		printf("\n2. Sum of floats");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		getchar();
		switch(ch){
			case 1:
				sum = GetSumOfInt();
				printf("\n Sum of integers = %d", sum);
			break;
			case 2:
				sumFloat = GetSumOfFloat();
				printf("\n Sum of floats = %0.2f", sumFloat);
			break;
		}
		printf("\n\nDo you want to continue (0 to exit): ");
		scanf("%d", &exit);

	}while(exit != 0);
	getch();
}

//Use of atoi i.e strign to integer
int GetSumOfInt(){
	int i = 0, sum = 0;
	char string[200];
	
	while(i < SIZE){
		printf("\nEnter an Integer as a string: ");
		fgets(string, 10, stdin);
		sum += atoi(string);
		i++;
	}
	return sum;
}

//Use of atof i.e strign to float
float GetSumOfFloat(){
	int i = 0;
	char* string;
	float sub = 0.0;
	while(i < SIZE){
		printf("\nEnter an float value as a string: ");
		gets(string);
		sub += atof(string);
		i++;
	}
	return sub;
}