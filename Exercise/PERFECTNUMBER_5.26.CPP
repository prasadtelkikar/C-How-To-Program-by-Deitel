#include<stdio.h>
#include<conio.h>
int perfect(int number);

void main(){
	int n, sum;
	clrscr();
	printf("\nEnter number:");
	scanf("%d",&n);
	sum = perfect(n);
	if(sum == n)
		printf("\nPerfect Number");
	else
		printf("\nNot a perfect number");

	getch();

}

int perfect(int number){
	int i, sum = 0;
	for(i = 1; i< number; i++){
		if(number % i == 0){
			printf(" %d", i);
		     sum += i;
		}
	}
	return sum;
}