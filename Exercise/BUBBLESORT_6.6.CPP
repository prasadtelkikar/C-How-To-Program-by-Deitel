/*Bubble sort*/
#include<stdio.h>
#include<conio.h>

void BubbleSortRegular(int arr[], int size);  //Function prototype
void BubbleSortEfficient(int arr[], int size);
int Swap(int *firstNo, int *secondNo);

void main(){
	int choice, n, i;
	int arr[100];
	clrscr();

	printf("\nEnter your choice(1/2):");
	scanf("%d", &choice);

	printf("\nEnter length of array:");
	scanf("%d", &n);

	printf("\nEnter %d array elements:",n);
	for(i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}

	switch(choice){
		case 1:
			BubbleSortRegular(arr, n);
			break;
		case 2:
			BubbleSortEfficient(arr, n);
			break;
	}

	printf("\n\nSorted Array:\n");
	for(i = 0; i < n; i++){
		printf("\t%d",arr[i]);
	}
	getch();
}


/*Regular bubble sort, with O(n^2)*/
void BubbleSortRegular(int arr[], int size){
	int temp, i, j;

	for(i = 0; i < size; i++){
		printf("\nPasses: %d", i+1);
		for(j = 0; j < (size - i - 1); j++){
		       temp = Swap(&arr[j], &arr[j+1]);
		}
	}
}

/*Bubble sort with some what efficiency. Courtasy: GeeksforGeeks*/
void BubbleSortEfficient(int arr[], int size){
	 int temp, i, j, sorted;

	 for(i = 0; i < size; i++){
		sorted = 0;
		printf("\nPassed: %d", i+1);
		for(j =0; j < (size - i - 1); j++){
			temp = Swap(&arr[j], &arr[j+1]);
			if(temp == 1)
				sorted = 1;
		}
		if(sorted == 0)
			break;
	 }
}

/*Swapping function*/
int Swap(int *firstNo, int *secondNo){
	int temp;

	if(*firstNo > *secondNo){
		temp = *firstNo;
		*firstNo = *secondNo;
		*secondNo = temp;
		return 1;
	}
	return 0;
}