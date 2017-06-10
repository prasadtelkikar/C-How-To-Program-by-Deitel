#include <stdio.h>
#include <conio.h>

#define Pi 3.1412
#define Cube(r) (r * r * r)
#define Square(r) (r * r)
#define Area(r) ((4) * Pi * Square(r))
#define Volume(r) ((4.0 / 3.0) * Pi * Cube(r))

#define SUM(x, y) (x + y)

int main(){
	float radius;
	int x, y;

	printf("\n%s", "Enter radius :");
	scanf("%f", &radius);
	float areaOfSphere = Area(radius);
	float VolumeOfSphere = Volume(radius);
	
	printf("\nEnter value of X and Y: ");
	scanf("%d%d", &x, &y);

	printf("\nArea and Volume of sphere using preprocessor: ");
	printf("\n\t%s %.2f","Area of sphere is:", areaOfSphere);
	printf("\n\t%s %.2f","Volume of sphere is:", VolumeOfSphere);

	int result = SUM(x, y);
	printf("\n\nThe sum of %d and %d is %d\n\n", x, y, result);
}