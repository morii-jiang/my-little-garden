#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int year = 0;
	for (i = 1000;i <= 2000;i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			year = i;
			printf("%d ",year);
		}
	}
	return 0;
}