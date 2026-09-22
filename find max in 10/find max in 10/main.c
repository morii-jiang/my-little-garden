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
	for (i = 0;i < 9;i++)
	{
		if (arr[i] > arr[i + 1])
			arr[i + 1] = arr[i];
	}
	printf("%d", arr[9]);
	return 0;
}