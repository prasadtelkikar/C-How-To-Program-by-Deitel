/*From example:6.22 Double subscripted array example*/
#include<stdio.h>
#include<conio.h>
#define EXAM 4
#define STUDENTS 3
int Minimum(int arr[][EXAM], int students, int tests);
int Maximum(int arr[][EXAM], int students, int tests);
float average(int arr[], int tests);
void printArray(int arr[][EXAM],int students, int tests);

void main(){
	int i, min, max;
	int studentGrades[STUDENTS][EXAM] = {{77, 68, 86, 73},
					      {96, 87, 89, 78},
					      {70, 90, 86, 81}};
	clrscr();

	min = Minimum(studentGrades, STUDENTS, EXAM);
	max = Minimum(studentGrades, STUDENTS, EXAM);

	printf("The array is:\n");
	printArray(studentGrades, STUDENTS, EXAM);
	printf("\n\nLower grade:%d\nHighest grade=%d\n", min, max);
	for(i = 0; i < STUDENTS; i++)
		printf("\nThe Average grade for student %d is %0.2f\n", i, average(studentGrades[i], EXAM));

	getch();
}
/*Find minimum grade*/
int Minimum(int grades[][EXAM], int students, int tests){
	int i, j, lowGrade = 100;
	for(i = 0; i < students; i++)
		for(j = 0; j < tests; j++)
			if(grades[i][j] < lowGrade)
				lowGrade = grades[i][j];

	return lowGrade;
}
/*Find maximum grade*/
int Maximum(int grades[][EXAM], int students, int tests){
	int i, j, highGrade = 0;
	for(i = 0;i < students; i++)
		for(j = 0; j < tests; j++)
			if(grades[i][j] > highGrade)
				highGrade = grades[i][j];

	return highGrade;
}

/*Average grade for a perticular exam*/
float average(int setOfMarks[], int tests){
	int i, total = 0;
	for(i = 0; i < tests; i++)
		total+= setOfMarks[i];

	return (float)total/tests;
}

/*Print an array*/
void printArray(int grades[][EXAM], int students, int tests){
	int i, j;
	printf("\n\t\t\t[0]\t[1]\t[2]\t[3]");
	for(i = 0; i < students; i++){
		printf("\nStudentGrades[%d] ",i);
		for(j = 0; j < tests; j++)
			printf("%9d",grades[i][j]);
	}
}