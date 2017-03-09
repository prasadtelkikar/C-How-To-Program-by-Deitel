/*From exercise: Problem number:6.10*/
#include<stdio.h>
#include<conio.h>
void CalculateEarning(float arr[], int size);
void GetCount(float arr[], int headCount[], int size);
void PrintTab(int headCount[]);
void main(){
	int i, n;
	float sales[50];
	int headCount[9]={0};
	clrscr();
	printf("\nEnter Number of employees: ");
	scanf("%d",&n);

	for(i = 0;i < n; i++){
		printf("\nEnter sales of %dth employee: ",i);
		scanf("%f",&sales[i]);
	}

	CalculateEarning(sales, n);
	GetCount(sales, headCount, n);
	PrintTab(headCount);

	getch();
}

void CalculateEarning(float arr[], int size){
	int i;
	float sum = 0;
	for(i = 0; i < size;i++){
		arr[i] *= 0.09;
		arr[i] += 200;
	}
}

void GetCount(float arr[], int headCount[], int size){
	int i;
	for(i = 0;i < size; i++){
		if(arr[i] >= 200 && arr[i] <= 299.99)
			headCount[0]++;
		else if(arr[i] >= 300 && arr[i] <= 399.99)
			headCount[1]++;
		else if(arr[i] >= 400 && arr[i] <= 499.99)
			headCount[2]++;
		else if(arr[i] >= 500 && arr[i] <= 599.99)
			headCount[3]++;
		else if(arr[i] >= 600 && arr[i] <= 699.99)
			headCount[4]++;
		else if(arr[i] >= 700 && arr[i] <= 799.99)
			headCount[5]++;
		else if(arr[i] >= 800 && arr[i] <= 899.99)
			headCount[6]++;
		else if(arr[i] >= 900 && arr[i] <= 999.99)
			headCount[7]++;
		else
			headCount[8]++;
	}
}
void PrintTab(int headCount[]){
	int i;
	printf("\nRange\t\t\tHeadCount\n");
	for(i = 0; i < 40; i++)
		printf("-");
	printf("\n$200 - $299 %15d",headCount[0]);
	printf("\n$300 - $399 %15d",headCount[1]);
	printf("\n$400 - $499 %15d",headCount[2]);
	printf("\n$500 - $599 %15d",headCount[3]);
	printf("\n$600 - $699 %15d",headCount[4]);
	printf("\n$700 - $799 %15d",headCount[5]);
	printf("\n$800 - $899 %15d",headCount[6]);
	printf("\n$900 - $999 %15d",headCount[7]);
	printf("\n$1000- above %14d", headCount[8]);
}