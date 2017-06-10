#include <stdio.h>
#include <conio.h>

#define MINIMUM2(x , y) (x > y) ? x : y
#define MINIMUM3(x, y, z) (MINIMUM2(x, y) > z) ? MINIMUM2(x, y) : z
#define Print(x) printf("%s", x)

int main(){
	int x, y, z;
	printf("\nEnter values of x, y, z: ");
	printf("\n\tValue for X: ");
	scanf("%d", &x);
	printf("\n\tValue for Y: ");
	scanf("%d", &y);
	printf("\n\tValue for Z: ");
	scanf("%d", &z);
	int min2 = MINIMUM2(x, y);
	int min3 = MINIMUM3(x, y, z);
	char str[30];
	printf("\n Minimum from %d and %d is %d", x, y, min2);
	printf("\n Minimum from %d, %d and %d is %d\n", x, y, z, min3);
	Print("Enter string: ");
	scanf("%s", str);
	Print(str);
}