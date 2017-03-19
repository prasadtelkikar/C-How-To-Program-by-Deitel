// LinearSearch.cpp : Linear search non recursive and recursive. Time complexity: Worst case: O(n)
//

#include <stdio.h>
#include <conio.h>

void LinearSearchWithRecursion(int arr[], int n, int key, int index);
int LinearSearchWithoutRecursion(int arr[], int n, int key);
int main()
{
	int choice,  n, i;
	int arr[50], exitKey;
	int keyIndex = 0, searchValue = 0;
	printf("\nEnter number of elements: ");
	scanf_s("%d", &n);
	
	printf("\nEnter elements: ");
	for (i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	printf("\n*****************Menu driven program*************\n");
	do
	{
		printf("\n1. Linear search without recursion");
		printf("\n2. Linear search with recursion");
		printf("\n Enter your choice: ");
		scanf_s("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("\nEnter key to find in an array: ");
			scanf_s("%d", &searchValue);
			keyIndex = LinearSearchWithoutRecursion(arr, n, searchValue);
			if (keyIndex != -1)
				printf("%d value found at location = %d", searchValue, keyIndex + 1);
			else
				printf("%d value is not available in an array", searchValue);
			break;
		case 2:
			printf("\nEnter key to find in an array: ");
			scanf_s("%d", &searchValue);
			LinearSearchWithRecursion(arr, n, searchValue, 0);
			break;
		default:
			break;
		}
		printf("\n\nPress key to continue(0 to exit): ");
		scanf_s("%d", &exitKey);
	} while (exitKey != 0);
}

int LinearSearchWithoutRecursion(int arr[], int n, int key)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

void LinearSearchWithRecursion(int arr[], int n, int key, int index)
{
	int i;
	if(arr[index] == key)
	{
		printf("%d found at location %d", key, index + 1);
		return;
	}
	if(index + 1 == n)
	{
		printf("%d is not found in an array", key);
		return;
	}
	LinearSearchWithRecursion(arr, n, key, index + 1);
}