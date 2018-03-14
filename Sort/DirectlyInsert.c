#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define bool int
#define false 0
#define true 1
/*
* 思想:将数组分为两个部分,一部分为有序,一部分为无序
* 起始时,有序部分只有一个数,然后将无序部分的第一个数
* 插入到有序部分中,直至无序部分为空*/

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

void DirectlySort(int *a,int length)
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
        while(a[j] < flag && j+1)  //将小数后移,即从大到小排序
        //while(a[j] > flag && j+1 )  //将大数后移,即从小到大排序
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] =flag;
        line ++;  //每次插入后line后退一个
    }

    printf("\n\n排序后:");
    Print(a,length);
}

int main()
{

    int a[100] = {0};
    for(int i = 0;i < 100;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%500;
    }
    DirectlySort(a,100);
}
