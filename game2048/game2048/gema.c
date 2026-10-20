#include"game.h"
void startshow()
{
	printf("--------------------------\n");
	printf("--------1.开始游戏--------\n");
	printf("--------0.结束游戏--------\n");
	printf("--------------------------\n");
}

void finishshow()
{
	printf("--------------------------\n");
	printf("--------1.重新开始--------\n");
	printf("--------0.结束游戏--------\n");
	printf("--------------------------\n");
}

void game()
{
	int i, j;
	int borad[6][6];//棋盘
	int grade = 0;//总分
	int g = 0;//一次的分数
	for (i = 0;i < 6;i++)//棋盘初始化
	{
		for (j = 0;j < 6;j++)
		{
			borad[i][j] = 0;
		}
	}

	int flag = 1;
	while (flag)
	{
		put(borad);

		showborad(borad);//随机生成一个，空格-1；展示
		int d = direct();//上1  下2  左3  右4
		g = m_c(borad, d, g);
		grade += g;
		flag = finish(borad);
	}
	printf("游戏结束\n你的得分是%d\n", grade);
	finishshow();
}

void showborad(int arr[6][6])
{
	for (int i = 1;i < 5;i++)
	{
		printf(" ");
		for (int j = 1;j < 5;j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void put(int arr[6][6])
{

	int num = 1;
	int x, y, n;
	while (num)
	{
		x = rand() % 4 + 1;
		y = rand() % 4 + 1;
		n = (rand() % 2 + 1) * 2;
		if (arr[x][y] != 0)
		{
			continue;
		}
		else
		{
			arr[x][y] = n;
			num--;
		}

	}
}

int direct()
{
	int n;
	printf("选择方向wasd\n");
	while (1)
	{
		char d;
		scanf(" %c", &d);
		if (d == 'w')
		{
			n = 1;
			break;
		}
		else if (d == 's')
		{
			n = 2;
			break;
		}
		else if (d == 'a')
		{
			n = 3;
			break;
		}
		else if (d == 'd')
		{
			n = 4;
			break;
		}
		else
		{
			printf("输入错误\n");
			continue;
		}
	}
	return n;
}

int m_c(int arr[6][6], int d, int g)//move&&combine
{
	move(arr, d);
	g = combine(arr, d);
	move(arr, d);
	return g;
}

void move(int arr[6][6], int d)
{
	int k;
	switch (d)
	{
	case 1://上
		for (int j = 1;j < 5;j++)
		{
			k = 1;
			for (int i = 1;i <= 4;i++)
			{
				if (arr[i][j] == 0)
				{
					continue;
				}
				else
				{
					if (i > k)
					{
						arr[k][j] = arr[i][j];
						arr[i][j] = 0;
					}
					k++;
				}
			}
		}
		break;
	case 2://下
		for (int j = 1;j < 5;j++)
		{
			k = 4;
			for (int i = 4;i >= 1;i--)
			{
				if (arr[i][j] == 0)
				{
					continue;
				}
				else
				{
					if (i < k)
					{
						arr[k][j] = arr[i][j];
						arr[i][j] = 0;
					}
					k--;
				}
			}
		}
		break;
	case 3://左
		for (int i = 1;i < 5;i++)
		{
			k = 1;
			for (int j = 1;j <= 4;j++)
			{
				if (arr[i][j] == 0)
				{
					continue;
				}
				else
				{
					if (j > k)
					{
						arr[i][k] = arr[i][j];
						arr[i][j] = 0;
					}
					k++;
				}
			}
		}
		break;
	case 4://右
		for (int i = 1;i < 5;i++)
		{
			k = 4;
			for (int j = 4;j >= 1;j--)
			{
				if (arr[i][j] == 0)
				{
					continue;
				}
				else
				{
					if (j < k)
					{
						arr[i][k] = arr[i][j];
						arr[i][j] = 0;
					}
					k--;
				}
			}
		}
		break;
	}
}

int combine(int arr[6][6], int d)
{
	int num = 0;
	switch (d)
	{
	case 1://上
		for (int j = 1;j < 5;j++)
		{
			for (int i = 1;i <= 4;i++)
			{
				if (arr[i][j] == arr[i + 1][j])
				{
					arr[i][j] *= 2;
					arr[i + 1][j] = 0;
					num += arr[i][j];
				}
			}
		}
		break;
	case 2://下
		for (int j = 1;j < 5;j++)
		{
			for (int i = 4;i >= 1;i--)
			{
				if (arr[i][j] == arr[i - 1][j])
				{
					arr[i][j] *= 2;
					arr[i - 1][j] = 0;
					num += arr[i][j];
				}
			}
		}
		break;
	case 3://左
		for (int i = 1;i < 5;i++)
		{
			for (int j = 1;j <= 4;j++)
			{
				if (arr[i][j] == arr[i][j + 1])
				{
					arr[i][j] *= 2;
					arr[i][j + 1] = 0;
					num += arr[i][j];
				}
			}
		}
		break;
	case 4://右
		for (int i = 1;i < 5;i++)
		{
			for (int j = 4;j >= 1;j--)
			{
				if (arr[i][j] == arr[i][j - 1])
				{
					arr[i][j] *= 2;
					arr[i][j - 1] = 0;
					num += arr[i][j];
				}
			}
		}
		break;
	}
	return num;
}

int finish(int arr[6][6])
{
	int i, j;
	for (i = 1;i < 5;i++)
	{
		for (j = 1;j < 5;j++)
		{
			int p = arr[i][j];
			if (p == 0)
			{
				return 1;
			}
			else
			{
				if (p == arr[i + 1][j] || p == arr[i - 1][j] || p == arr[i][j + 1] || p == arr[i][j - 1])
				{
					return 1;
				}

			}
		}
	}
	return 0;
}