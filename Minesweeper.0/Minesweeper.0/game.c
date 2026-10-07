#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char mine[11][11];
	char show[11][11];
	start(mine, '0');
	start(show, '*');


	putmine(mine);
	//display(mine);
	int flag = 1;
	int blank = 71;
	int x, y;
	printf("\n");
	do {
		display(show);
		printf("\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] - '0' == 1)
		{
			flag = 0;
		}
		else if (mine[x][y] - '0' == 0)
		{
			blank--;
			show[x][y] = count(mine,x,y);
			//open(mine, show, x, y);
		}
	} while (flag&&blank);
	if (flag == 0)
	{
		printf("踩到地雷，游戏结束\n");
	}
	else if (blank == 0)
	{
		printf("扫雷成功，游戏结束\n");
	}
	display(mine);
}


void start(char arr[11][11], char c)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < 11; i++)
	{
		for (j = 0;j < 11;j++)
		{
			arr[i][j] = c;
		}
	}
}


void display(char arr[11][11])
{
	int i = 0;
	int j = 0;
	for (int i = 0;i < 10;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i < 10; i++)
	{
		printf("%d ", i);
		for (j = 1;j < 10;j++)
		{
			
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}


void putmine(char arr[11][11])
{
	int count = 10;
	do {
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (arr[x][y] - '0' == 0)
		{
			arr[x][y] = '1';
			count--;
		}
	} while (count);
}


char count(char arr[11][11],int x,int y)
{
	int num = 0;
	char n = '0';
	for (int i = 0;i <= 2;i++)
	{
		for (int j = 0;j <= 2;j++)
		{
			if (arr[x - 1 + i][y - 1 + j] - '0' == 1)
			{
				num++;
			}
		}
	}
	n += num;
	return n;
}

//void open(char arr1[11][11],char arr2[11][11],int x,int y)
//{
//	int num = rand() % 3;
//	int p = 0;
//	switch (num)
//	{
//	case 0:
//		break;
//	case 1:
//		break;
//	case 2:
//		do 
//		{
//
//		} while(num);
//		break;
//	}
//}