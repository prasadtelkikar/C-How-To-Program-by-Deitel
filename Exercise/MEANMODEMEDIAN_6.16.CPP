/*Mean: Average of values
Median:Picking a middle element of sorted array.Note that when there is an even number of elements,
the median should be calculated as the mean of the two middle elements.
Mode:The mode is the value that occurs most frequently in an array.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 99

float FindMean(int arr[]);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
float FindMedian(int arr[]);
int FindMode(int arr[]);
int FindMaxFreq(int arr[], int size);

void main(){
 //	int frequency[10] = {0};
	int elements[SIZE] = {0};
	int i, mode;
	float mean, median;
	clrscr();
	srand(time(NULL));
	for(i = 0; i < SIZE; i++)
		elements[i] = (1 + rand()%9);

       //	printArray(elements, SIZE);
	mean = FindMean(elements);
	median = FindMedian(elements);
	mode = FindMode(elements);
	printf("\nMean = %.2f",mean);
	printf("\nMedian = %.2f", median);
	printf("\nMode = %d", mode);
	getch();
}

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		if(i%10 == 0)
			printf("\n");

		printf("\t%d, ", arr[i]);
	}

}

float FindMean(int arr[]){
	int i, sum = 0;
	float mean;
	for(i = 0; i < SIZE; i++)
		sum += arr[i];

	mean = (float) sum/(float) SIZE;
	return mean;
}

float FindMedian(int arr[]){
	float sum = 0;
	int index = 0;
	bubbleSort(arr, SIZE);
	index = SIZE / 2;
	if(SIZE % 2 == 0)
	     sum = (arr[index] + arr[index + 1]) / 2;
	else
	     sum = arr[index];

	return sum;

}

void bubbleSort(int arr[], int size){
	int i, j, temp = 0;
	int flag = 1;

	for(i = 0; i < size; i++){
		flag = 1;
		for(j = 0; j < size - i -1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}
		}
		if(flag == 1)
			break;
	}
}

int FindMode(int arr[]){
	int frequency[10]={0};

	for(int i = 0; i < SIZE; i++){
		++frequency[arr[i]];
	}
	return FindMaxFreq(frequency, 10);
}

int FindMaxFreq(int arr[], int size){
	int index = 0, max = 0, i;
	max = arr[0];
	for(i = 1; i < size; i++){
		if(max < arr[i]){
			index = i;
			max = arr[i];
		}
	}
	return index;
}