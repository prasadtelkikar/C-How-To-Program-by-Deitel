#include<stdio.h>
#include<conio.h>

void DrawBox()
{
	int i, j;
	for(i = 0; i<10; i++){
		printf("\n");
		for(j =0; j<10; j++){
			if(i == 0 || i == 9)
				printf("*");
			else {
			  if(j == 0 || j == 9)
				printf("*");
			  else
				printf(" ");
			}
		}
	}
}
void DrawOval(){
	int i =0, j =0, half = 7 / 2;
	for(i = 0;i<9; i++){
		printf("\n");
		for(j = 0; j<7; j++){
			if(i == 0 || i == 8){
				if(j >= (half - 1) && j <= (half + 1))
					printf("*");
				else
					printf(" ");
			}
			else if(i == 1 || i == 7){
				if(j == (half+2) || j == (half - 2))
					printf("*");
				else
					printf(" ");
			}
			else{
				if(j == 0 || j == 6)
					printf("*");
				else
					printf(" ");
			}
		}
	}
}

void DrawArrow(){
	int i = 0, j = 0,k =0, arrow = 5 /2;

	for(i=0;i<9;i++){
		printf("\n");
		for(j=0; j<arrow - i;j++)
			printf(" ");

		for(k = 0; k< (2*i+1); k++)
			if(i <= arrow)
				printf("*");
		if(i > arrow)
			for(j = 0; j < 5; j++){
				if(j == arrow)
					printf("*");
				else
					printf(" ");
		}
	}
}

void DrawDiamond(){
	int mid = 9/2, i, j, k, l;
	for(i = 0; i<9; i++){
	      printf("\n");
	      if(i <= mid){
		for(j = 0; j <mid - i; j++)
			printf(" ");

		printf("*");
	     }
	     if(i>0 &&i <= mid){
		for(k = 0; k < 2*i-1; k++)
			printf(" ");

		printf("*");
	     }
	    if(i > mid){
		for(k = 0; k <(i - mid); k++)
			printf(" ");

		printf("*");
	   }
	   if(i > mid && i <9 - 1){
		   for(k = 1; k < 2*(9 - i - 1); k++)
			printf(" ");

		   printf("*");
	   }

      }
}

void DrawChecksheet(){
	int i, j;
	for(i = 0; i< 10; i++){
		printf("\n");
		if(i%2 != 0)
			printf(" ");
		for(j = 0; j<10; j++)
			printf("* ");
	}
}

void main(){
	int choice;
	clrscr();
	do{
		printf("\n****************************Manu driven program****************");
		printf("\n\t1) Box\n\t2)Oval\n\t3)Arrow\n\t4)Diamond\n\t5)Checksheet");
		printf("\nEnter your choice(Enter -1 to end)");
		scanf("%d", &choice);
		clrscr();
		switch(choice){
			case 1:
			DrawBox();
			break;
			case 2:
			DrawOval();
			break;
			case 3:
			DrawArrow();
			break;
			case 4:
			DrawDiamond();
			break;
			case 5:
			DrawChecksheet();
			break;
		}
	}while(choice != -1);
}
