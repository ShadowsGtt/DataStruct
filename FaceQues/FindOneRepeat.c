/*************************************************************************
 * 问题描述:
 找出数组中重复的数字。
    在一个长度为n 的数组里的所有数字都在0~n-1的范围内。数组中某
    些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了
    几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7 的数
    组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2 或者3。

 ************************************************************************/

 #include <time.h>
 #include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void Swap(int *a,int *b);
void Print(int *a,int length);

void Print(int *a,int length)
{
    int i = 0;
    for(i = 0 ;i < length;i++)
    {
        if(i%10 == 0)
            putchar(10);
        printf("%-4d",a[i]);
    }
}
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int FindOneRepeat(int *a,int length)
{
    assert(NULL != a);
    if(0 >= length)
        return -1;

    for(int i = 0;i < length;)
    {
        if(a[i] >= length)
            return -1;
        if(a[i] == i)
        {
            i++;
            continue;
        }
        else
        {
            if(a[i] == a[a[i]])
                return a[i];
            else
                Swap(&a[i],&a[a[i]]);
        }
    }
    return -1;
}
int main()
{
    int a[7] = {2,3,1,0,2,5,3};
    int repeat = FindOneRepeat(a,7);
    printf("repeat:%d\n",repeat);
}
