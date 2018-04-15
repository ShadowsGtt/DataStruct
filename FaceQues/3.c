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
/*
 *方法：因为数组大小为n,且数组每一个元素
 *大小范围都在0 到 n-1所以必然有重复
 *将数组里每一个元素放到对应下标处，就能找到重复的数组
 * 具体做法：从数组下标0开始，判断该下标处的数字是否等于该下标
 * 如果相等，继续向后扫描，如果不想等，则判断该数字对应下标处的数字
 * 是否放置了对应数字，如果放置，则找到重复数字，如果没有放置，将该
 * 数字放置到对应下标位置，继续向后扫描
 */

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
