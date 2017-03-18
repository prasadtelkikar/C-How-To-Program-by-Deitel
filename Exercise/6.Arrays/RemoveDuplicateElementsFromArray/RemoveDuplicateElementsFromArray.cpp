// RemoveDuplicateElementsFromArray.cpp : Program to generate 20 random numbers and store all non duplicate values.

#include <stdio.h>
#include<conio.h>
#include <time.h>
#include <cstdlib>

int main()
{
	int size = 20, count = 0, i, j, k;
	int arr[20] = { 0 };
	srand(time(NULL));
	while(count < size)
	{
		arr[count] = rand();
		printf("\t%d", arr[count]);
		count++;
	}

	for(i = 0; i < size; i++)
	{
		for(j = i+1; j < size;)
		{
			if(arr[i] == arr[j])
			{
				for (k = j; k < size; k++)
				{
					arr[k] = arr[k + 1];
				}
				size--;
			}
			else
				j++;
		}
	}
	for (i = 0; i < size; i++)
		printf("\t%d", arr[i]);

	_getch();
	return 0;
}
