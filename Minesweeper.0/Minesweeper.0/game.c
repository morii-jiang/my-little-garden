#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char mine[11][11];
	char show[11][11];
	start(mine, '0');
	start(show, '*');


	putmine(mine);
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
			show[x][y] = count(mine, x, y);		/* 先翻开自己 */
			blank--;							/* 自己算一格 */
			blank -= open(mine, show, x, y);	/* 再扣掉额外翻开的格数 */
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

int open(char arr1[11][11], char arr2[11][11], int x, int y)
{
	/* 一次性多翻开几格：沿用"随机捎带 n 个空格"的玩法，
	   但先把真正可翻的邻居收集起来，只在其中随机取，绝不空转。
	   可翻 = 在 1~9 内、不是雷、还没翻开。 */
	int cand[8][2];
	int n = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;			/* 自己跳过 */
			int nx = x + i;
			int ny = y + j;
			if (nx < 1 || nx > 9 || ny < 1 || ny > 9) continue;	/* 边界 */
			if (arr1[nx][ny] != '0') continue;					/* 是雷 */
			if (arr2[nx][ny] != '*') continue;					/* 已经翻开过 */
			cand[n][0] = nx;
			cand[n][1] = ny;
			n++;
		}
	}

	if (n == 0)							/* 周围没得翻：直接收工，不会卡住 */
	{
		return 0;
	}

	int want = rand() % 6;				/* 这次想捎带 0~5 格 */
	if (want > n)						/* 凑不够就按实际有的来 */
	{
		want = n;
	}

	int p = 0;
	while (p < want && n > 0)
	{
		int k = rand() % n;				/* 从候选里抽，抽不重 */
		arr2[cand[k][0]][cand[k][1]] = count(arr1, cand[k][0], cand[k][1]);
		p++;
		cand[k][0] = cand[n - 1][0];		/* 选中的用最后一个补位 */
		cand[k][1] = cand[n - 1][1];
		n--;
	}

	return p;							/* 返回真正翻开的格数，交给 game() 扣 blank */
}