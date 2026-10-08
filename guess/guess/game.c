#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
#include<math.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void game()
{
	time_t start = time(NULL);
	srand((unsigned int)time(NULL));
	int real = rand()%100+1;
	int guess = 0;
	int count = 0;
	int min = 1;
	int max = 100;
	printf("范围是%d-%d\n",min,max);
	
	do 
	{
		count++;
		scanf("%d", &guess);
		if (real > guess)
		{
			printf("猜小了\n");
			min = guess;
			printf("范围是%d-%d\n",min,max);
		}
		else if (real < guess)
		{
			printf("猜大了\n");
			max = guess;
			printf("范围是%d-%d\n",min,max);
		}
	} while (guess != real&&count<5);
	if (count <= 5)
	{
		printf("猜测正确\n");
		printf("一共猜测%d次\n", count);
	}
	else
	{
		printf("猜测失败\n");
		printf("答案是%d\n", real);
	}
}