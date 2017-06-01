#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* rightNode;
	struct Node* leftNode;
};

struct Queue{
	int data;
	struct Queue* link;
};

void Push(int value);
Node* Pop(Node* queueHead);
Node* CreateBST(Node* currentNode, int value);
Node* CreateNewNode(int value);
void InOrderTraversal(Node* rootNode);

int main(){
	int size;
	Node* head = NULL;
	printf("%s\n", "\nEnter number of elements in bst: ");	
	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		int value;
		printf("%s\n", "Enter element: ");
		scanf("%d", &value);

		head = CreateBST(head, value);
	}
	InOrderTraversal(head);
}

Node* CreateBST(Node* currentNode, int value){

	if(currentNode == NULL)
		return CreateNewNode(value);
	else if(value > currentNode -> data)
		currentNode -> rightNode = CreateBST(currentNode -> rightNode, value);
	else if(value < currentNode -> data)
		currentNode -> leftNode = CreateBST(currentNode -> leftNode, value);

	return currentNode;
}

Node* CreateNewNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> data = value;
	newNode -> rightNode = NULL;
	newNode -> leftNode = NULL;

	return newNode;
}

void InOrderTraversal(Node* currentNode){
	if(currentNode != NULL){
		InOrderTraversal(currentNode -> leftNode);
		printf("%d \t", currentNode -> data);
		InOrderTraversal(currentNode -> rightNode);
	}
} 