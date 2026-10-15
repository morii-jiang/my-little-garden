#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void startframe()
{
	printf("--------------------\n");
	printf("-----1.开始游戏-----\n");
	printf("-----0.退出游戏-----\n");
	printf("--------------------\n");
}
void chessbroad(int arr[14][14])
{
	
	int i, j;
	for (i = 0;i < 14;i++)
	{
		if (i < 10)
		{
			printf("%d ", i);
		}
		else 
		{
			printf("%c ", 'a' + i - 10);
		}
	}
	for (i = 0;i < 14; i++)
	{
		if (i > 0)
		{
			if (i < 10)
			{
				printf("%d ", i);
			}
			else
			{
				printf("%c ", 'a' + i - 10);
			}
		}
		for (j = 0;j < 14;j++)
		{
			arr[i][j] = 0;
			if (i != 0 && j != 0)
			{
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
int put(int arr[14][14] ,int x,int y,int n,int num)
{
	
	if (arr[x][y])
	{
		printf("此处已有棋子，请重新下子\n");
		return 1;
	}
	else
	{
		arr[x][y] = n;
	}
	printf("\n");
	show(arr);
	return 0;

}
void show(int arr[14][14])
{
	int i, j;
	for (i = 0;i < 14;i++)
	{
		if (i < 10)
		{
			printf("%d ", i);
		}
		else
		{
			printf("%c ", 'a' + i - 10);
		}
	}
	for (i = 0;i < 14; i++)
	{
		if (i > 0)
		{
			if (i < 10)
			{
				printf("%d ", i);
			}
			else
			{
				printf("%c ", 'a' + i - 10);
			}
		}
		for (j = 0;j < 14;j++)
		{
			if (i != 0 && j != 0)
			{
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
int judge(int arr[14][14],int x,int y,int n,int w)
{
	//上下   左右    斜1   斜2
	int p = 1;
	int i, j;
	int num;
	int left,right,up,down,left_up,left_down,right_up,right_down;
	while (p < 5)
	{
		left = 1;
		right = 1;
		up = 1;
		down = 1;
		left_down = 1;
		left_up = 1;
		right_down = 1;
		right_up = 1;
		num = 1;
		switch (p)
		{
		case 1:
		{
			
			j = 1;
			while (num < 5 && (arr[x][y + j] == arr[x][y] || arr[x][y - j] == arr[x][y]) && y + j < 14 && y - j>0)
			{
				if (arr[x][y]!=arr[x][y - j])
				{
					left = 0;
				}
				if (arr[x][y] != arr[x][y + j])
				{
					right = 0;
				}
				if (arr[x][y] == arr[x][y - j]&&left)
				{
					num++;
				}
				if (arr[x][y] == arr[x][y + j]&&right)
				{
					num++;
				}
				if (num == 5)
				{
					return n;
				}
				j++;
			}
			break;
		}
		case 2:
		{
			
			i = 1;
			while (num < 5 && (arr[x + i][y] == arr[x][y] || arr[x - i][y] == arr[x][y]) && x + i < 14 && x - i>0)
			{
				if (arr[x][y] != arr[x+i][y])
				{
					down = 0;
				}
				if (arr[x][y] != arr[x-i][y])
				{
					up = 0;
				}
				if (arr[x][y] == arr[x - i][y]&&up)
				{
					num++;
				}
				if (arr[x][y] == arr[x + i][y]&&down)
				{
					num++;
				}
				if (num == 5)
				{
					return n;
				}
				i++;
			}
			break;
		}
		case 3://左上&右下
		{
			
			i = 1;
			j = 1;
			while (num < 5 && (arr[x + i][y + j] == arr[x][y] || arr[x - i][y - j] == arr[x][y]) && y + j < 14 && y - j>0 && x + i < 14 && x - i>0)
			{
				if (arr[x][y] != arr[x-i][y - j])
				{
					left_up = 0;
				}
				if (arr[x][y] != arr[x+i][y + j])
				{
					right_down = 0;
				}
				if (arr[x][y] == arr[x - i][y - j]&&left_up)
				{
					num++;
				}
				if (arr[x][y] == arr[x + i][y + j]&&right_down)
				{
					num++;
				}
				if (num == 5)
				{
					return n;
				}
				i++;
				j++;

			}
			break;
		}
		case 4://左下&右上
		{
			i = 1;
			j = 1;
			while (num < 5 && (arr[x - i][y + j] == arr[x][y] || arr[x + i][y - j] == arr[x][y]) && y + j < 14 && y - j>0 && x + i < 14 && x - i>0)
			{
				if (arr[x][y] != arr[x+i][y - j])
				{
					left_down = 0;
				}
				if (arr[x][y] != arr[x-i][y + j])
				{
					right_up = 0;
				}
				if (arr[x][y] == arr[x + i][y - j]&&left_down)
				{
					num++;
				}
				if (arr[x][y] == arr[x - i][y + j]&&right_up)
				{
					num++;
				}
				if (num == 5)
				{
					return n;
				}
				i++;
				j++;

			}
			break;
		}
		}
		p++;
	}
	return 0;
}
void again()
{
	printf("--------------------\n");
	printf("-----1.重新开始-----\n");
	printf("-----0.退出游戏-----\n");
	printf("--------------------\n");
}