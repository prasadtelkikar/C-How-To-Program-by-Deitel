/*From Exercise:6.15*/
#include<stdio.h>
#include<conio.h>
int isPresent(int k, int arr[],int start, int size);
void main(){
	int i, n, k;
	int arr[20];
	int available = 0;
	clrscr();
	printf("\nEnter size of array(Less than 20):");
	scanf("%d",&n);

	printf("\nPlease Enter elements:");
	for(i = 0;i < n;i++)
		scanf("%d",&arr[i]);
	for(i = 0; i < n;i++){
		available = isPresent(arr[i], arr, i+1, n);
		if(available == 1)
			printf("\n%d",arr[i]);
	}
	getch();
}

int isPresent(int k, int arr[], int start, int size){
	int i;
	for(i = start; i < size; i++){
		if(arr[i] == k)
			return 0;
	}
	return 1;
}