/*************************************************************************
	> File Name: QuickSort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月21日 星期日 17时09分49秒
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void QuickSort(int a[],int s,int t);
int Par(int a[],int i,int j);
void Swap(int *a,int *b);

void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int Par(int a[],int i,int j)
{
    int base = a[0];
    while(i < j)
    {
        while(i < j && (a[j] > base))
            j--;
        if(i < j)
        {
            a[i]  = a[j];
            i++;
            //Swap(&a[j],&a[i++]);
            
        }
        while(i < j && (a[i] < base))
            i++;
        if(i < j)
        {
            a[j] = a[i];
            //j--;
            Swap(&a[j--],&a[i]);
        }
        a[i] = base;
        return i;
    }
}
void QuickSort(int a[],int s,int t)
{
    if(s < t)
    {
        int m = Par(a,s,t);
        QuickSort(a,s,m-1);
        QuickSort(a,m+1,t);
    }
}
int main()
{
    int a[] = {7,1,4,2,3,9,6};// 7个
    QuickSort(a,0,6);
    for(int i = 0;i < 7;i++)
        printf("%-4d",a[i]);
    return 0;
}
