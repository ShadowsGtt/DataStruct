
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

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



void ShellSort(int *a,int head,int tail)
{
    int length = tail - head + 1;
    
    /* 设置步长 */
    int d = 1;
    while(d < length / 3)
        d = 3*d + 1;
    while(d >= 1)
    {
        for(int i = head;i < tail;i++)
        {
            for(int j = i+d;j <= tail;j += d)
            {
                if(a[j] < a[i])
                {
                    int temp = a[j];
                    for(int k = j;k >= i;k -= d)
                        a[k] = a[k-d];
                    a[i] = temp;
                }
            }
        }
        d /=  2;
    }
}
int main()
{

    //int a[5] = {3,1,5,2,4};
    int a[100] = {0};
    
    for(int i = 0;i < 100;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%100;
    }
    printf("\n原始数据:\n");
    Print(a,100);
    
    ShellSort(a,0,99);


    printf("\n排序后数据:");
    Print(a,100);
    printf("\n");
}
