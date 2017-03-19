// Palindromes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include<conio.h>
#include <string.h>

void GetReverseWithoutStrFunction(char originalStr[], char copyOfOriginalStr[]);
void GetReverseWithStrFunction(char originalStr[], char copyOfOriginalStr[]);
void RecursivePalindrome(char originalStr[], int index);

int main()
{
	char strValue[30], revstrValue[30], s[10];
	int choice, exitKey = -1;
	printf("\n******************Menu driven program******************");
	printf("\nCheck palindrome");
	do
	{	
		printf("\n1. Revese string whithout string functions (whithout strrev)");
		printf("\n2. Reverse string with string function (with strrev)");
		printf("\n3. Reverse string using recursion");
		printf("\nEnter your choice: ");
		scanf_s("%d", &choice);
		gets_s(s);

		switch(choice)
		{
		case 1:
			printf("\nEnter string: ");
			gets_s(revstrValue);
			strcpy_s(strValue, revstrValue);
			GetReverseWithoutStrFunction(revstrValue, strValue);
			break;
		case 2:
			printf("\nEnter string: ");
			gets_s(revstrValue);
			strcpy_s(strValue, revstrValue);
			GetReverseWithStrFunction(revstrValue, strValue);
			break;
		case 3:
			printf("\nEnter String: ");
			gets_s(revstrValue);
			RecursivePalindrome(revstrValue, 0);
			break;
		default:
			printf("\nYou entered wrong input");
			break;
		}
		printf("\n\nDo you want to continue(0 to exit)");
		scanf_s("%d", &exitKey);
	} while (exitKey != 0);

	_getch();
	return 0;
}

void GetReverseWithoutStrFunction(char originalStr[], char copyOfOriginalStr[])
{
	int i = 0, len;
	len = strlen(originalStr) - 1;
	char temp;
	while(i < len)
	{
		temp = originalStr[i];
		originalStr[i] = originalStr[len];
		originalStr[len] = temp;
		i++;
		len--;
	}

	if (strcmp(originalStr, copyOfOriginalStr) == 0)
		printf("string is palindrome");
	else
		printf("string is not palindrome");
}

void GetReverseWithStrFunction(char originalStr[], char copyOfOriginalStr[])
{
	if (strcmp(copyOfOriginalStr, _strrev(originalStr)) == 0)
		printf("String is palindrome");
	else
		printf("string is not palindrome");
}

void RecursivePalindrome(char str[] , int index)
{
	int len = strlen(str) - (index + 1);

	if(str[index] == str[len])
	{
		if(index + 1 == len || index == len)
		{
			printf("\nString is palindrome");
			return;
		}
		RecursivePalindrome(str, index + 1);
	}
	else
	{
		printf("\nString is not palindrome");
	}
}