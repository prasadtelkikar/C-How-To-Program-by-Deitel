#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

Node* SearchElement(Node* rootNode, int value);
Node* CreateList(Node* currentNode, int value);
void Display(Node* currentNode);

int main(){
	int size, value;
	int searchValue = 0;
	Node* head = NULL;
	Node* searchResult = NULL;
	printf("\nEnter size of list: ");
	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		printf("\nEnter element: ");
		scanf("%d", &value);
		head = CreateList(head, value);
	}

	printf("\nElement to be search: ");
	scanf("%d", &searchValue);
	
	searchResult = SearchElement(head, searchValue);
	
	if(searchResult != NULL)
		printf("\n%d element found at memory location %u\n", searchResult -> data, searchResult -> next);
	else
		printf("%s\n", "Element is not in the list");

	Display(head);
}

//Insert element at last
Node* CreateList(Node* head, int value){
	Node* nextNode = (Node*)malloc(sizeof(Node));
	nextNode -> data = value;
	nextNode -> next = NULL;
	Node* currentNode = head;

	if(currentNode == NULL)
		return nextNode;
	else{
		while(currentNode -> next != NULL)
			currentNode = currentNode -> next;

		currentNode -> next = nextNode;
	}
	return head;
}

//Display list in forward direction
void Display(Node* head){
	printf("\n");
	for (Node* currentNode = head; currentNode != NULL; currentNode = currentNode -> next)
		printf("%d ", currentNode -> data);
}

//Search element if not found then return null: Recursive call.
Node* SearchElement(Node* head, int value){
	if(head == NULL || head -> data == value)
		return head;
	SearchElement(head -> next, value);
}