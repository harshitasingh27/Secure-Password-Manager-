#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char chr1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char chr2[] = "abcdefghijklmnopqrstuvwxyz";
	char chr3[] = "0123456789";
	char chr4[] = "!#$%&'()*+,-./:;<=>?@[\"]\\^_`{|}~";
	char pass[16];
	
	srand((unsigned int) time(0) + getpid());
	
	for(int i = 0; i < 16; i++)
	{
		int a = rand() % 4;
		switch(a)
		{
			case 0 : pass[i] = chr1[rand() % 26];
			break;
			
			case 1 : pass[i] = chr2[rand() % 26];
			break;
			
			case 2 : pass[i] = chr3[rand() % 10];
			break;
			
			case 3 : pass[i] = chr4[rand() % 13];
			break;
			
			default : printf("Default");
			break;
		}
		
	}
	int c = 16;
	while(c--)
		printf("%c", pass[15-c]);
	
	return 0;
}
