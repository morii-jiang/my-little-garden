#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int num = 0;
	for (i = 1;i <= 100;i++)
	{
		if (i % 10 == 9)
			num++;
		if (i / 10 == 9)
			num++;
	}
	printf("%d", num);
	return 0;
}