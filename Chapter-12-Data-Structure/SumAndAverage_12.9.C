#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 25

struct Node{
	int data;
	Node* nextNode;
};

Node* CreateLinkedList(Node* head);
Node* Accept(Node* head, int x);
void Display(Node* head);
int Addition(Node* head);

int main(){
	Node* head = NULL;
	int x, sum;
	srand(time(NULL));
	
	head = CreateLinkedList(head);
	sum = Addition(head);
	float avg = (float) sum / SIZE;

	Display(head);
	printf("\nAddition of all elements: %d\n\n", sum);
	printf("\nAverage of all elements: %.2f\n\n", avg);

	return 0;
}

/* Create a linked list containing random number from 1 to 100 */
Node* CreateLinkedList(Node* head){
	int r = 0;
	for (int i = 0; i < SIZE; ++i){
			int r = rand() % 100 + 1;
			head = Accept(head, r);
		}
		return head;
}

/* Add new number at head of linked list. Time complexity is O(1) where 
  complexity of adding number to the end of list is O(n) */
Node* Accept(Node* head, int randomNumber){
	Node* current = head;
	Node* temp = (Node*) malloc(sizeof(Node));
	temp -> data = randomNumber;
	temp -> nextNode = NULL;
	if(head == NULL)
		head = temp;
	else{
		temp -> nextNode = head ;
		head = temp;
	}
	return head;
}

/* Display linked list */
void Display(Node* head){
	if(head == NULL)
		printf("\nList is empty");
	else{
		while(head != NULL){
			if(head -> nextNode == NULL)
				printf("%d -> NULL", head -> data);
			else
				printf("%d -> ", head -> data);
			head = head -> nextNode;
		}
	}
}

/* summation of linked list elements */
int Addition(Node* head){
	int sum = 0;
	while(head != NULL){
		sum += head -> data;
		head = head -> nextNode;
	}
	return sum;
}