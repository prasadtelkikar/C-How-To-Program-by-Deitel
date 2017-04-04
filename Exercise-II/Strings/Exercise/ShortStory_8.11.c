#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5
#define SIZEOFSTORY 20		//Size is in number of sentences
int RandomGeneration();
char* GetSentence(char* article[], char* noun[], char* verbs[], char* preposition []);

int main(){
	char *article[SIZE] = {"the", "a", "one", "some", "any"};
	char *noun[SIZE] = {"boy", "girl", "dog", "town", "car"};
	char *verbs[SIZE] = {"drove", "jumped", "ran", "walked", "skipped"};
	char *preposition[SIZE] = {"to", "from", "over", "under", "on"};
	int i;
	srand(time(NULL));
	char* sentence = malloc(SIZEOFSTORY*1000);
	for (i = 0; i < SIZEOFSTORY; ++i){
		char* nextSentence = GetSentence(article, noun, verbs, preposition);
		if(i == 0)
			strcpy(sentence, nextSentence);
		else{
			strcat(sentence, " ");
			strcat(sentence, nextSentence);
		}
	}
	printf("%s\n",sentence);

	getch();
}

//Generating random number. SIZE is equal to size of character array
int RandomGeneration(){
	return rand() % SIZE;
}

//Append space to exisitng string and concatinate with source
char* StringConcatination(char* destination, char* source){
		if(strlen(destination)!=0 || destination != NULL)
			strcat(destination, " ");

		strcat(destination, source);	
}

//Generate sentence using words
char* GetSentence(char* article[], char* noun[], char* verbs[], char* preposition []){
		
		int randomForPreposition = RandomGeneration();
		int randomForArticle = RandomGeneration();
		int randomForNoun = RandomGeneration();
		int randomForVerbs = RandomGeneration();
		int randomForArticleEnd = RandomGeneration();
		int randomForNounEnd = RandomGeneration();
		char* str1 = malloc(1000);

		strcpy(str1, article[randomForArticle]);
		str1[0] = toupper(str1[0]);
		
		str1 = StringConcatination(str1, noun[randomForNoun]);
		str1 = StringConcatination(str1, verbs[randomForVerbs]);
		str1 = StringConcatination(str1, preposition[randomForPreposition]);
		str1 = StringConcatination(str1, article[randomForArticleEnd]);
		str1 = StringConcatination(str1, noun[randomForNounEnd]);

		int length = strlen(str1);
		str1[length] = '.';
		str1[length+1] = '\0';	

		return str1;
}