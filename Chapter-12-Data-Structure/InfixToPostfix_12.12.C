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
void InfixToPostfix(Node* top, char* expression, char result[SIZE]);
bool HasHigherPrecedence(char stackOperator, char currentOperator);
bool IsOperator(char ch);

int main(){
	char expression[SIZE];
	char result[SIZE];
	Node* top = NULL;
	printf("\nEnter expression: ");
	gets(expression);
	InfixToPostfix(top, expression, result);
	printf("\nPostfix expression: %s", result);
	return 0;
}

/*Infix to Postfix conversion
Parameters: Node* top = Stack top; char* expression = Input expression; char result[] : Output expression
*/
void InfixToPostfix(Node* top, char* expression, char result[]){
	int i = 0;
	int postfixIndex = 0;

	while(expression[i] != '\0'){
		if(IsOperator(expression[i])){
			while(top != NULL && HasHigherPrecedence(top -> data , expression[i]) && top -> data != '('){
				char ch = top -> data;
				result[postfixIndex] = ch;
				top = Pop(top);
				postfixIndex++;
			}
			top = Push(top, expression[i]);
			
			//To remove '(' and ')' from stack.
			if(top -> data == ')'){
				top = Pop(Pop(top));
			}
		}
		else if(expression[i] == '(')
			top = Push(top, expression[i]);
		else{
			char ch = expression[i];
			result[postfixIndex] = ch;
			postfixIndex++;	
		}
		i++;
	}

	while(top != NULL){
		char ch = top -> data;
		result[postfixIndex] = ch;
		top = Pop(top);
		postfixIndex++;
	}
}

/* Push character into stack */
Node* Push(Node* top, char ch){
	Node* temp = (Node*) malloc(sizeof(Node));
	temp -> data = ch;
	temp -> nextNode = top;

	top = temp;

	return top;
}

/* Pop top letter from stack */
Node* Pop(Node* top){
	Node* temp = top;
	top = top -> nextNode;
	free(temp);	
	return top;
}

/* Check higher precedence operator */
bool HasHigherPrecedence(char stackOperator, char currentOperator){
	if((stackOperator == '*' || stackOperator == '/' || stackOperator == '%') && (currentOperator == '+' || currentOperator == '-'))
		 return true;
	if((currentOperator == '*' || currentOperator == '/' || currentOperator == '%') && (stackOperator == '+' || stackOperator == '-'))
		return false;

	return true;
}

/* Check for operator */
bool IsOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')')
		return true;

	return false;
}