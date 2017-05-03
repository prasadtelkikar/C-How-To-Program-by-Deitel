#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

struct Node{
	char data;
	Node* nextNode;
};

Node* CreateList(Node* top, char ch);
void Display(Node* top);
Node* Push(Node* top, char ch);
Node* Pop(Node* top);
void InfixToPostfix(Node* top, char* expression);
bool HasHigherPrecedence(char stackOperator, char currentOperator);
bool IsOperator(char ch);

int main(){
	char expression[SIZE];
	char* result;
	Node* top = NULL;
	printf("\nEnter expression: ");
	gets(expression);
	InfixToPostfix(top, expression);
	
	return 0;
}

void InfixToPostfix(Node* top, char* expression){
	int i = 0;
	char result[SIZE] = "";

	while(expression[i] != '\0'){
		if(!IsOperator(expression[i]))
			strcat(result, &expression[i]);
		else if(IsOperator(expression[i])){
			while(top != NULL && HasHigherPrecedence(top -> data, expression[i])){
				strcat(result, &(top -> data));
				top = Pop(top);
			}
			top = Push(top, expression[i]);
		}
	}
	while(top != NULL){
		strcat(result, &(top -> data));
		top = top -> nextNode;
	}
	printf("\nPostfix expression: %s", result);
}

Node* Push(Node* top, char ch){
	Node* temp = (Node*) malloc(sizeof(Node));
	temp -> data = ch;
	temp -> nextNode = top;

	top = temp;

	return top;
}

Node* Pop(Node* top){
	printf("\nPoped Element: %c", top -> data);
	Node* temp = top;
	top = top -> nextNode;
	free(temp);	
	return top;
}

bool HasHigherPrecedence(char stackOperator, char currentOperator){
	if((stackOperator == '*' || stackOperator == '/' || stackOperator == '%') && (currentOperator == '+' || currentOperator == '-'))
		 return true;
	if((currentOperator == '*' || currentOperator == '/' || currentOperator == '%') && (stackOperator == '+' || stackOperator == '-'))
		return false;

	return true;
}

bool IsOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return true;

	return false;
}