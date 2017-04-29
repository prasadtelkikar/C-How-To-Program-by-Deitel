#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	char letter;
	Node* next;
};

Node* Push(Node* top, char ch);
void Pop(Node* top);

int main(){
	int i = 0;
	Node* stackTop = NULL;
	char sentence[30];
	printf("\nEnter a string: ");
	scanf("%s", sentence);

	while(sentence[i] != '\0'){
		stackTop = Push(stackTop, sentence[i]);
		i++;
	}
	Pop(stackTop);
}

/* Stack Push function */
Node* Push(Node* top, char ch){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> letter = ch;
	temp -> next = NULL;
	if(top != NULL)
		temp -> next = top;

	top = temp;
	return top;
}

/*Pop function*/
void Pop(Node* top){
	
	if(top == NULL)
		printf("\nStack is empty");
	else{
		printf("\nReversed string: ");
		while(top != NULL){
			Node* temp = (Node*)malloc(sizeof(Node));
			temp -> letter = top -> letter;
			temp -> next = NULL;
			top = top -> next;
			printf("%c", temp -> letter);
			free(temp);	
		}
	}
}

