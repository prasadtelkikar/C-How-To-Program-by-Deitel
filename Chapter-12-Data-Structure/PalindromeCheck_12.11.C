#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	Node* nextNode;
};

Node* CreateNode(Node* head, int x);
Node* Reverse(Node* head);
bool IsPalindrome(Node* head);
void Display(Node* head);
bool IsEquals(Node* firstHalfHead, Node* secondHalfHead);

int main(){
	int size, x;
	Node* head = NULL;
	printf("%s\n", "Enter size of linked list: ");
	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		printf("%s\n", "Enter an element: ");
		scanf("%d", & x);
		head = CreateNode(head, x);
	}
	printf("\nList contains: \n\t");
	Display(head);
	printf("\n");
	if(IsPalindrome(head))
		printf("\nList is palindrome");
	else
		printf("\nList is Not palindrome");

	printf("\n");
} 

/*Create a list*/
Node* CreateNode(Node* head, int x){
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

/*Display elements of the list*/
void Display(Node* head){
	Node* CurrentNode = head;
	if(CurrentNode == NULL)
		printf("%s\n","Empty linked list");
	else{
		while(CurrentNode != NULL){
			printf("%d -> ", CurrentNode -> data);
			CurrentNode = CurrentNode -> nextNode;
		}
		printf("NULL");
	}
}

/*Reverse the list*/
Node* Reverse(Node* head){
	Node* previous = NULL;
	Node* currentNode = head;
	Node* next = head;
	if(head != NULL){
		while(currentNode != NULL){
			next = currentNode -> nextNode;
			currentNode -> nextNode = previous;
			previous = currentNode;
			currentNode = next;
		}
	}
	return previous;
}

/*Check list is a palindrome or not. Required functions: Reverse and IsEquals*/
bool IsPalindrome(Node* head){
	Node* slowNode = head;
	Node* fastNode = head;
	Node* secondHalf = head;
	Node* firstHalf = NULL;

	while(fastNode != NULL && fastNode -> nextNode != NULL){
		fastNode = fastNode -> nextNode -> nextNode;
		firstHalf = slowNode;
		slowNode = slowNode -> nextNode;
	}
	/*If size of list is even*/
	if(fastNode == NULL)
		secondHalf = slowNode;
	else
		secondHalf = slowNode -> nextNode;

	/*To create 2 different lists*/
	firstHalf -> nextNode = NULL;
	/*Reverse second list to compare with first one*/
	secondHalf = Reverse(secondHalf);
	return IsEquals(head, secondHalf);
}

/*Compare the two different list*/
bool IsEquals(Node* firstHalfHead, Node* secondHalfHead){
	while(firstHalfHead != NULL || secondHalfHead != NULL){
		if(firstHalfHead -> data != secondHalfHead -> data)
			return false;
		firstHalfHead = firstHalfHead -> nextNode;
		secondHalfHead = secondHalfHead -> nextNode;
	}
	return true;
}