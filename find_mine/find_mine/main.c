#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int main()
{
	time_t start = time(NULL);
	srand((unsigned int)time(NULL));
	int startgame = 0;
	do {
		printf("----------------\n");
		printf("-----1.play-----\n");
		printf("-----0.exit-----\n");
		printf("----------------\n");

		scanf("%d", &startgame);
		switch (startgame)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("开始游戏\n");
			game();
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}


	} while (startgame);

	return 0;
}
