/*************************************************************************
	> File Name: QuickSort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月21日 星期日 17时09分49秒
 ************************************************************************/
 #include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void QuickSort(int a[],int s,int t);
int Par(int a[],int i,int j);
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

/* 这个函数将要排序的数列划分
* 为两个部分,在关键字左边的是
* 比关键字小的数,在关键字右边
* 的是比关键字大的部分。
* 
* 返回值:关键字的下标*/
int count = 1;
int Par(int a[],int head,int tail)
{
    printf("\npar:\n");
    printf("[%d,%d]",head,tail);
    int i = head;
    int j = tail;
    int length = j-i+1;
    int base = 0;

    base = a[head];

    while(i < j)
    {
        while(i < j && (a[j] >= base))
            j--;
        if(i < j)
        {
            Swap(&a[j],&a[i]);
            i++;
        }
        
        Print(a,length);
        

        while(i < j && (a[i] <= base))
            i++;
        if(i < j)
        {
            Swap(&a[j],&a[i]);
            j--;
        }

        //Print(a,length);

    }
        Print(a,length);
    printf("\ni:%d\n",i);
    return i;
}

/* 随机化快排 */
int Par_fair(int a[],int head,int tail)
{
    //printf("[%d,%d]",head,tail);
    int i = head;
    int j = tail;
    int length = j-i+1;
    int base = 0;

    srand(time(NULL)+head+tail);
    int k =   rand()%(tail-head+1)+head;
    //printf("\n关键字:%d\n",a[k]);

    Swap(&a[head],&a[k]);
    base = a[head];



    while(i < j)
    {
        while(i < j && (a[j] > base))
            j--;
        if(i < j)
        {
            //printf("\nswap:%d  <->  %d\n",a[j],a[i]);
            Swap(&a[j],&a[i]);
            i++;
            //Print(a,length);
        }
        

        while(i < j && (a[i] < base))
            i++;
        if(i < j)
        {
            //printf("\nswap:%d  <->  %d\n",a[j],a[i]);
            Swap(&a[j],&a[i]);
            j--;
            //Print(a,length);
        }

    }
    //printf("\n一大轮交换完毕后,分割点:%d\n",a[i]);
        //Print(a,length);
    printf("\npar:%d\n",i);
    return i;
}

void QuickSort(int a[],int s,int t)
{
    if(s < t)
    {
    printf("\n[%d,%d]\n",s,t);
        int m = Par_fair(a,s,t);
        QuickSort(a,s,m-1);
        QuickSort(a,m+1,t);
    }
}
int main()
{
    int a[] = {7,1,4,2,9,6,5,3,10,0};
    int length = sizeof(a)/sizeof(int);

    /*
    for(int i = 0;i < length;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%50;
    }
    */
    printf("\n原始数组:\n");
    Print(a,length);

    QuickSort(a,0,length-1);
    putchar(10);
    printf("\n最终排序结果:\n");
    Print(a,length);
    putchar(10);
    return 0;
}
