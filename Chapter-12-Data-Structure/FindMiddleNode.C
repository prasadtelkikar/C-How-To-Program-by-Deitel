#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* nextNode;
};

Node* CreateList(Node* head, int x);
void Display(Node* head);
Node* FindMiddle(Node* head);

int main(){
	Node* head = NULL;
	Node* middleNode;

	int n, x;
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		printf("\nEnter an element: ");
		scanf("%d", &x);
		head = CreateList(head, x);
	}
	printf("\nLinked list: \n");
	Display(head);
	printf("\nMiddle Node: ");
	middleNode = FindMiddle(head);
	printf("%d", middleNode -> data);

	return 0;
}

/*Create Node and attach to the head of list*/
Node* CreateList(Node* head, int x){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> data = x;
	temp -> nextNode = NULL;
	if(head == NULL)
		head = temp;
	else{
		temp -> nextNode = head;
		head = temp;
	}
	return head;
}

/*Print Linked list*/
void Display(Node* head){
	if(head == NULL)
		printf("\nEmpty list");
	else{
		while(head != NULL){
			printf("%d ->", head -> data);
			head = head -> nextNode;
		}
		printf("NULL");
	}
}

/*Find middle of Linked list. Source: GeeksForGeeks*/
Node* FindMiddle(Node* head){
	Node* fastPtr = head;
	Node* slowPtr = head;
	
	if(head == NULL)
		printf("\nEmpty list");
	else{
		while(fastPtr != NULL && fastPtr -> nextNode != NULL){
				
			fastPtr = fastPtr -> nextNode -> nextNode;
			slowPtr = slowPtr -> nextNode;
		}
	}
	
	return slowPtr;
}