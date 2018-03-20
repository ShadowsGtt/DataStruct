 #include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*
* 直接选择排序(又叫简单选择排序)思想:
*       将数组分为两个部分,第一部分为排序过后的,第二部分是未排序的
*       从第二部分中选择最小的一个元素,放在第一部分的末尾
*       直到第二部分为空*/
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

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

void SelectSort(int *a,int head,int tail)
{
    int k = 0;
    int i = head;
    int j = 0;

    for(i;i <= tail ; i++)
    {
        k = i;
        for(j = i + 1;j <= tail; j++)
        {
            if(a[j] < a[k])
                k = j;
        }
        if( k != i )
            Swap(&a[k],&a[i]);
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

    SelectSort(a,0,length-1);
    putchar(10);
    printf("\n最终排序结果:\n");
    Print(a,length);
    return 0;
}

