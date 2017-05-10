#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	int count;
	Node* leftPtr;
	Node* rightPtr;	
};

Node* InsertNode(Node* rootNode, int value);
Node* CreateNewNode(int value);

void InorderTraversal(Node* rootNode);
void PreorderTraversal(Node* rootNode);
void PostorderTraversal(Node* rootNode);
Node* SearchNode(Node* rootNode, int value);
Node* DeleteNode(Node* rootNode, int value);
void DisplayAllTraversal(Node* rootNode);

int main(){
	int size;
	Node* rootNode = NULL;
	int searchNumber = 0;
	int deleteNumber = 0;

	printf("\n%s", "Enter number of leaves: ");
	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		int nodeValue = 0;
		printf("\n%s", "Enter value(Supports duplicate values): ");
		scanf("%d", &nodeValue);
		getchar();
		if(rootNode == NULL)
			rootNode = InsertNode(rootNode, nodeValue);
		else{
			rootNode = InsertNode(rootNode, nodeValue);	
		}
	}

	DisplayAllTraversal(rootNode);
	
	printf("\nEnter Number to search: ");
	scanf("%d", &searchNumber);

	Node* searchFound = SearchNode(rootNode, searchNumber);
	if(searchFound != NULL)
		printf("\n%d\t%s", searchFound -> data, "Element found in the tree");
	else
		printf("\n%s", "Element not found");

	printf("\n%s", "Enter number to be deleted: ");
	scanf("%d", &deleteNumber);

	//Node* rootNode = DeleteNode(rootNode, deleteNumber);
}

/* Create new node */
Node* CreateNewNode(int value){
	
	Node* temp = (Node*) malloc(sizeof(Node));
	temp -> data = value;
	temp -> count = 1;
	temp -> leftPtr = NULL;
	temp -> rightPtr = NULL;

	return temp;
}

/* Insert node at its position */
Node* InsertNode(Node* rootNode, int value){
	
	if(rootNode == NULL)
		return CreateNewNode(value);
	else if(value == rootNode -> data)
		rootNode -> count++;
	else if(value > rootNode -> data)
		rootNode -> rightPtr =InsertNode(rootNode -> rightPtr, value);
	else if(value < rootNode -> data)
		rootNode -> leftPtr = InsertNode(rootNode -> leftPtr, value);

	return rootNode;
}

/* Inorder traversal */
void InorderTraversal(Node* rootNode){
	if(rootNode != NULL){
	InorderTraversal(rootNode -> leftPtr);
	printf("%d(%d)\t", rootNode -> data, rootNode -> count);
	InorderTraversal(rootNode -> rightPtr);
	}
}

/* Preorder traversal */
void PreorderTraversal(Node* rootNode){
	if(rootNode != NULL){
	printf("%d(%d)\t", rootNode -> data, rootNode -> count);
	PreorderTraversal(rootNode -> leftPtr);
	PreorderTraversal(rootNode -> rightPtr);
	}
}

/* Postorder traversal */
void PostorderTraversal(Node* rootNode){
	if(rootNode != NULL){
	PostorderTraversal(rootNode -> leftPtr);
	PostorderTraversal(rootNode -> rightPtr);
	printf("%d(%d)\t", rootNode -> data, rootNode -> count);
	}
}

/* Search node with value */
Node* SearchNode(Node* rootNode, int value){
	bool isAvailable = false;	
	if(rootNode == NULL || rootNode -> data == value)
		return rootNode;
	else{
		if(value  > rootNode -> data)
			return SearchNode(rootNode -> rightPtr, value);
		if(value < rootNode -> data)
			return SearchNode(rootNode -> leftPtr, value);
	}
}

void DisplayAllTraversal(Node* rootNode){
	printf("\n%s", "Inorder Traversal:\n\t");
	InorderTraversal(rootNode);
	printf("\n%s", "Preorder Traversal:\n\t");
	PreorderTraversal(rootNode);
	printf("\n%s", "Postorder Traversal:\n\t");
	PostorderTraversal(rootNode);
}

Node* DeleteNode(Node* rootNode, int value){
	//TODO: complete delete function
}