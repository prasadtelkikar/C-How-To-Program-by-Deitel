#include <stdio.h>
#include <conio.h>

int main(){
	int size = 0;
	printf("%s\n", "Enter size of Square: ");
	scanf("%d",&size);
	int count = 0;
	Beginning:
		if(count > size)
			goto end;
		if(count == 0 || count == size){
			printf("\n");
			goto FirstLastLine;
		}
		else{
			printf("\n");
			goto MiddleLine;
		}

	FirstLastLine:
		for (int i = 0; i < size; ++i)
			printf("*");
		count++;
		goto Beginning;

	MiddleLine:
		for (int i = 0; i < size; ++i)
		{
			if(i == 0 || i == size - 1)
				printf("*");
			else
				printf(" ");
		}
		count++;
	goto Beginning;
	
	end:
	return 0;	
}