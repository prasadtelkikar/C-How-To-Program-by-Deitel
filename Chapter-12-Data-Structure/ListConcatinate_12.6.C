#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

Node* GetDetails(Node* string1);
void Concatinate(Node* string1, Node* string2);
Node* AppendNode(Node* head, char ch);
void DisplayList(Node* string);

int main(){
	Node* string1 = NULL;
	Node* string2 = NULL;
	int n;
	char ch;
	string1 = GetDetails(string1);
	string2 = GetDetails(string2);
	Concatinate(string1, string2);

	printf("\n");
	DisplayList(string1);
	printf("\n");
	return 0;
}

//Get nodes of linked list
Node* GetDetails(Node* string1){
	int n;
	char ch;
	printf("\nEnter number of elements: ");
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		printf("\nEnter character: ");
		scanf("%c", &ch);
		getchar();
		string1 = AppendNode(string1, ch);
	}
	return string1;
}

//Append node to the list
Node* AppendNode(Node* head, char ch){
	Node* character = (Node*)malloc(sizeof(Node));
	character -> data = ch;
	character -> next = NULL;
	Node* temp = head;

	if(head == NULL){
		head = character;
		return head;
	}
	else{
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = character;
	}
	return head;
}

//string 2 concatinate with string 1
void Concatinate(Node* string1, Node* string2){
	if(string1 == NULL)
		string1 = string2;

	else{
		while(string1 -> next != NULL)
			string1 = string1 -> next;
		string1 -> next = string2;
	}
}

//Print the list
void DisplayList(Node* head){
	if(head == NULL)
		printf("\nList is empty");
	else{
		while(head != NULL){
			printf("%c ", head -> data);
			head = head -> next;
		}
	}
}
