// Strings.cpp : String functions
//

#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <cstdlib>

void CheckDigits();
void StringToNumber();
void StringToLong();
void GetsAndPutChar();
void GetCharAndPuts();
void Reverse(char *str);

int main()
{
	CheckDigits();
	StringToNumber();
	StringToLong();
	GetsAndPutChar();
	GetCharAndPuts();

	_getch();
    return 0;
}

//Implementation of isdigit, isalpha, isalnum and isxdigit
void CheckDigits()
{
	printf("\nAccording to isdigit: ");
	printf("\n%s", isdigit('8') ? "8 is a digit" : "8 is not a digit");
	printf("\n%s", isdigit('#') ? "# is a digit" : "# is not a digit");

	printf("\nAccording to isalpha: ");
	printf("\n%s", isalpha('A') ? "A is a letter" : "A is not a letter");
	printf("\n%s", isalpha('#') ? "# is a letter" : "# is not a letter");

	printf("\nAccording to isalnum: ");
	printf("\n%s", isalnum('A') ? "A is a letter or number" : "A is not a letter or number");
	printf("\n%s", isalnum('8') ? "8 is a letter or number" : "8 is not a letter or number");
	printf("\n%s", isalnum('#') ? "# is a letter or number" : "# is not a letter or number");

	printf("\nAccording to isxdigit: ");
	printf("\n%s", isxdigit('A') ? "A is a hexadecimal" : "A is not a hexadecimal");
	printf("\n%s", isxdigit('8') ? "8 is a hexadecimal" : "8 is not a hexadecimal");
	printf("\n%s", isxdigit('#') ? "# is a hexadecimal" : "# is not a hexadecimal");

}

//Implementation of atof, atoi, atol
void StringToNumber()
{
	double d = atof("99.5");
	int i = atoi("77");
	long l = atol("1000000");

	printf("\nThe string \" 99.5 \" converted to double is %0.2f", d);
	printf("\nThe string \"77 \" converted to int %d", i);
	printf("\nThe string \"1000000\" converted to long %ld", l);

}

//Seperate long integer and string from string: strtol (string to long), strtoul(string to unsigned long).
//Syntax: long = strtol(string, &remainder, numberSystem);
//Syntax long = strtoul(string, &remainder, numberSystem);
//strtod: string to double
void StringToLong()
{
	long x;
	unsigned long unsignedX;
	char *stringUnsigned = "1234567abc", *remainderPtrUnsigned;
	char *string = "-1234567abc", *remainderPtr;
	x = strtol(string, &remainderPtr, 0); //0 for decimal, 8 for octal, 16 for hex
	unsignedX = strtoul(stringUnsigned, &remainderPtrUnsigned, 0); //0 for decimal, 8 for octal, 16 for hex

	printf("\nAccording to strtol(String to long)");
	printf("\nString with numbers =%s\tLong values = %ld \t Remaining string = %s", string, x, remainderPtr);
	
	printf("\nAccording to strtoul(String to unsigned long)");
	printf("\nString with unsigned numbers =%s\tLong values = %ld \t Remaining string = %s", stringUnsigned, unsignedX, remainderPtrUnsigned);
}

//Recursive function to read string. Use of gets_s and putchar function
void Reverse(char *str)
{
	if (str[0] == '\0')
		return;
	else
		Reverse(&str[1]);
	putchar(str[0]);
}

void GetsAndPutChar()
{
	char sentence[50];
	printf("\nEnter string to reverse: ");
	gets_s(sentence);
	
	printf("Reverse string: ");
	Reverse(sentence);
}

void GetCharAndPuts()
{
	char c, sentence[80];
	int i = 0;
	printf("\nEnter a line of text:");
	while ((c = getchar()) != '\n')
		sentence[i++] = c;

	sentence[i] = '\0';

	puts("Line entered was:");
	puts(sentence);
		
}