/*From Exercise: 6.17 Sum of array elements using recursion*/
#include<stdio.h>
#include<conio.h>
int SumRecursive(int arr[], int size);
void main(){
	int i, n,total;
	int arr[20]={0};
	clrscr();

	printf("\nEnter size of Array:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i = 0; i < n;i++)
		scanf("%d",&arr[i]);
	total = SumRecursive(arr, n);
	printf("\nTotal of array elements= %d",total);
	getch();
}

int SumRecursive(int arr[], int size){
	if(size == 1)
		return arr[0];
	else
	      return arr[size - 1] + SumRecursive(arr, size - 1);
}