#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find(int arr[11], int n);
int main()
{
	int arr[11] = { 1,2,5,8,9,13,17,23,45,56,99 };
	int n = 0;
	int p;
	while (scanf("%d", &n) ==1)
	{
		p = find(arr, n);
		printf("%d\n", p);
	}
	return 0;
}

int find(int arr[11], int n)
{
	int i = 0;
	int j = 10;
	int m;
	do
	{
		m = (i + j) / 2;
		if (arr[m] < n)
		{
			i = 1 + m;
		}
		else if (arr[m] > n)
		{
			j = m - 1;
		}
		else if (arr[m] == n)
			break;
	} while (i<=j);
	if (arr[m] == n)
	{
		printf("找到了\n");
		return m;
	}
	else
	{
		printf("没找到\n");
		return -1;
	}
}