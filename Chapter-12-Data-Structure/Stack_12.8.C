#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

Node* Push(Node* top, int x);
Node* Pop(Node* top);
void DisplayStack(Node* top);
int Instruction();

int main(){
	Node* top = NULL;
	int x, n;
	int choice = 0;
	while(choice != 4){
		choice = Instruction();
		switch(choice){
			case 1:
			printf("\nEnter number of elements to be push into the stack: ");
			scanf("%d", &n);
			for (int i = 0; i < n; ++i)
			{			
				printf("\nEnter an element: ");
				scanf("%d", &x);
				top = Push(top, x);
			}
			break;
			case 2:
			top = Pop(top);
			break;
			case 3:
			DisplayStack(top);
			break;
		}
	}
	return 0;
}

int Instruction(){
	int choice;
	printf("\n\n1. Push into Stack");
	printf("\n2. Pop from Stack");
	printf("\n3. Display Stack");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	return choice;
}

Node* Push(Node* top, int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = value;
	newNode -> next = NULL;

	if(top != NULL)
		newNode -> next = top;
	
	top = newNode;
	return top;
}

Node* Pop(Node* top){
	Node* nodeToPop = (Node*)malloc(sizeof(Node));
	if(top == NULL)
		printf("\nStack is empty");
	else{
		nodeToPop = top;
		printf("\nPopped element: %d", nodeToPop -> data);

		top = nodeToPop -> next;
		free(nodeToPop);	
	}
	return top;
}

void DisplayStack(Node* top){
	Node* CurrentNode = top;
	if(CurrentNode == NULL)
		printf("\nStack is empty");
	else{
		printf("\n");
		while(CurrentNode != NULL){
			if(CurrentNode -> next == NULL)
				printf("%d -> NULL\n", CurrentNode -> data);
			else
				printf("%d ->", CurrentNode -> data);
		CurrentNode = CurrentNode -> next;
		}	
		printf("\n");
	}
}