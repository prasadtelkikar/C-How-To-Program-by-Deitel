#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <stdlib.h>
//TODO: half done; delete functionality is remaining
struct Node{
	char data;
	struct Node *nextNode;
};

int Instructions();
Node* InsertNode(Node* head, char c);
Node* DeleteNode(Node* head, char c);
void DisplayList(Node* head);

int main(){
	Node* head = NULL;
	int choice = 0, n;
	char c;
	char* cq;
	while(choice != 4){
		choice = Instructions();
		switch(choice){
			case 1:
			getchar();
			printf("\nEnter number of characters to be insert: ");
			scanf("%d", &n);
			getchar();
			for (int i = 0; i < n; ++i)
			{
				printf("\nEnter a character: ");
				scanf("%c", &c);
				getchar();
				head = InsertNode(head, c);
			}
			break;
			case 2:
			break;
			case 3:
				DisplayList(head);
			break;
		}
	}
}

int Instructions(){
	int choice;
	printf("1. Insert a character into a list");
	printf("\n2. Delete a character from a list");
	printf("\n3. Display List");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	return choice;
}

Node* InsertNode(Node* head, char c){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> data = c;
	temp -> nextNode = NULL;
	Node* currentNode = head;
	Node* previousNode = NULL;

	if(head == NULL){	
		head = temp;
		return head;
	}
	else{
		while(currentNode != NULL && c > currentNode -> data){
			previousNode = currentNode;
			currentNode = currentNode -> nextNode;
		}
		previousNode -> nextNode = temp;
		temp -> nextNode = currentNode;
		return head;
	}
}


void DisplayList(Node* head){
	Node* currentNode = head;
	while(currentNode != NULL){
		if(currentNode -> nextNode == NULL)
			printf("%c -> NULL",currentNode ->data);
		else
			printf("%c -> ", currentNode -> data);
		currentNode = currentNode -> nextNode;
	}
	printf("\n");
}
