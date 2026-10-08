/* 用真实游戏循环（逐字节照抄 game()）自测：只点空格，看能不能走到"扫雷成功"。
   这同时证明两件事：
     1) open() 不空转（会结束）
     2) blank 记账正确 —— 翻开全部 71 个空格那一刻 blank 恰好归零
   仅自测用，不进工程。 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "game.c"

int main(void)
{
	int seed;
	int wins = 0, losses = 0, stuck = 0;

	for (seed = 1; seed <= 200; seed++)
	{
		char mine[11][11], show[11][11];
		int flag = 1, blank = 71;
		int x, y, guard;

		start(mine, '0');
		start(show, '*');
		srand(seed);
		putmine(mine);

		/* 只点空格，直到赢或没有空格可点 */
		for (guard = 0; guard < 5000 && flag && blank; guard++)
		{
			for (x = 1; x <= 9; x++)
				for (y = 1; y <= 9; y++)
					if (mine[x][y] == '0' && show[x][y] == '*')
					{
						show[x][y] = count(mine, x, y);
						blank--;
						blank -= open(mine, show, x, y);
					}
		}

		if (blank == 0) wins++;
		else if (flag == 0) losses++;
		else stuck++;
	}

	printf("=== real game-loop self-test (safe clicks only) ===\n");
	printf("seeds=200  wins=%d  losses=%d  stuck=%d\n", wins, losses, stuck);
	printf(wins == 200 ? "RESULT: PASS (blank 记账正确, 200/200 全部判胜)\n"
		: "RESULT: FAIL (有局没能走到胜利)\n");
	return wins == 200 ? 0 : 1;
}
