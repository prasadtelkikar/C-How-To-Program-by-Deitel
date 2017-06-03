#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <queue>

struct Node{
	int data;
	struct Node* rightNode;
	struct Node* leftNode;
};
Node* CreateBST(Node* currentNode, int value);
Node* CreateNewNode(int value);
void InOrderTraversal(Node* rootNode);
void LevelOrderTraversal(Node* rootNode, int size);

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

	printf("\n");
	Node* currentNode = head;
	printf("%s\n", "InOrderTraversal :");
	InOrderTraversal(currentNode);
	
	printf("\n");
	for (int i = 0; i < 20; ++i)
		printf("-");
	printf("\n");
	
	currentNode = head;
	printf("%s\n", "Level order traversal :");
	LevelOrderTraversal(currentNode, size);
}

//Create binary search tree
Node* CreateBST(Node* currentNode, int value){

	if(currentNode == NULL)
		return CreateNewNode(value);
	else if(value > currentNode -> data)
		currentNode -> rightNode = CreateBST(currentNode -> rightNode, value);
	else if(value < currentNode -> data)
		currentNode -> leftNode = CreateBST(currentNode -> leftNode, value);

	return currentNode;
}

//Create new node
Node* CreateNewNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> data = value;
	newNode -> rightNode = NULL;
	newNode -> leftNode = NULL;

	return newNode;
}


//Inorder traversal
void InOrderTraversal(Node* currentNode){
	if(currentNode != NULL){
		InOrderTraversal(currentNode -> leftNode);
		printf("%d \t", currentNode -> data);
		InOrderTraversal(currentNode -> rightNode);
	}
} 

//Almost completed; still fix the bug
void LevelOrderTraversal(Node* rootNode, int size){
	Node* queue[size] = {NULL};
	int index = 0;
	int insertIndex = 0;
	if(rootNode == NULL)
		printf("Empty tree");
	else{
		queue[0] = rootNode;
		while(queue[index] != NULL && index < size){
			Node* current = queue[index];
			printf("%d\t", current -> data);

			if(current -> leftNode != NULL)
				queue[++insertIndex] = current -> leftNode;
			if(current -> rightNode != NULL)
				queue[++insertIndex] = current -> rightNode;

			index++;
		}
	}
}