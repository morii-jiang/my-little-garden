#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d", &a, &b);
	if (a > b)
	{
		c = b;
	}
	else
	{
		c = a;
	}
	int i = 0;
	int max = 1;
	for (i = 1;i <= c;i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}
	printf("%d", max);
	return 0;
}