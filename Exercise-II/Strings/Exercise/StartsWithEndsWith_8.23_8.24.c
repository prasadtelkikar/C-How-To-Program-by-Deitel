#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 200
void GetStringStartsWith(char* word[], char* ch, int arrLength);
void GetStringEndsWith(char* word[], char* ch, int arrLength);

int main(){
	char sentence[SIZE];
	char* tokens[SIZE];
	char ch[SIZE];
	int index = 0, choice = 0;
	int exit;

	//Enter sentence from user
	printf("\nEnter sentence: ");
	gets(sentence);

	//Tokenize strings
	char* tokenPtr = strtok(sentence, " ");
	while(tokenPtr!= NULL){
		tokens[index] = tokenPtr;
		tokenPtr = strtok(NULL, " ");
		index++;
	}

	//Menu driven program
	do{
		printf("\n1. To test starts with functionality");
		printf("\n2. To test ends with functionality");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter character to search words which starts with: ");
				scanf("%s", ch);
				GetStringStartsWith(tokens, ch, index);
				printf("\n");
			break;
			case 2:
				printf("\nEnter character to search words which ends with: ");
				scanf("%s", ch);
				GetStringEndsWith(tokens, ch, index);
				printf("\n");
			break;
			default:
				printf("Entered wrong choice");
			break;
		}
		printf("\nDo you want to continue (0 to exit): ");
		scanf("%d", &exit);
	}while(exit != 0);

	return 1;
}

//Get elements which starts with prifix string
void GetStringStartsWith(char* word[], char* prifix, int arrLength){
	int elemntFount = 0;
	printf("\nWords starts with %s: ", prifix);
	for (int i = 0; i < arrLength; ++i)
	{
		int isStartsWith = strncmp(word[i], prifix, strlen(prifix));
		if(isStartsWith == 0){
			elemntFount = 1;
			printf("\n\t%s", word[i]);
		}
	}
	if(elemntFount == 0)
		printf("\nNo element found");
}

//Get elements which ends with suffix string
void GetStringEndsWith(char* word[], char* suffix, int arrLength){
	int elemntFount = 0;
	printf("\nWords ends with %s", suffix);
	int lengthOfsuffix = strlen(suffix);
	for (int i = 0; i < arrLength; ++i)
	{
		int wordLength = strlen(word[i]);
		int isEndWith = strncmp(word[i] +wordLength-lengthOfsuffix, suffix, lengthOfsuffix);
		if(isEndWith == 0){
			elemntFount = 1;
			printf("\n\t%s", word[i]);		
		}
	}
	if(elemntFount == 0)
		printf("\nNo element found");
}