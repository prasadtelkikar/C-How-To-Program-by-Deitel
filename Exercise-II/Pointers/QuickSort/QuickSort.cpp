/*Implementation of quick sort
 * All elements to the right of the pivot are smaller than pivot
 * All elements to the left of the pivot are greater than pivot
*/
#include<stdio.h>
#include <conio.h>
void Swap(int *firstNumber, int *secondNumber);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
	int i;
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	quickSort(arr, 0, n - 1);

	printf("Sorted array: \n");
	for(i = 0; i<n;i++)
	{
		printf("\t%d", arr[i]);
	}
	_getch();
	return 0;
}

void Swap(int *firstNumber, int *secondNumber)
{
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}

int partition(int arr[], int low, int high)
{
	//Wall
	int i = (low - 1);
	//consider last element as pivot
	int j, pivot = high;

	for (j = low; j < high; j++)
	{
		//if pivot elment is greater than arr[j] then swap
		// This swapping technique seperate smaller element tha pivot to the left of pivot
		//greater elements to the right of the pivot
		if (arr[pivot] >= arr[j])
		{
			i++;
			Swap(&arr[j], &arr[i]);
		}
	}

	//This swap function swap pivot to its original position
	Swap(&arr[i + 1], &arr[high]);

	//return index of pivot element
	return i + 1;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//Partition of an array. 
		int pi = partition(arr, low, high);

		//Apply quick sort for left most array
		quickSort(arr, low, pi - 1);
		
		//Apply quick sort for right most array
		quickSort(arr, pi + 1, high);
	}
}
