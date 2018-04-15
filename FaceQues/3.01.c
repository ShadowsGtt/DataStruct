/*************************************************************************
* 问题描述:
* 题目二: 不修改数组找出重复的数字。
*  在一个长度为n+1的数组里的所有数字都在1~n的范围内，
*  所以数组中至少有一个数字是重复的。
*  请找出数组中任意一个重复的数字，
*  但不能修改输入的数组。
*  例如，如果输入长度为8 的数组{2，3,5,4,3,2,6,7}，
*  那么对应的输出是重复的数字2 或者3
*/
#include "../BitMap/BitMap.h"

/*
 * 方法：使用位图法
 * 具体做法：从数组下标0处开始扫描，
 * 判断位图中该位置处的值是否为1,如果是1则找到重复
 * 如果不是1,则将位图中该位置置1，继续向后扫描
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

    BITMAP bit;
    BIT_ZERO(bit);
    for(int i = 0; i < length;i++)
    {
        
        if(BIT_ISSET(bit,a[i]))
            return a[i];
        else
        {
            BIT_SET(bit,a[i]);
        }
        
    }
    return -1;

}
int main()
{
    int a[40] = {\
                2,3,1,0,4,5,6,7,8,9,             \
                10,11,12,13,14,15,16,17,18,19,   \
                20,21,22,23,24,25,26,27,28,29,   \
                30,31,32,33,34,35,36,37,38,2,   \
                };
    Print(a,40);
    putchar(10);

    int rept = FindOneRepeat(a,40);
    printf("the repeat number is:%d\n",rept);

    
}
