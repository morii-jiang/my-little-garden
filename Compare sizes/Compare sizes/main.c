#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0,b = 0,c = 0;
	scanf("%d%d%d", &a, &b, &c);
	int n = 0;
	if (c > b)
	{
		n = b;
		b = c;
		c = n;
	}
	if (b > a)
	{
		n = a;
		a = b;
		b = n;
	}
	printf("%d%d%d",a,b,c);
	return 0;
}