// pointerOperators.cpp : From examples: use of & and * pointer operator
#include<stdio.h>
#include <conio.h>

int main()
{
	int a, *aptr;	//a is int veriabal and aptr is pointer to the integer.
	a = 10;
	aptr = &a;		//aptr set to address of a
	printf("\n*******************use of & and * pointer operator*******************\n");

	printf("\n\tAddress of a = %p", &a);
	printf("\n\tThe value of aPtr = %p", aptr);
	printf("\n\tThe value of a = %d", a);
	printf("\n\tThe value of *aptr = %d", *aptr);

	_getch();
	return 0;
}

