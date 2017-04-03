//While running program you might get errors related to _CRT_SECURE_NO_WARNINGS, go to properties of project -> c/c++ Processor -> add Processor defination "_CRT_SECURE_NO_WARNINGS"
#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include "StringBuiltInFunctions.h"

void CheckDigits();
void StringToNumber();
void SeperateStringWithLong();
void GetsAndPutChar();
void GetCharAndPuts();
void Reverse(char *str);
void StringCopy();
void StringConcatinate();
void StringManipulation();
void StringManipulation2();
void StringTokenizing();
void StringLength();

int main()
{

	CheckDigits();
	StringToNumber();
	SeperateStringWithLong();
	GetsAndPutChar();
	GetCharAndPuts();
	StringCopy();
	StringConcatinate();
	StringManipulation();
	StringManipulation2();
	StringTokenizing();
	StringLength();

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
	double d = StringToFloat("99.5");
	int i = StringToInt("77");
	long l = StringToLong("1000000");

	printf("\nThe string \" 99.5 \" converted to double is %0.2f", d);
	printf("\nThe string \"77 \" converted to int %d", i);
	printf("\nThe string \"1000000\" converted to long %ld", l);

}

//Seperate long integer and string from string: strtol (string to long), strtoul(string to unsigned long).
//Syntax: long = strtol(string, &remainder, numberSystem);
//Syntax long = strtoul(string, &remainder, numberSystem);
//strtod: string to double
void SeperateStringWithLong()
{
	long x;
	unsigned long unsignedX;
	char *stringUnsigned = "1234567abc", *remainderPtrUnsigned;
	char *string = "-1234567abc", *remainderPtr;
	x = StringToLong(string, &remainderPtr, 0);

	unsignedX = StringToUnsigned(stringUnsigned, &remainderPtrUnsigned, 0);

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

//Gets(): Read string.
//PutChar(): read character by character.
void GetsAndPutChar()
{
	char sentence[50];
	printf("\nEnter string to reverse: ");
	gets_s(sentence);
	
	printf("Reverse string: ");
	Reverse(sentence);
}

//GetChar() : To read string character by character.
//puts(): Print full string
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

//char *strcpy(char *s1, const char *s2): Copies the string s2 into the array s1. The value of s1 is returned.
//char *strncpy(char *s1, const char *s2, size_t n): Copies at most n characters of the string s2 into the array s1. The value of s1 is returned.
void StringCopy()
{
	char x[] = "Happy birthday to you";
	char y[25], z[25];

	printf("\nConstant string x: %s", x);
	printf("\nCopied string to y(strcpy): %s", StringCopy(y, x));
	
	printf("\nCopied string to z(strncpy): %s", StrCopyWithLimit(z, x, 14));
}

//char *strcat(char *s1, const char *s2): Append the string s2 to the array s1. The first character of s2 overwrites the terminating NULL character of s1.The value of s1 is returned.
//char *strncat(char *s1, const char *s2, size_t n): Append at most n characters of string s2 to array s1. The first character of s2 overwrites the terminating NULL character of s1. The value of s1 is returned.
void StringConcatinate()
{
	char s1[60] = "Happy ";
	char s2[] = "birthday to you";
	char s3[60] = "";

	printf("\ns1 = %s\ts2 = %s", s1, s2);
	printf("\nstrcat(s1, s2) = %s", StringConcatinate(s1, s2));
	printf("\nstrncat(s1, s2) = %s", StringConcatinateWithLimit(s1, s2, 14));

}

//char *strchr(const char *s, char c): Locate the FIRST occurrence of character c in string s. If c is found , a pointer to c is returned. Otherwise a Null pointer is returned
//char *strrchr(const char *s, int c): Locate the LAST occurrence of c in string s. If c is found, a  pointer to c is returned. Otherwise a Null pointer is returned.
//size_t strcspn(const char *s1, const char *s2): Determines and returns the LENGHTH of the initial segment of string s1 consisting of character of characters NOT contained in string s2
//size_t strspn(const char *s1, const char *s2): Determine and return the length of the initial segment of string s1 consisting only of character contained in string s2.
void StringManipulation()
{
	char *sentence = "Welcome to string world";
	char chr = 's';
	const char *cspn = "o";
	int cspnInt = 'w';
	const char *spn = "emocwel";
	printf("\nInputs:\n\t%s\n\t%c\n\t%s\n\t%s\n", sentence, chr, cspn, spn);
	
	if (FindCharFromString(sentence, chr) != NULL)
		printf("\n%c was found in string: %s", chr, sentence);
	else
		printf("\n%c was not found in string: %s", chr, sentence);

	int size = GetExcludedLengthOfString(sentence, cspn);
	
	printf("\nLength of sentence containing no characters from string cspn = %d", size);
	size = GetLengthOfStringFromLetter(sentence, spn);

	printf("\nLength of sentence containing only characters from string spn = %d", size);
	printf("\nLast occurence of latter starts with o is = %s", strrchr(sentence, cspnInt));
}

void StringLength()
{
	char string[] = "C-How-To-Program";
	printf("\nLength of string \"%s\" is = %d", string, GetLength(string));
}

//char *strpbrk(const char *s1, const char *s2): Locate first occurrence in string s1 of any character in string s2. If a character from string s2 is found, a pointer to the character
//in string s1 is returned. Otherwise a NULL pointer is returned.
//char *strstr(const char *s1, const char *s2): Locate the first occurenece int string s1 of string s2. If the string is found, a pointer to the string in s1 is returned.Otherwise a NULL pointer is returned
void StringManipulation2()
{
	char *string1 = "This is a test";
	char *string2 = "beware";
	char *string3 = "is";
	
	printf("\nInputs:\n\t%s\n\t%s\n\t%s", string1, string2, string3);

	printf("\n%s\"%s\"\n'%c'%s\n\"%s\"\n", "Of the characters in", string2,
		*strpbrk(string1, string2), " is the first character to appear in", string1);
	printf("\nThe remainder of first string with the first occurrence of string2: %s", strstr(string1, string3));

}
//char * strtok(char *s1, const char *s2): A sequence of calls to strtok breaks string s1 into "tokens" - logical pieces such as words in a line of text-seperated by characters contained in string s2.
//First cell contains s1 as the first argument, and subsequent calls to continue tokenizing the same string contain NULL as a first argument. A pointer to the current token is returned by each call.
//If there are no more tokens when the function is called. NULL is returned.
void StringTokenizing()
{
	char string[] = "This is a sentence with 7 tokens";
	char *tokenptr;

	printf("\n%s\n%s\n\n%s\n", "The string to be tokenized is:", string, "The tokens are:");
	tokenptr = strtok(string, " ");

	while(tokenptr!=NULL)
	{
		printf("%s\n", tokenptr);
		tokenptr = strtok(NULL, " ");
	}
}

