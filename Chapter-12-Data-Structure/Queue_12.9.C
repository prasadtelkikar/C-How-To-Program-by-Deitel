#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* nextNode;
};

int Instructions();
Node* Enqueue(Node* head, int x);
Node* Dequeue(Node* head);
void Display(Node* head);

int main(){
	Node* head = NULL;
	int value, choice, n, x;
	while(choice != 4){
		choice = Instructions();
		switch(choice){
			case 1:
				printf("\nEnter number: ");
				scanf("%d", &n);
				getchar();
				for (int i = 0; i < n; ++i)
				{
					printf("\nEnter an element: ");
					scanf("%d", &x);
					head = Enqueue(head, x);
				}
			break;
			case 2:
			head = Dequeue(head);
			break;
			case 3:
			Display(head);
			break;
		}
	}
	return 0;
}

int Instructions(){
	int choice = 0;
	printf("\n 1. Enqueue Element");
	printf("\n 2. Dequeue Element");
	printf("\n 3. Display Queue");
	printf("\n 4. Exit");
	printf("\n Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

Node* Enqueue(Node* head, int x){
	Node* temp = (Node*)malloc(sizeof(Node));

	temp -> data = x;
	temp -> nextNode = NULL;
	Node* currentNode = head;
	if(head == NULL){
		head = temp;
		return head;
	}
	else{
		while(currentNode ->nextNode != NULL){
			currentNode = currentNode -> nextNode;
		}
		currentNode->nextNode = temp;
		return head;
	}
}

Node* Dequeue(Node* head){
	Node* currentNode = head;
	if(currentNode == NULL){
		printf("\nQueue is empty");
		return head;
	}
	else{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp = currentNode;
		printf("\nDequeued element: %d", temp -> data);
		head = currentNode -> nextNode;
		free(temp);
		return head;
	}
}

void Display(Node* head){
	Node* currentNode = head;
	if(currentNode == NULL)
		printf("\nQueue is empty");
	else{
		while(currentNode != NULL){
			if(currentNode -> nextNode == NULL)
				printf("%d -> NULL", currentNode -> data);
			else
				printf("%d -> ", currentNode -> data);

			currentNode = currentNode -> nextNode;
		}
	}
}