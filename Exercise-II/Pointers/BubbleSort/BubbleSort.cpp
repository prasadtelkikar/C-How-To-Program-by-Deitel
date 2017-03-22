// BubbleSort.cpp : Bubble sort using pointer
//

#include <stdio.h>
#include <conio.h>
void Swap(int *firstNumber, int *secondNumber);

int main()
{
	int size, arr[30], i, j, isSwapped;
	
	printf("\nEnter size of array: ");
	scanf_s("%d", &size);
	printf("\nEnter %d numbers: ", size);
	
	for (i = 0; i < size; i++)
		scanf_s("%d", &arr[i]);

	for(i = 0; i < size; i++)
	{
		isSwapped = 0;
		for(j = 0; j < size - i - 1; j++)
		{
			isSwapped = 1;
			Swap(&arr[j], &arr[j + 1]);
		}
		if (isSwapped == 0)
			break;
		printf("\nPasses = %d", i + 1);
	}

	printf("\nSorted Array:\n");
	for (i = 0; i < size; i++)
		printf("%3d", arr[i]);

	_getch();
    return 0;
}

void Swap(int *firstNumber, int *secondNumber)
{
	int temp;
	if(*firstNumber > *secondNumber)
	{
		temp = *firstNumber;
		*firstNumber = *secondNumber;
		*secondNumber = temp;
	}
}
