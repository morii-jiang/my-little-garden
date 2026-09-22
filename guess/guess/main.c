#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
#include<time.h>


int main()
{
	int start = 0;
	do
	{


		printf("--------------------\n");
		printf("-----1.开始游戏-----\n");
		printf("-----2.退出游戏-----\n");
		printf("--------------------\n");

		scanf("%d", &start);
		/*if (start == 1)
		{
			printf("-----准备开始-----\n");

		}
		else if(start==2)
		{
			printf("-----下次再见-----\n");
		}
		else
		{
			printf("选择错误，重新选择");
		}*/
		switch (start)
		{
		case 1:
			printf("-----准备开始-----\n");
			game();
			break;
		case 2:
			printf("-----下次再见-----\n");
			break;
		default:
			printf("选择错误，重新选择\n");
		}
	} while (start != 2);
	return 0;


}