/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月17日 星期三 16时25分49秒
 ************************************************************************/

#include<stdio.h>
    int c[20] = {0};
void MergeSort(int a[],int lo,int hi);
void Merge(int a[],int lo,int p,int hi);
void Copy(int a[],int c[],int left,int right);


void Copy(int a[],int c[],int left,int right)
{
    for(int i = left ; i <= right;i++)
    {
        a[i] = c[i];
    }
}
void MergeSort(int a[],int lo,int hi)
{
    if(lo >= hi)
        return;
    int p = (lo + hi) / 2;
    MergeSort(a,lo,p);
    MergeSort(a,p+1,hi);
    Merge(a,lo,p,hi);
    Copy(a,c,lo,hi);
}
void Merge(int a[],int lo,int p,int hi)
{
    int k = lo;
    int i = lo;
    int j = p+1;
    while(i <= p && j <= hi)
    {
        if(a[i] <= a[j])
        {
            c[k++]  = a[i++];
        }
        else
        {
            c[k++] = a[j++];
        }
    }
    while(i <= p || j <= hi)
    {
        if(i <= p)
            c[k++] = a[i++];
        if(j <= hi)
            c[k++] = a[j++];
    }
}
int main()
{
    int a[5] = {5,1,4,2,3};
    MergeSort(a,0,4);
    for(int i = 0 ; i < 5;i++)
        printf("%-4d",c[i]);
    return 0;
}
