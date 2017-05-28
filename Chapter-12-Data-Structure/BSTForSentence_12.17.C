#include <stdio.h>
#include <conio.h>
#include <string.h>
struct TreeNode{
	char* word;
	struct TreeNode* leftNode;
	struct TreeNode* rightNode;
};

int main(){
	char sentence[50];
	int length = 0;
	printf("\nEnter sentence: ");
	gets(sentence);

	char* wordPtr = strtok(sentence, " ");
	char* sentencePtr[50];

	while(wordPtr != NULL){
		sentencePtr[length] = wordPtr;
		length++;
		wordPtr = strtok(NULL, " ");
	}

	for (int i = 0; i < length; ++i)
		printf("%s\n", sentencePtr[i]);
	
	return 0;
}