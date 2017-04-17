#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node *nextNode;
};

typedef struct Node node;

void Insert(node *startNode, char character);
void DisplayList(node *startNode);
int Instructions();

int main(){
	int choice;
	node *startNode = NULL;
	char c;
	choice = Instructions();
	
	while(choice != 3){
		switch(choice){
			case 1:
			printf("\nEnter a character: ");
			scanf("%c", &c);
			Insert(startNode, c);
			//DisplayList(startNode);
			break;
			case 2:
			break;
		}
	}
	return 0;
}

int Instructions(){
	int choice;
	printf("\nOptions:");
	printf("\n\t1. Insert element to the list:");
	printf("\n\t2. Delete element from the list:");
	printf("\n\t3. Exit");
	printf("\nEnter your choice:");
	scanf("%d", &choice);
	char c = getchar();
	return choice;
}

void Insert(node *Node, char value){
	node *newNode, *previousNode, *currentNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode != NULL){
		newNode -> data = value;
		newNode -> nextNode = NULL;

		previousNode = NULL;
		currentNode = Node;
		
		while(currentNode != NULL && value > currentNode-> data){
			previousNode = currentNode;
			currentNode = currentNode -> nextNode;
		}

		if(previousNode != NULL){
			newNode -> nextNode = Node;
			*Node = newNode;
		}
		else{
			previousNode -> ntNode = newNode;
			newNode -> nextNode = currentNode;
	}
	else
		printf("\n%c not inserted. No memory available.", value);
		}
}

void DisplayList(node *startNode){
	if(startNode == NULL)
		printf("%s\n", "List is empty");
	else{
		printf("\nThe list is:\n");
		while(startNode != NULL){
			printf("%c ->", startNode ->data);
			startNode = startNode -> nextNode;
		}
	}
}