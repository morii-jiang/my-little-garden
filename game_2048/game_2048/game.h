#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>


void game();
void startshow();
void finishshow();
void showborad(int arr[6][6]);
void put(int arr[6][6]);
int direct();
int m_c(int arr[6][6], int d,int g);
void move(int arr[6][6], int d);
int combine(int arr[6][6], int d);
int finish(int arr[6][6]);