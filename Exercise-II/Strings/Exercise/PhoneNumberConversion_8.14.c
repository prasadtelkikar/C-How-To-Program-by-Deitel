/*print area code and number from contact number, structure: (area code) first tree digit - actual number; print: area code and actual number*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char* GetAreaCode(char* areaCode);
char* GetNumber(char* number);

int main(){
	char contactNumber[30];
	char contact[3][30];
	char* tokenPtr;
	char* ch;
	char* ch1;
	int index = 0;
	long contactDetails;
	printf("\nEnter your contact number in (NNN) NNN-NNNN format: ");
	gets(contactNumber);

	tokenPtr = strtok(contactNumber, " ");
	while(tokenPtr != NULL){
		if(index == 0)
			ch = GetAreaCode(tokenPtr);
		else
			ch1 = GetNumber(tokenPtr);
	

	tokenPtr = strtok(NULL, " ");
		index++;
	}

	//Concatinate 2 numbers
	strcat(ch, ch1);

	//Convert string to long
	contactDetails = atol(ch);	
	printf("Contact details: %lu\n", contactDetails);
	
	return 0;
}

//Extracting area code from string.
char* GetAreaCode(char* areaCode){
	int lenght = (strlen(areaCode)-1);
	char ac[5];
	int i = 0;
	for(i = 1; i < lenght; i++)
		areaCode[i-1] = areaCode[i];

	areaCode[i-1] = '\0';

	return areaCode;
}

//Get your number
char* GetNumber(char* number){
	char* tokenPtr;
	int index = 0;
	tokenPtr = strtok(number, "-");
	//printf("%s\n", tokenPtr[1]);
	while(tokenPtr !=NULL){
		if(index = 1)
			return tokenPtr;

		tokenPtr = strtok(NULL, " ");
		index++;

	}
	return NULL;
}