// Inline functions: it replaces a call of that function with its body, avoiding the overhead of a function call
#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <cstdlib>
#include <cstring>

//atof(char *) used to convert string to float
double StringToFloat(char *str)
{
	return atof(str);
}

//atoi(char *) used to convert string to int.
int StringToInt(char *str)
{
	return atoi(str);
}
//atol(char *) used to convert string to long.
long StringToLong(char *str)
{
	return atol(str);
}
//strtol:Seperate out string with remainder string.base can be 0 for decimal, 2 for binary, 8 for Octal
long StringToLong(char *str, char **remainderString, int base)
{
	return strtol(str, remainderString, base);
}

//strtoul: return string with unsigned long value.e.g str= 12345abc rem = abc then return 12345
unsigned long StringToUnsigned(char *str, char **remainderString, int base)
{
	return strtoul(str, remainderString, base);
}

//strcpy: copy source string into destination string.
char* StringCopy(char *destinationString, char* sourceString)
{
	return strcpy(destinationString, sourceString);
}

//strncpy: copy limited source string to destination string.
char* StrCopyWithLimit(char *destinationString, char* sourceString, int limit)
{
	strncpy(destinationString, sourceString, limit);
	destinationString[limit] = '\0';
	return destinationString;
}

//concatinate first string with second. Overwrite '\0' of first string to starting of second string.
char* StringConcatinate(char* firstString, char* secondString)
{
	return strcat(firstString, secondString);
}

//Concatinate first string with second with specified size.
char* StringConcatinateWithLimit(char* firstString, char* secondString, int limit)
{
	return strncat(firstString, secondString, limit);
}

//strchr: find character ch in the string. Here finding character should be of int data type
char* FindCharFromString(char *str, int ch)
{
	return strchr(str, ch);
}
//strrchr: find character ch in the reverse string . Here finding character should be of int data type
char* FindCharFromReverseString(char *str, int ch)
{
	return strrchr(str, ch);
}

//strcspn: Return length of main string by excluding second string.
int GetExcludedLengthOfString(char *mainString, const char* excludedString)
{
	return strcspn(mainString, excludedString);
}

int GetLengthOfStringFromLetter(char *mainString, const char* string)
{
	return strspn(mainString, string);
}

//Get length of string
int GetLength(char* str)
{
	return strlen(str);
}