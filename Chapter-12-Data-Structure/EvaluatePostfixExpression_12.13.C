#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/*Note: Add space in between 2 digits or operators. 
Space is considered as a seperator in an equation*/
struct Node{
	int data;
	struct Node* nextNode;
};

int EvaluatePostfixExpression(char *expr);
int Calculate(int op1, int op2, char oper);
Node* Push(Node* top, int value);
Node* Pop(Node* top);
bool IsOperator(char ch);
void Display(Node* top);
void Tokenization(char* expression, char** tokenPtr);

int main(){
	int index;
	char expression[50];
	printf("\nEnter postfix expression: ");
	gets(expression);
	int result = EvaluatePostfixExpression(expression);
	printf("\n");
	printf("Equation result: %d", result);
	printf("\n");
	return 0;		
}

/* Evaluate Postfix expression */
int EvaluatePostfixExpression(char *expression){
	int i = 0;
	Node* top = NULL;
	char* expTokens[10]={NULL};
	Tokenization(expression, expTokens);
	while(expTokens[i] != NULL){
		if(IsOperator(*expTokens[i])){
			int x = top -> data;
			top = Pop(top);
			int y = top -> data;
			top = Pop(top);
			//printf("%d %c %d\n", x, *expTokens[i], y);
			int result = Calculate(x, y, *expTokens[i]);
			top = Push(top, result);
		}
		else{
			int value = atoi(expTokens[i]);
			//printf("Pushed values = %d\n", value);
			top = Push(top, value);
		}
		i++;
	}
	return top -> data;
}

/*Push node at the top of the list. Principle: FILO*/
Node* Push(Node* top, int value){
	Node* temp = (Node*) malloc(sizeof(Node));
	temp -> data = value;
	temp -> nextNode = NULL;
	if(top == NULL)
		top = temp;
	else{
		temp -> nextNode = top;
		top = temp;
	}
	return top;
}

/* Pop top node and replace head index to current top*/
Node* Pop(Node* top){
	top = top -> nextNode;
	return top;
}

/* Check whether character ch is an operator*/
bool IsOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return true;
	else
		return false;
}

/* Opearations on the basis of ch (operator)*/
int Calculate(int op1, int op2, char ch){
	int result = 0;
	switch(ch){
		case '+':
			result = op1 + op2;
		break;
		case '-':
			result = op1 - op2;
		break;
		case '*':
			result = op1 * op2;
		break;
		case '/':
		if(op1 > op2)
			result = op1 / op2;
		else
			result = op2 / op1;
		break;
		case '%':
		if(op1 > op2)
			result = op1 % op2;
		else
			result = op2 % op1;
		break;
	}
	return result;
}

/* Print Stack*/
void Display(Node* top){
	if(top == NULL)
		printf("\nStack is empty");
	else{
		while(top != NULL){
			printf("%d\n", top -> data);
			top = top -> nextNode;
		}
	}
}

/* Create token of string using space */
void Tokenization(char* expression, char** tokenPtr){

	int index = 0; 
	char* token = strtok(expression, " ");
	while(token != NULL){
		tokenPtr[index] = token;
		token = strtok(NULL, " ");
		index++;
	}
}