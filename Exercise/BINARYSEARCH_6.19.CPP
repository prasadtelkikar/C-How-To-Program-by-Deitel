/*Binary search:Search a sorted array by repeatedly dividing the interval in half.
Begin with an converting the whole array. If the value of the search key is less
than the item in the middle of the interval, narrow the interval to the lower half
Otherwise narrow it to the upper half. Repeatedly check until the value is found
or the interval is empty.Time complexity is O(Logn)*/
#include<stdio.h>
#include<conio.h>
void BubbleSort(int arr[], int size);
int BinarySearch(int arr[], int left, int right, int k, int size);
void PrintHeader(int size);
void PrintRow(int arr[], int left, int mid, int right, int size);
void main(){
	int n, i, k, searchedIndex;
	int arr[50];
	clrscr();

	printf("\nEnter size of array(less than 50):");
	scanf("%d",&n);
	printf("\nEnter values of an array:");

	for(i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	BubbleSort(arr, n);

	printf("Enter element to be search:");
	scanf("%d",&k);
	PrintHeader(n);
	searchedIndex = BinarySearch(arr, 0, n-1, k, n);
	printf("%d found at location = %d",k, searchedIndex);
	getch();
}
void BubbleSort(int arr[], int size){
	int i, j, temp, isSorted;
	for(i = 0; i < size; i++)
	{
		isSorted = 1;
		for(j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				isSorted = 0;
			}
		}
		if(isSorted == 1)
			break;
	}
}

int BinarySearch(int arr[], int left, int right, int k, int n){
	int mid = 0;
	if(right >= left){
		mid = left + (right - left)/2;

		PrintRow(arr, left, mid, right, n);
		//n(Array size) is not required for binary search. Passed to print array.

		if(arr[mid] > k)
			return BinarySearch(arr, left, mid - 1, k, n);
		else if(arr[mid] < k)
			return BinarySearch(arr, mid + 1, right, k, n);
		else
			return mid;

	}
	return -1; 	/*Search key not found*/
}
void PrintHeader(int size){
	int i;
	printf("\nSubscripts:\n");
	for(i = 0; i < size; i++)
		printf("%3d", i);

	printf("\n");
	for(i = 0; i < 4*size; i++)
		printf("-");
	printf("\n");
}

void PrintRow(int arr[], int left, int mid, int right, int size){
	int i;
	for(i = 0; i < size; i++){
		if(i < left || i > right)
			printf("  ");
		else if(i == mid)
			printf("%3d*",arr[i]); /*Mark middle value*/
		else
			printf("%3d",arr[i]);
		}
	printf("\n");
}