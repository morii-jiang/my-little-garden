#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>

void game();
void start(char arr[11][11], char c);
void display(char arr[11][11]);
void putmine(char arr[11][11]);
char count(char arr[11][11], int x, int y);
void open(char arr1[11][11], char arr2[11][11], int x, int y);