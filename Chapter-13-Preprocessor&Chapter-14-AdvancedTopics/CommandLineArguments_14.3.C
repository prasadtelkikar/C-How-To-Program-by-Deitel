#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* How to run:
 * cmd :> gcc -0 outputName CommandLineArguments_14.3.C
 * cmd :> outputName.exe 5 10 15 20
 ******Argument list ************
 * argc = 5 (exe + four values)
 * argv[0] = outputName.exe
 * argv[1] = 5
 * argv[2] = 10
 * argv[3] = 15
 * argv[4] = 20
*/
int main(int argc, char* argv[]){
	int total = 0;
	printf("\nArgc : %d", argc);
	for (i+nt i = 0; i < argc; ++i)
		total += atoi(argv[i]);

	printf("\nSum of %d numbers are equals to = %d", argc, total);
	return 0;
}