#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void GetDate(char date[], char day[], char month[], char year[]);
void PrintDate(char day[], char month[], char year[], char result[]);

int main(){
	char day[5], month[5], year[7];
	char resultDate[50];

	char* datePtr;
	char date[50];
	printf("\nEnter date in format (MM/DD/YY): ");
	gets(date);
	int index = 0;
	GetDate(date, day, month, year);
	PrintDate(day, month, year, resultDate);
	if(resultDate == NULL)
		printf("%s\n", "Wrong input");
	else
		printf("%s\n", resultDate);
	return 0;
}

//Get day, month and year from date string.
void GetDate(char date[], char day[], char month[], char year[]){
	int length = strlen(date);
	int indexOfMonth = strchr(date, '/') - date;
	int indexOfDay = strchr(date+indexOfMonth+1, '/') - date;
	int indexOfYear = length - indexOfDay - 1;

	strncpy(month, date, indexOfMonth);
	strncpy(day, date + indexOfMonth + 1, indexOfDay - indexOfMonth - 1);
	strncpy(year, date+indexOfDay + 1, indexOfYear +1);
}

//Print date in proper format
void PrintDate(char day[], char month[], char year[], char result[]){
	const char * months[12] = {"January", "February", "March", "April",
							   "May", "June", "July", "August", "September",
							   "October", "November", "December"};
	int dayInt = atoi(day);
	int monthInt = atoi(month);
	int yearInt = atoi(year);

	int lenghtYr = strlen(year);
	if(lenghtYr == 2){
		if(yearInt < 50)
			yearInt+= 2000;
		else
			yearInt += 1900;
	}
	if(dayInt > 31 || monthInt > 12 || lenghtYr > 4)
		printf("%s\n", "Wrong input");
	else
	{
		strcat(result, day);
		strcat(result, ", ");
		strcat(result, months[monthInt - 1]);
		itoa(yearInt, year, 10);
		strcat(result, " ");
		strcat(result, year);
	}
}