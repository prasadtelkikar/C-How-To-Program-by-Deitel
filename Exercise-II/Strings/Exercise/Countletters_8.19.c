#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void DrawLine();

int main(){

	char sentence[100];
	int i, length;
	int arr[26] = {0};
	printf("\nEnter the sentence: ");
	gets(sentence);

	//Used ASCII value to count the occurrences of alphabets
	for (int i = 0; i < strlen(sentence); ++i)
		arr[tolower(sentence[i]) - 'a']++;
	
	//Print in tabular format.
	DrawLine();
	printf("\n%2s | %2s\n", "Letter", "Count");
	DrawLine();
	for(int i = 0;i < 26; i++)
		printf("\n%3c %3c %3d",(i+'a'), "-",arr[i]);

	return 1;
}

void DrawLine(){
	for (int i = 0; i < 20; ++i)
		printf("-");
}