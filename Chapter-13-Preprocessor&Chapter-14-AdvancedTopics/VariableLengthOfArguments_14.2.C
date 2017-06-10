#include <stdio.h>
#include <conio.h>
#include <stdarg.h> //Handle variable length of arguments

int Product(int count, ...);

int main(){
	int v1 = 4, v2 = 8, v3 = 12, v4 = 16;
	printf("\nValues:\n");
	printf("\n\tV1 : %d", v1);
	printf("\n\tV2 : %d", v2);
	printf("\n\tV3 : %d", v3);
	printf("\n\tV4 : %d", v4);
	printf("\n-----------------------------------------");
	printf("\n%s : %12d","Sum of V1 and V2 ",Product(2, v1, v2));
	printf("\n%s : %8d","Sum of V1, V2 and V3 ",Product(3, v1, v2, v3));
	printf("\n%s : %4d","Sum of V1, V2, V3 and V4 ",Product(4, v1, v2, v3, v4));
	printf("\n-----------------------------------------");

}

//Variable length of argumenets; Count = number of arguments
int Product(int count, ...){
	int total = 0;

	int i=0;
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; ++i)
		total += va_arg(ap, int);

	va_end(ap);

	return total;
}