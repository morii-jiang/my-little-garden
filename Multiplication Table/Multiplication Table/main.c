#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int p = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 1;i < n+1;i++)
	{
		for (j = 1;j < n+1;j++)
		{
			p = i * j;
			printf("%d ", p);
		}
		printf("\n");
	}
	return 0;
}