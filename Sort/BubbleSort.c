#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define bool int
#define false 0
#define true 1


/* 优化的冒泡算法 */
/*
* 优化方法:对原本有序的数组,不进行排序
* */
void Print(int *,int);


void BubbleSort(int *a,unsigned length)
{
    printf("\n排序前:\n");
    Print(a,length);
    bool flag = true;
    int i ;
    int j;
    int temp;
    int count = 0; //比较的次数

    for(i = 0; i < length -1 && flag ;i++){
        flag = false;
        for(j = i+1;j < length ;j++){
            if(a[j] < a[i]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                count++;
                flag = true;  
            }
        }
    }
    printf("\n\n排序后:");
    Print(a,length);
    printf("\n比较的次数:%d\n",count);

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

int main()
{
    int a[100] = {0};
    for(int i = 0;i < 100;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%500;
    }
    BubbleSort(a,100);
    
}
