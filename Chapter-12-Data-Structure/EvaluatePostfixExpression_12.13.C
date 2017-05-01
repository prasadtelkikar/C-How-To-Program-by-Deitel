#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

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
char* Tokenization(char* expression);

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
//	char* expTokenPtr[] = Tokenization(expression);
	while(expression[i] != '\0'){
		char ch = expression[i];
		if(IsOperator(ch)){
			int x = top -> data;
			top = Pop(top);
			int y = top -> data;
			top = Pop(top);
			int result = Calculate(x, y, ch);
			top = Push(top, result);
		}
		else{
			int value = ch - '0';
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
