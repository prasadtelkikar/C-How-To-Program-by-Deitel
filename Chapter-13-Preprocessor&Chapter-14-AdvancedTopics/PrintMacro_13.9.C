#include <stdio.h>
#include <conio.h>

#define SIZE 10
#define PRINT(X) printf("\n%d", X);

int main(){
	int arr[SIZE];

	printf("\nEnter %d elements: ", SIZE);	
	for (int i = 0; i < SIZE; ++i)
		scanf("%d", &arr[i]);

	for (int i = 0; i < SIZE; ++i)
	{
		PRINT(arr[i]);
	}
}