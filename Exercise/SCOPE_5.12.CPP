/*Solved example: Scoping example*/
#include<stdio.h>
#include<conio.h>

void a();  /*Function prototype*/
void b();
void c();

int x = 1;	/*Global variable*/

void main(){
	int x = 5;	/*Local variable*/
	clrscr();

	printf("\nLocal variable x in outer scope of main: %d", x);
	{
	 int x = 7;
	 printf("\nLocal variable x in inner scope of main: %d", x);
	}
	printf("\nLocal variable x in outer scope of main: %d\n", x);
	a();	/* a has automatic local x */
	b();	/* b has static x */
	c();
	printf("*********************Calling Second Time*********************");
	a();
	b();
	c();
	getch();
}


void a(){
	int x = 25;
	printf("local x in a is %d after entering a\n", x);
	++x;
	printf("local x in a is %d before exiting a\n", x);
}

void b(){
	static int x = 50;
	printf("local x in b is %d after entering b\n", x);
	++x;
	printf("local x in b is %d before exiting b\n", x);
}
void c(){
	printf("Global x in c is %d after entering c\n", x);
	x *=10;
	printf("Global x in cis %d before exiting b\n", x);
}