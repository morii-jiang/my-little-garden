#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void test()
{
    int n = 0;
    scanf("%d", &n);
    if (n == -1)
        return;   // 函数提前返回，结束test()
    printf("%d\n", n);

}

int main()
{
    test();
    return 0;
}