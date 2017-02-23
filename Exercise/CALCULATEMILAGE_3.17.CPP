#include<stdio.h>
#include<conio.h>

void main(){
	float gaslineVol;
	int distance;
	int totalG, totalD;
	float result, resultF;
	do{
		printf("\nEnter the gallons used (-1 to end): ");
		scanf("%f", &gaslineVol);

		if(gaslineVol == -1)
			break;

		printf("\nEnter the miles driven: ");
		scanf("%d", &distance);

		result = distance / gaslineVol;
		totalG += gaslineVol;
		totalD += distance;
		printf("\nThe miles/ gallon for this tank was %f", result);

	}while(gaslineVol != -1);

	resultF = totalD / totalG;
	printf("The overall average miles/gallon was %f", resultF);
}