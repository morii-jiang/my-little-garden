#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void startframe();
void chessbroad(int arr[14][14]);
int put(int arr[14][14],int x,int y,int n,int num);
void show(int arr[14][14]);
int judge(int arr[14][14], int x, int y, int n,int w);
void again();