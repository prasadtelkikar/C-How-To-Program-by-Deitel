/*Conversion of string to latin word*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

void PrintLatinWord(char* tokenPtr);
void StringTokenization(char* sentence);

int main(){
	char sentence[200];
	printf("\nEnter a line of text: ");
	gets(sentence);

	StringTokenization(sentence);

	getch();
}

//Tokenizing string
void StringTokenization(char* sentence){
	char* tokenPtr;

	tokenPtr = strtok(sentence, " ");
	while(tokenPtr != NULL){
		PrintLatinWord(tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
}

//Conversion of string to pig latin i.e moving first letter to last and appending "ay" to it.
void PrintLatinWord(char* tokenPtr){
	char string[200];
	int index = 0;
	int length = (strlen(tokenPtr) - 1);
	
	while(index < length){
		string[index] = tokenPtr[index+1];
		index++;
	}

	string[index] = tokenPtr[0];
	string[index+1] = '\0';
	strcat(string, "ay");

	puts(string);
}