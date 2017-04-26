#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* nextData;
};

Node* GetNodeList(Node* head, int listNumber);
Node* Accept(Node* head, int x);
Node* Sort(Node* head);
void Display(Node* head);
void Merge(Node* head1, Node* head2);
int GetLength(Node* head);
void Swap(Node* a, Node* b);

int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;

	head1 = GetNodeList(head1, 1);
	head2 = GetNodeList(head2, 2);
	printf("\nFirst List: \n");
	Display(head1);
	printf("\nSecond List: \n");
	Display(head2);

	Merge(head1, head2);
	
	printf("\nMerged list before sorting: \n");
	Display(head1);
	/*Source: GeeksForGeeks*/
	head1 = Sort(head1);

	printf("\nMerged list before sorting: \n");
	Display(head1);

	printf("\n");
	return 0;
}

/*Read node from user*/
Node* GetNodeList(Node* head, int listNumber){
	int count = 0;
	int x;
	printf("\nEnter number of Element in %d(st/nd) order list: ", listNumber);
	scanf("%d", &count);
	getchar();
	for (int i = 0; i < count; ++i)
	{
		printf("\nEnter the element: ");
		scanf("%d", &x);
		getchar();
		head = Accept(head, x);
	}
	return head;
}

//Add node at the end of list
Node* Accept(Node* head, int x){
	 Node* temp = (Node*)malloc(sizeof(Node));
	 temp -> data = x;
	 temp -> nextData = NULL;
	 Node* curretNode = head;

	 if(head == NULL)
	 	head = temp;
	 else{
	 	while(curretNode -> nextData != NULL)
	 		curretNode = curretNode -> nextData;

	 	curretNode -> nextData = temp;
	 }
	 return head;
}

//Display list
void Display(Node* head){
	if(head == NULL)
		printf("\nList is empty");
	else{
		while(head != NULL){
			if(head -> nextData == NULL)
				printf("%d -> NULL", head -> data);
			else
				printf("%d -> ", head -> data);

			head = head -> nextData;
		}
	}
}

//Merge list2(head 2) at the end of list1(head 1)
void Merge(Node* head1, Node* head2){
	while(head1 -> nextData != NULL)
		head1 = head1 -> nextData;

	head1 -> nextData = head2;
}

/**/
Node* Sort(Node* head){
	int swapped;
	do{
		Node* temp = head;		//To iterate from beginning
		swapped = 0;
		while(temp -> nextData != NULL){
			if(temp -> data > temp -> nextData -> data){	//Check for ascending order
				Swap(temp, temp -> nextData);				//Pass pointers to swap only data instead of swapping nodes.
				swapped = 1;
			}		
			temp = temp -> nextData;						//Move to next node
		}

	}while(swapped);
	return head;
}

/*Swap only data from node*/
void Swap(Node* a, Node* b){
	int temp = a -> data;
	a -> data = b -> data;
	b -> data = temp;
}