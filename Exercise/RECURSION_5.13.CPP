/*Menu driven program implementing recursion*/
#include<stdio.h>
#include<conio.h>

int Factorial(int n);
int Fibbonacci(int n);
int GCD(int n, int n1);
int TowerOfHonoi();
void main(){
	int choice, n, n1;
	int fact = 0;
	clrscr();
	do{
	printf("\n*****Implementing RECURSION using menu driven program *****");
	printf("\n\t 1) Factorial\n\t 2) Fibbonacci Series \n\t 3) GCD");
	printf("\n\t 4) Multiply two numbers\n\t 5) Tower of Honoi");
	printf("\nEnter your choice(-1 to end)");
	scanf("%d",&choice);

	switch(choice){
		case 1:
			printf("\nEnter n for factorial (n!):");
			scanf("%d",&n);
			fact = Factorial(n);
			printf("Factorial of %d is = %d", n, fact);
		break;
		case 2:
			printf("\nEnter n for printing fibonnacci");
			scanf("%d", &n);
			printf("%d", Fibbonacci(n));
		break;
		case 3:
			printf("\nEnter two numbers:");
			scanf("%d%d",&n,&n1);
			printf("\nGCD of %d & %d = %d",n, n1, GCD(n, n1));
		break;
		case 4:
		n = TowerOfHonoi();
		break;
		}
	}while(choice != -1);


}

int Factorial(int fact){
	if(fact == 1)
		return fact;
	else
	       return fact * Factorial(fact - 1);
}

int Fibbonacci(int n){
	if(n == 0 || n == 1){
		return n;
	}
	else
	  {
		return (Fibbonacci(n - 1) + Fibbonacci(n -2));
	  }
}

int GCD(int n1, int n2){
	if(n2 != 0)
		return GCD(n2, n1%n2);
	else
		return n1;
}

int TowerOfHoni(){
//TODO: implement program
}