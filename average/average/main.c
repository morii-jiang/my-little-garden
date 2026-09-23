#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		scanf("%d", &arr[i]);
	}
	int sum = 0;
	for (i = 0;i < 10;i++)
	{
		sum += arr[i];
	}
	printf("%f", sum / 10.0);
	return 0;
}