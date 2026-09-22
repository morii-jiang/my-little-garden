#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	float sum = 0;
	for (i = 1;i <= 100;i++)
	{
		sum += 1.0 / i;
	}
	printf("%f", sum);
	return 0;
}