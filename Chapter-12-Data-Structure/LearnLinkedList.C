//Learning basics of Linked list from utube channel: mycodeschool
/*3 ways to do same program: 1) use head as a global variable. 2) pass by value (in insert Pass Node* variableName)
							  3) Pass by reference (in insert pass by reference (Node** variableName))*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

//Node* head; //--global declaration.
Node* Insert(Node* head, int data);
Node* InsertAtNth(Node* head, int data, int location);
Node* DeleteAtNth(Node* head, int location);
Node* Reverse(Node *head);
Node* ReverseRecursively(Node* currentNode);
void DisplayList(Node* head);
void DisplayListRecursively(Node* head);
void DisplayReverseListRecursively(Node* head);
int Instructions();

int main(){
	Node* head = NULL;
	int size, data;
	int x, location;
	int choice = 0;
	while(choice != 6){
		choice = Instructions();
		switch(choice){
			case 1:	
				printf("\nHow many numbers you want to insert: ");
				scanf("%d", &size);
				for (int i = 0; i < size; ++i)
				{
					printf("\nEnter a number: ");
					scanf("%d", &x);
					head = Insert(head, x);
				}		
			break;
			case 2:
				printf("\nEnter location to insert: ");	
				scanf("%d", &location);
				printf("\nEnter element to insert at position %d: ", location);
				scanf("%d", &data);
				head = InsertAtNth(head, data, location);
			break;
			case 3:
				printf("\nEnter location to insert: ");	
				scanf("%d", &location);
				head = DeleteAtNth(head, location);				
			break;
			case 4:
				printf("\nReversed linked list");
				//head = Reverse(head);
				head = ReverseRecursively(head);
			break;
			case 5:
				//DisplayListRecursively(head);
				//DisplayReverseListRecursively(head);
				DisplayList(head);
			break;
		}
	}
}

//Menu driven choice
int Instructions(){
	int choice;
	printf("\n1. Insert elements: ");
	printf("\n2. Insert element at nth position");
	printf("\n3. Delete element at nth position");
	printf("\n4. Reverse linked list");
	printf("\n5. Print");
	printf("\n6. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	return choice;

}

//Insert nodes 
Node* Insert(Node* head ,int data){
	Node* temp = (Node *)malloc(sizeof(Node));
	temp -> data = data;
	temp-> next = NULL;

	if(head != NULL)
		temp->next = head;
	head = temp;

	return head;
}

//Insert node at a perticular position
Node* InsertAtNth(Node* head, int data, int location){
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1 -> data = data;
	temp1 -> next = NULL;
	if(location = 1){
		temp1 -> next = head;
		head = temp1;
		return head;
	}
	Node* temp = head; 
	for (int i = 0; i < location - 2; ++i)
		temp = temp -> next;

	temp1 -> next = temp;
	temp -> next = temp1;
	return head;
}

//Delete element present on Nth location
Node* DeleteAtNth(Node* head, int location){
	Node* temp = head;
	Node* deletingNode;
	if(location == 1){
		temp = temp -> next;
		head = temp;
		return head;
	}
	else{
		for (int i = 0; i < location - 2; ++i)
			temp = temp -> next;	

		deletingNode = temp -> next;
		temp -> next = deletingNode -> next;
		free(deletingNode);
		return head;
	}
}

//Reverse the linked list
Node* Reverse(Node *head){
	Node *previous, *current, *next;
	previous = NULL;
	current = head;

	while(current != NULL){
		next = current -> next;
		current -> next = previous;
		previous = current;
		current = next;
	}
	head = previous;
	return head;
}

//Reverse list using recursion
Node* ReverseRecursively(Node* currentNode){

	if(currentNode == NULL)
		return NULL;
	if(currentNode -> next == NULL)
		return currentNode;

	Node* temp = ReverseRecursively(currentNode -> next);
	Node* p = currentNode -> next;
	p -> next = currentNode;
	currentNode -> next = NULL;
	return temp;
}
//Print all elements from list.
void DisplayList(Node* head){
	printf("%s\n", "List is: ");
	while(head != NULL){
		if(head -> next == NULL)
			printf("%d -> NULL", head -> data);
		else
			printf("%d -> ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

//print all elements recursively
void DisplayListRecursively(Node* head){
	if(head == NULL)
		return;
	printf("%d ", head -> data);
	DisplayListRecursively(head -> next);
}

//print all elements in reverse order
void DisplayReverseListRecursively(Node* head){
	if(head == NULL)
		return;

	DisplayReverseListRecursively(head -> next);
	printf("%d ", head ->data);
}

