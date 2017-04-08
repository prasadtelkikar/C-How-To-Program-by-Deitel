#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 100
int main(){

	char sentence[SIZE];
	char* tokens[SIZE];
	int index;
	char* tokenPtr;
	//Read string from user
	printf("\nEnter a sentence (space is used for Tokenization): ");
	gets(sentence);

	//Tokenization of string 
	tokenPtr = strtok(sentence, " ");

	while(tokenPtr!= NULL){
		tokens[index] = tokenPtr;

		tokenPtr = strtok(NULL, " ");
		index++;
	}

	for (int i = index - 1; i >= 0; i--)
	{
		printf("%s\n", tokens[i]);
		//printf("%d - %s\n", i, tokens[i]); //Printing string with its index in char array
	}
	
	return 1;
}