#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
/*
*折半直接插入排序思想：
*     这种排序是在直接插入排序的基础上
*     进行了优化,直接插入排序是将无序
*     部分第一个数插入到有序部分的适当
*     位置.而在折半直接插入排序中这个
*     适当位置是通过二分法查找(也就是
*     折半查找)得来的.
* */

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

/* 此处的折半查找并不是寻找目标元素下标
* 而是查找目标元素在目标数组中按照顺序应该插入的位置
* 此处是从小到大排序*/
int HaflFind(int *a,int head,int tail,int aim)
{
    int mid;
    int index;

    while(head <= tail)
    {
        mid = (head + tail) / 2;
        if(a[mid] > aim)
        {
            tail = mid - 1;
            index = tail + 1;
        }
        else
        {
            head = mid + 1;
            index = head;
        }
    }
    printf("\nindex:%d\n",index);  //插入到有序部分中的位置
    return index;
}

void HalfDirectlyInsert(int *a,int length)
{
    
    printf("\n排序前:\n");
    Print(a,length);

    int i ;
    int j ;
    int  flag;  //哨兵,即无序数中的第一个
    int line = 1;  //第一个无序数的下标

    for(i = 0;i < length - 1;i++){
        flag = a[line]; //flag是无序部分中第一个数
        j = line -1;  //j为有序数中最后一个元素下标
        int index = HaflFind(a,0,j,flag); //找到应该插入的位置
        for(int k = line;k > index;k--)
            a[k] = a[k-1];
        a[index] =flag;
        line ++;  //每次插入后line后退一个
        Print(a,length);
    }

    printf("\n\n排序后:");
    Print(a,length);
}

int main()
{

    int a[5] = {3,1,5,2,4};
    //int a[100] = {0};
    /*
    for(int i = 0;i < 100;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%500;
    }
    */
    HalfDirectlyInsert(a,5);
}
