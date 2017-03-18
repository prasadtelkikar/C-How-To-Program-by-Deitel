// SieveOfEratosthenes.cpp : Finding prime number using "Sieve of Eratosthenes" algorithm. Time complexity = O(n loglog n).
// cons: Consume lot of space.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define SIZE 1000
int main()
{
	int arr[SIZE];
	int i, j, k, limit;
	for(i = 0; i < SIZE; i++)
	{
		if (i == 0)
			arr[i] = -1;
		else
			arr[i] = 1;
	}
	limit = sqrt(SIZE);
	for(i = 2; i < limit; i++)
	{
		if(arr[i] == 1)
		{
			for(j = (i*i), k = 0; j < SIZE;k++, j = ((i*i) + (k*i)))
			{
				arr[j] = 0;
			}
		}
	}
	printf("\nPrime numbers:\n");
	for(i = 0; i < SIZE; i++)
	{
		if (arr[i] == 1)
			printf("\t%d", i);
	}
	_getch();
	return 0;
}

