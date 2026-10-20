#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int main()
{
	int winner;
	startframe();
	int flag;
	do 
	{
		winner = 0;
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("\n开始游戏\n");
			int broad[14][14];
			chessbroad(broad);
			int x, y;
			int n;
			int num = 1;
			int p = 0;

			scanf("%d%d", &x, &y);
			int step = 0;
			do {
				
				n = 2 - num;
				p=put(broad, x, y, n,num);
				if (p)
				{
					num = (num + 1) % 2;
					step--;
				}
				winner=judge(broad, x, y, n,winner);//判断5连
				num = (num + 1) % 2;
				step++;
				if (winner)
				{
					printf("游戏结束,%d号玩家获胜\n",winner);
					printf("二人一共走了%d步\n", step);
					break;
				}
				if (step == 13 * 13)//棋盘全下完了还没决出胜负
				{
					printf("游戏结束，和棋，没有赢家\n");
					break;
				}
			} while (scanf("%d%d", &x, &y) == 2);
		}
		else if (flag == 0)
		{
			printf("\n退出游戏\n");
			//break;
		}
		else
		{
			printf("\n请求错误\n");
		}
		if (flag && winner)
		{
			again();
		}
	} while (flag);
	return 0;
}
