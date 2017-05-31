#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* CreateList(Node* rootNode, int value);
void DisplayList(Node* rootNode);
void PrintListBackword(Node* rootNode);

int main(){
	int size =0;
	int nodeData;
	Node* rootNode = NULL;
	printf("\nEnter size of list:");
	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		printf("\nEnter value: ");
		scanf("%d", &nodeData);
		rootNode = CreateList(rootNode, nodeData);
	}

	PrintListBackword(rootNode);
	DisplayList(rootNode);
	return 0;
}

Node* CreateList(Node* currentNode, int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> data = value;
	newNode -> next = NULL;

	if(currentNode == NULL)
		return newNode;
	else{
		Node* temp = currentNode;
		while(temp ->next != NULL)
			temp = temp -> next;
		
		temp -> next = newNode;
		return currentNode;
	}
}

void PrintListBackword(Node* rootNode){
	if(rootNode == NULL)
		return ;

	PrintListBackword(rootNode -> next);
	printf("\n%d", rootNode -> data);
}

void DisplayList(Node* rootNode){
	for (Node* currentNode = rootNode; currentNode != NULL 	; currentNode = currentNode -> next)
		printf("\n%d", currentNode -> data);
}