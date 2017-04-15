#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 8
//Took Help from: http://www.c-program-example.com/2012/05/c-program-to-convert-number-to-words.html
void ChequeProtection(char amount[]);
void ConvertNumberToWord(int amount);
void PrintIndex();

void UnitDigitPrint(int digit);
void TenDigitPrint(int digit);
void TenMultiple(int digit);

int main(){
	char amount[100];
	printf("\nEnter amount to be printed on cheque: ");
	gets(amount);
	ChequeProtection(amount);
//	PrintIndex();
	ConvertNumberToWord(atoi(amount));
	return 0;
}

// Append string in blank fields
void ChequeProtection(char amount[]){
	int length = strlen(amount);
	int i = 0, j = 0;
	char printChequeProAmount[20];
	if(length > MAXLENGTH)
		printf("\nMaximum length exceeded");
	else
	{
		int astricks = MAXLENGTH - length;
		for(i = 0; i < astricks; i++)
			printChequeProAmount[i] = '*';
		
		for(i = astricks; i < MAXLENGTH;i++){
			printChequeProAmount[i] = amount[j];
			j++;
		}
		printChequeProAmount[MAXLENGTH] = '\0';
		printf("%s\n", printChequeProAmount);
	}
}

//print index
void PrintIndex(){
	for(int i = 0; i < MAXLENGTH; i++)
		printf("-");

	printf("\n");
	
	for(int i = 0; i < MAXLENGTH; i++)
		printf("%d",i+1);
	printf("\n");
}

//Conversion of number to word
void ConvertNumberToWord(int number){
	if(number <= 0)
		printf("\nEmpty string");
	if(number > 9999)
		printf("\n Amount more than 9999 is not supported");

	int totalPosition, n1, digit, flag = 1, div, pos;
	div = 1;
	totalPosition = 0;
	n1 = number;

	while(n1 > 9){
		n1 = n1 / 10;
		div = div * 10;
		totalPosition++;
	}
	totalPosition++;
	pos = totalPosition;
	while(number != 0){
		digit = number / div;
		number = number % div;
		div = div / 10;
		switch(pos){
			case 1:
			if(flag)
				UnitDigitPrint(digit);
			break;
			case 2:
				if(digit == 1){
					flag = 0;
					TenDigitPrint(digit);
				}
				else{
					flag = 1;
					TenMultiple(digit);
				}
			break;
			case 3:
				UnitDigitPrint(digit);
				printf("Hundred ");
			break;
			case 4:
				UnitDigitPrint(digit);
				printf("Thousand ");
			break;
		}
	pos--;
	}
}
//print unit digit 
void UnitDigitPrint(int digit){
	switch(digit){
		case 1:printf("%s", "One ");break;
		case 2:printf("%s", "Two ");break;
		case 3:printf("%s", "Three ");break;
		case 4:printf("%s", "Four ");break;
		case 5:printf("%s", "Five ");break;
		case 6:printf("%s", "Six ");break;
		case 7:printf("%s", "Seven ");break;
		case 8:printf("%s", "Eight ");break;
		case 9:printf("%s", "Nine ");break;
	}
}

//print number from 10 to 19
void TenDigitPrint(int digit){
	switch(digit){
		case 0 : printf("ten ");break;
	    case 1 : printf("eleven ");break;
	    case 2 : printf("twelve ");break;
	    case 3 : printf("thirteen ");break;
	    case 4 : printf("fourteen ");break;
	    case 5 : printf("fifteen ");break;
	    case 6 : printf("sixteen ");break;
	    case 7 : printf("seventeen ");break;
	    case 8 : printf("eighteen ");break;
	    case 9 : printf("ninteen ");break;
	}
}

//Print 20, 30, 40, 50, 60, 70, 80, 90
void TenMultiple(int digit){
	switch(digit){
		case 2: printf("twenty ");break;
	    case 3: printf("thirty ");break;
	    case 4: printf("forty ");break;
	    case 5: printf("fifty ");break;
	    case 6: printf("sixty ");break;
	    case 7: printf("seventy ");break;
	    case 8: printf("eighty ");break;
	    case 9: printf("ninty ");break;	
	}
}