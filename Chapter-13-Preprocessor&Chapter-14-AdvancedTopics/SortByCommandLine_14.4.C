in#clude <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* How to run the program
 * Compilation: cmd :/> gcc -o outputName SortByCommandLine_14.4.c
 * Run : cmd :/> outputName -a/-d 5 3 4 2 9
 * -a : stands for Ascending order
 * -d : stands for Descending order
*/

void BubbleSort(int arr[], int size, bool isAscending);
void Swap(int* firstNumber, int* secondNumber);

int main(int argc, char* argv[]){
	int cmp = strcmp(argv[1], "-a");
	int sizeArr = argc -2;
	int arr[sizeArr];
	for (int i = 2, j = 0; i < argc; i++, j++)
		arr[j] = atoi(argv[i]);

	if(cmp == 0){
		printf("\n%s\n", "Ascending Order");
		BubbleSort(arr, sizeArr, true);	
	}
	else{
		printf("\n%s\n", "Descending Order");
		BubbleSort(arr, sizeArr, false);
	}

	for (int i = 0; i < sizeArr; ++i)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

//Bubble sort. Time complexity: O(n^2)
void BubbleSort(int arr[], int size, bool isAscending){
	
	for (int i = 0; i < size -1; ++i)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if(isAscending){
				if(arr[j] > arr[j + 1]){
					Swap(&arr[j], &arr[j + 1]);
				}
			}
			else{
				if(arr[j] < arr[j + 1]){
					Swap(&arr[j], &arr[j+1]);
				}
			}
		}
	}
}

//Swap two numbers
void Swap(int* firstNumber, int* secondNumber){
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}