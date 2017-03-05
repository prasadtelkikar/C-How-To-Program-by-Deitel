/*Ask question using RAND function*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void main(){
	int firstOperand, secondOperand, answer;
	int size = 10;
	char choice;
	char a;
	clrscr();
	srand(time(NULL));
	do{
		firstOperand = 1 + rand() % 10;
		secondOperand = 1 + rand() % 10;

		printf("How much is %d 	times %d?", firstOperand, secondOperand);

		printf("\n\n\nTo display sum: Press A:");
		a = getchar();

		if(a == 'A' || a == 'a')
			printf("\nAnswer of %d + %d = %d", firstOperand, secondOperand, (firstOperand + secondOperand));
		else
			printf("Wrong input. Answer is not visible");

		printf("\nEnter charactor yes to continue:(Y/N)");
		choice = getchar();
		getchar();
	  }while(choice == 'y');
	getch();
}