// pointerOperators.cpp : From examples: use of & and * pointer operator
//Call by value and call by reference
//Converting lowercase letters to uppercase letters

#include<stdio.h>
#include <conio.h>
void CallByValue(int a, int b);
void CallByReference(int *a, int *b);
void ConvertToUppercase(char *str);

int main()
{
	int a, b, *aptr, *bptr;	//a is int veriabal and aptr is pointer to the integer.
	a = 10;
	b = 20;
	aptr = &a;		//aptr set to address of a
	bptr = &b;

	printf("\n*******************use of & and * pointer operator*******************\n");

	printf("\n\tAddress of a = %p", &a);
	printf("\n\tThe value of aPtr = %p", aptr);
	printf("\n\tThe value of a = %d", a);
	printf("\n\tThe value of *aptr = %d", *aptr);
	
	printf("\n\nValues before callByValue function\n\tA = %d, \tB = %d", a, b);
	CallByValue(a, b);
	printf("\nValues after callByValue function\n\tA = %d, \tB = %d", a, b);
	printf("\n---------------------------------------------------------------------");
	printf("\n\nValues before callByReference function\n\tA = %d, \tB = %d", a, b);
	CallByReference(&a, &b);
	printf("\nValues after callByReference function\n\tA = %d, \tB = %d", a, b);

	printf("\n---------------------------------------------------------------------");
	char string[] = "characters";
	printf("\nThe string before conversion is: %s", string);
	ConvertToUppercase(string);
	printf("\nThe string after conversion is: %s", string);

	_getch();
	return 0;
}

void CallByValue(int a, int b)
{
	a += 10;
	b += 10;
	printf("\nValues in callByValue function\n\tA = %d, \tB = %d", a, b);
}

void CallByReference(int *a, int *b)
{
	*a += 10;
	*b += 10;
	printf("\nValues in callByReference function\n\tA = %d, \tB = %d", *a, *b);
}

void ConvertToUppercase(char *str)
{
	while(*str !='\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;					/* Converting to ASCII upper case letters */

		++str;				/* Increment s to point to the next character */
	}
}