/*
* 问题描述：给定数组a,给定数组长度
* 将数组中重复的元素剔除，最后返回数组长度
*
* 例如：给定数组  1 1 1 2 长度：4
*       输出结果为:1 2 数组长度 2
* 要求：不能使用额外的空间，只能在原来数组内操作
* */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int RemvRept(int *a,int length)
{
    assert(0 != length);
    assert(NULL != a);
    if(1 == length)
        return length;

    int len = length;
    int *head = a;
    int *tail = a + 1;

    while(tail < a + length)
    {
        while(*head == *tail)
        {
            tail++;
            len--;
        }
        if(tail < a + length)
        {
            *(head + 1) = *tail;
        }
        head++;
        tail++;
    }
    return len;
}

int main()
{
    int a[2] = {1,1};
    int b[6] = {1,1,1,2,2,3};
    int c[6] = {1,1,2,2,3,3};
    
    int alen = RemvRept(a,2);
    int blen = RemvRept(b,6);
    int clen = RemvRept(c,6);

    printf("alen:%d    blen:%d   clen:%d\n",alen,blen,clen);

    for(int i = 0; i < alen;i++)
        printf("%-4d",a[i]);
    printf("\n");

    for(int i = 0; i < blen;i++)
        printf("%-4d",b[i]);
    printf("\n");
    
    for(int i = 0; i < clen;i++)
        printf("%-4d",c[i]);
    printf("\n");
}
