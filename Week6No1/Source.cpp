#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <cctype>
int checkprevious(int used, char** p);
void convertolow(char *temp);
int main()
{
	char vowel[5] = {'a','e','i','o','u'};
	char *temp=(char*)malloc(15*sizeof(char));	
	int escape=0,used=0;
	double score=0;
	time_t t;
	srand((unsigned)time(&t));
	int r = rand() % 25,c = 'a' + r,n;
	printf("How many words do you wanna play? : ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("\nAre you kidding me?\n");
		return 0;
	}
	char** str;
	str = (char**)malloc(n*sizeof(str));
	for (int i = 0; i < n; i++)
	{
		str[i] = (char*)malloc(15*sizeof(char));
	}
	printf("Start with : %c\n", c);
	for (int i = 0; i < n; i++)
	{
		if(i==0)
		{
			scanf("%s", temp);
			convertolow(temp);
			char* p = temp;
			if (*p == c)
			{
				strcpy(str[i], temp);
				c = temp[strlen(temp)-1];
				used++;
				score += 100;
				memset(temp, 0, 15);
			}
			else
			{
				printf("\nGame over! Omae Wa Mou Shindeiru!\n");
				printf("\nThis is your score >>>> %.0lf\n", score);
				return 0;
			}
		}
		else
		{
			printf("Start with : %c\n", c);
			scanf("%s", temp);
			convertolow(temp);
			char* p = temp;
			if (*p == c)
			{
				strcpy(str[i], temp);
				c = temp[strlen(temp) - 1];
				used++;
			}
			else
			{
				printf("Game over! Omae Wa Mou Shindeiru!");
				printf("\nThis is your score >>>> %.0lf\n", score);
				return 0;
			}
			escape = checkprevious(used,str);
			if (escape == 1)
			{
				printf("\nGame over! Omae Wa Mou Shindeiru!\n");
				printf("\nThis is your score >>>> %.0lf\n", score);
				return 0;
			}
			score += 100;
			memset(temp, 0, 15);
		}
		for (int j = 0; j < 15; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (str[used - 1][j] == vowel[k])
				{
					score += 300;
					break;
				}
			}
		}
	}
	printf("\nYou win! Conglaturation\n");
	printf("\nThis is your score >>>> %.0lf\n",score);
	return 0;
}
int checkprevious(int used, char** p)
{
	int r=0;
	for (int i = 0; i < used-1; i++)
	{
		if (strcmp(p[used - 1], p[i]) == 0)
		{
			r = 1;
			break;
		}
	}
	return r;
}
void convertolow(char *temp)
{
	for (int i = 0; i < 15; i++)
	{
		temp[i]=tolower(temp[i]);
	}
}