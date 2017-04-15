#include <stdio.h>
#include <conio.h>
#include <string.h>
/*ASCII A = 65, Z = 90, a = 97, z = 122, 1 = 49, 9 = 57*/
void ConversionEnglishToMorse(char *sentence, const char *MorseCodeNumberic[], const char *MorseCodeAlphabets[]);
void ConversionMorseToEnglish(char *sentence, const char *MorseCodeNumberic[], const char *MorseCodeAlphabets[]);

int main(){
	char sentence[30];
	int flag = 1;
	int choice = 0, exit;
	const char *MorseCodeAlphabets[] = {".-", "-...", "-.-.", "-..", ".", "..-.", 
					   "--.", "....", "..", ".---", "-.-", ".-..",
					   "--","-.","---",".--.", "--.-",".-.", "...",
					   "-", "..-","...-",".---","-..-","-.--","--.."};
	const char *MorseCodeNumberic[] = {".---", "..---", "...--", "...--", "....-",
							   ".....", "-....", "--...", "---..", "----.", 
							   "-----"};
	do{
		printf("\n1. English To Morse code");
		printf("\n2. Morse code to English");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		char ch = getchar();
		switch(choice){
			case 1:
				printf("Enter sentence: ");
				gets(sentence);		
				ConversionEnglishToMorse(sentence, MorseCodeNumberic, MorseCodeAlphabets);
				printf("\n");
			break;
			case 2:
				printf("Enter sentence: ");
				gets(sentence);		
				ConversionMorseToEnglish(sentence, MorseCodeNumberic, MorseCodeAlphabets);
				printf("\n");
			break;
		}
		printf("\nDo you want to continue (0 to exit): ");
		scanf("%d", &exit);
	}while(exit != 0);
	return 0;
}

void ConversionEnglishToMorse(char *sentence, const char *MorseCodeNumberic[], const char *MorseCodeAlphabets[]){
	for (int i = 0; i < strlen(sentence); ++i)
	{
		int ascii = sentence[i];
		if(ascii > 64 && ascii < 91) {
			printf("%s", MorseCodeAlphabets[ascii - 65]);
		}
		else if(ascii > 96 && ascii < 123){
				printf("%s", MorseCodeAlphabets[ascii - 97]);	
		}
		else if (ascii > 48 && ascii < 58){
			printf("%s", MorseCodeAlphabets[ascii - 49]);
		}
		else if(ascii == 32)
			printf(" ");
		else
			printf("\n%s\n", "Wrong input");
	}
}
//Todo
void ConversionMorseToEnglish(char *sentence, const char *MorseCodeNumberic[], const char *MorseCodeAlphabets[]){
	printf("%s\n", "TODO");
}