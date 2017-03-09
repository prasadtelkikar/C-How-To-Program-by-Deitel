/*Passing array and individual array element to the function*/
#include<stdio.h>
#include<conio.h>
#define SIZE 3

void modifyArray(int arr[], int size);
void modifyArrayElement(int arrayElement);

void main(){
	int arr[SIZE] = {1, 2, 3};
	int i;
	clrscr();
	printf("Passing array to a function\n");
	printf("\nArray element before passing to function\n");
	for(i = 0; i < SIZE; i++)
		printf("\t%d", arr[i]);
	modifyArray(arr, SIZE);	//Passing array means passing address of first element of array.
	printf("\nArray elements after modification\n");

	for(i = 0; i < SIZE; i++)
		printf("\t%d",arr[i]);
	printf("\n-----------------------------------------------\n");
	printf("passing array element to function\n\n");
	printf("Value of arr[1] before function call= %d", arr[1]);
	modifyArrayElement(arr[1]);
	printf("\nValue of arr[1] after function call= %d", arr[1]);

	getch();

}
void modifyArrayElement(int element){
	element *= 2;
	printf("\nValue of arr[1] in function = %d", element);
}

void modifyArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++)
		arr[i] *= 2;
}