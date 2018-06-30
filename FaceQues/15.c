#include <stdio.h>

/* 读取一个数字，输出该数字二进制表示中１的个数 */
int NumOfOne(int num)
{
    int n = num;
    int count = 0;
    while(n)
    {
        n = (n-1)&n;
        ++count;
    }

    return  count;
}

int main()
{
    printf("%d\n",NumOfOne(-1));
    return  0;
}
