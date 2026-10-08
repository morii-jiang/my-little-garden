#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int p = 0;
	for (i = 1;i < 10;i++)
	{
		for (j = 1;j < 10;j++)
		{
			p = i * j;
			printf("%d ", p);
		}
		printf("\n");
	}
	return 0;
}