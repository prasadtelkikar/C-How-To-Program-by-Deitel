#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void DrawLine();
void CountAlphabets(char* sentence, int length);
void CountWordLength(char* sentence, int length);
void CountOccurrencesWord(char* sentence);
int CountOccurrencesPerticularWord(char* sentence,char* tokenPtr);

int main(){

	char sentence[100];
	int i, length, ch, exit;
	
	printf("\nEnter the sentence: ");
	gets(sentence);
	length = strlen(sentence);

	do{
	printf("\n1. Count alphabets");
	printf("\n2. Count length of words");
	printf("\n3. Count occurrences of words");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch){
		case 1:
		CountAlphabets(sentence, length);
		break;
		case 2:
		CountWordLength(sentence, length);
		break;
		case 3:
		CountOccurrencesWord(sentence);
		break;
	}
	printf("\nDo you want to continue (0 for exit): ");
	scanf("%d", &exit);
	}while(exit != 0);

	return 1;
}

void CountAlphabets(char* sentence, int length){
	int arr[26] = {0};
	//Used ASCII value to count the occurrences of alphabets
	for (int i = 0; i < length; ++i)
		arr[tolower(sentence[i]) - 'a']++;
	
	//Print in tabular format.
	DrawLine();
	printf("\n%2s | %2s\n", "Letter", "Count");
	DrawLine();
	for(int i = 0;i < 26; i++)
		printf("\n%3c %3s %3d",(i+'a'), "-", arr[i]);

}

void DrawLine(){
	for (int i = 0; i < 20; ++i)
		printf("-");
}

void CountWordLength(char* sentence, int length){
	int arr[50] = {0};
	int maxLength = 0;
	char *tokenPtr = strtok(sentence," ");
 
	while(tokenPtr!= NULL){
		int length = strlen(tokenPtr);
		if(length > maxLength)
			maxLength = length;

		arr[length]++;
		tokenPtr = strtok(NULL, " ");
	}

	DrawLine();
	printf("\n%2s | %2s\n", "word Length", "Count");
	DrawLine();
	for (int i = 1; i <= maxLength; ++i)
		printf("\n%6d %3s %3d",i, "-", arr[i]);

}

void CountOccurrencesWord(char* sentence){
	char* tokenPtr = strtok(sentence, " ");
	DrawLine();
	printf("\n%2s | %2s\n", "words", "Count");
	DrawLine();
	while(tokenPtr != NULL){
		int count =	CountOccurrencesPerticularWord(sentence, tokenPtr);
		printf("\n%2s%6d", tokenPtr, count);
		tokenPtr = strtok(NULL, " ");
	}
}

int CountOccurrencesPerticularWord(char* sentence,char* tokenPtr){
	int count = 1;
	char* strPtr = strstr(sentence, tokenPtr);

	while (strPtr != NULL)
	{
		count++;
		strPtr = strstr(sentence+1, tokenPtr);
	}
	return count;
}