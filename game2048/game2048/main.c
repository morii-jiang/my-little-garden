#include"game.h"
int main()
{
	time_t start = time(NULL);
	srand((unsigned int)time(NULL));
	startshow();
	int stp;//游戏是否开始
	while (scanf("%d", &stp) != EOF)
	{
		if (stp == 0)
		{
			printf("结束游戏\n");
			break;
		}
		else if (stp == 1)
		{
			printf("开始游戏\n请使用wasd来控制\n\n");
			game();
		}
		else
		{
			printf("选择错误，重新选择\n");
			continue;
		}
	}

	return 0;
}