/*Linear search*/
/*Time complexity of linear search is O(n). Linear search is rarely used practically
because other search alorithms such as binary search algorithm and hash table
allow significantly faster seaching comparision to linear search. Curtesy: GeeksForGeeks*/
#include<stdio.h>
#include<conio.h>
int LinearSearch(int arr[], int size, int x);

void main(){
	int i, element, x;
	int n, arr[10];
	clrscr();
	printf("\nEnter size of array (Less than 10):");
	scanf("%d",&n);
	if(n > 10)
		printf("\nWrong input");
	else{
		printf("\nEnter %d elements", n);
		for(i =0; i < n; i++)
			scanf("%d",&arr[i]);
		printf("\nPlease enter element to be seach");
		scanf("%d", &x);
		element = LinearSearch(arr, n, x);
		if(element == -1)
			printf("%d not found in array. Search result failed");
		else
			printf("%d element found at array index = %d ",x, element+1);
	}
	getch();
}

int LinearSearch(int arr[], int size, int x){
	int i;
	for(i =0; i < size; i++)
		if(arr[i] == x)
			return i;
		return -1;
}