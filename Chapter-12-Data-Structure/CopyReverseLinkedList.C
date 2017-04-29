#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	char data;
	Node* nextdata;	
};
Node* CreateList(Node* head, char ch);
void Display(Node* head);
Node* ReverseCopy(Node* head);

int main(){
	char ch;
	Node* head = NULL;
	Node* revHead = NULL;
	for (int i = 0; i < 5; ++i)
		{

			printf("Enter character: ");
			ch = getchar();
			getchar();
			head = CreateList(head, ch);
		}	
		printf("\nOriginal list: ");
		Display(head);
		//Created copy of reverse list
		revHead = ReverseCopy(head);
		printf("\nReverse list");
		Display(revHead);
}

/* Add new node to the list */
Node* CreateList(Node* head, char ch){

	Node* temp = (Node*) malloc(sizeof(Node));
	temp -> data = ch;
	temp -> nextdata = NULL;

	if(head == NULL)
		head = temp;
	else{
		temp -> nextdata = head;
		head = temp;
	}
}

/* Display list */
void Display(Node* head){
	if(head == NULL)
		printf("\nList is empty\n");
	else{
		while(head != NULL){
			printf("%c ->", head -> data);
			head = head -> nextdata;
		}
		printf("NULL\n");
	}
}

/* Recursive reverse list */
Node* ReverseCopy(Node* head){

	if(head == NULL)
		return NULL;
	else if(head -> nextdata == NULL)
		return head;
	else{
		Node* temp = ReverseCopy(head -> nextdata);
		Node* next = head -> nextdata;
		next -> nextdata = head;
		head -> nextdata = NULL;
		return temp;
	}
}