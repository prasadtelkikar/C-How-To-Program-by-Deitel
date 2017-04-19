//Doubly linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* previous;
	struct Node* next;
};

Node* CreateNode(int x);
int Instructions();
void InsertAtHead(int x);
void InsertAtTail(int x);
void DisplayList();
void DisplayListReverse();

Node* head;
int main(){
	int choice = 0;
	int n;
	int number;
	while(choice != 5){
		choice = Instructions();
		switch(choice){
			case 1:
			printf("\nEnter number of elements to be insert at head: ");
			scanf("%d", &n);
			for (int i = 0; i < n; ++i)
			{
				printf("\n%s", "Enter Number: ");
				scanf("%d", &number);
				InsertAtHead(number);
			}
			break;
			case 2:
				printf("\nEnter number of elements to be inserted at tail");
				scanf("%d", &n);
				for (int i = 0; i < n; ++i)
				{				
					printf("\n%s", "Enter Number: ");
					scanf("%d", &number);
					InsertAtTail(number);
				}
			break;
			case 3:
				printf("%s\n", "List is: ");
				DisplayList();
			break;
			case 4:
				printf("%s\n", "List is");
				DisplayListReverse();
			break;
		}
	}
	return 0;
}

//Menu driven program
int Instructions(){
	int choice = 0;
	printf("\n1. Insert elements at head");
	printf("\n2. Insert elements at tail");
	printf("\n3. Display elements");
	printf("\n4. Display list in reverse order");
	printf("\n5. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	return choice;
}

//Create a new node
Node* CreateNode(int x){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = x	;
	newNode -> previous = NULL;
	newNode -> next = NULL;
	return newNode;
}

//Insert node at head of the list
void InsertAtHead(int x){
	Node* temp = CreateNode(x);
	if(head == NULL){
		head = temp;
	}
	else{
		head -> previous = temp;
		temp -> next = head;
		head = temp;	
	}
}

//Insert node at tail of the list
void InsertAtTail(int x){
	Node* temp = CreateNode(x);
	Node* currenNode = head;
	if(head == NULL)
		head = temp;
	else{
		while(currenNode -> next != NULL)
			currenNode = currenNode ->next;

		
		temp -> previous = currenNode;
		currenNode -> next = temp;
		temp -> next = NULL; 
	}
}

//Display list in forward direction
void DisplayList(){
	Node* temp = head;
	printf("%s\n", "Forwards list:");
	while(temp != NULL){
		if(temp -> next == NULL)
			printf("%d -> NULL",temp -> data);
		else
			printf("%d ->", temp -> data);
		temp = temp -> next;
	}
}

//Display list in backward direction
void DisplayListReverse(){
	Node* temp = head;
	while(temp->next != NULL)
		temp = temp -> next;
	printf("%s\n", "Backward List:");

	while(temp != NULL){
		if(temp -> next == NULL)
			printf("Null ->%d", temp -> data);
		else
			printf(" ->%d", temp -> data);

		temp = temp -> previous;
	}
}