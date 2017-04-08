#include <stdio.h>
#include <conio.h>
#include <string.h>

void RecursiveFind(char* sentence, char* string);

int main(){
	char sentence[100];
	char string[10];

	printf("Enter sentence: ");
	gets(sentence);
	
	printf("\nEnter string to find in sentence: ");
	gets(string);

	RecursiveFind(sentence, string);

	return 1;
}

//Recursive function to extract substring.
void RecursiveFind(char* sentence, char* string){
	char* subSentence = strstr(sentence, string);
		if(subSentence == NULL)
			return;
		else{
			printf("%s\n", subSentence);
			RecursiveFind(subSentence+1, string);
		}
	}