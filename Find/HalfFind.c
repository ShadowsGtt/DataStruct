#include<stdio.h>
#include<unistd.h>

/* 前提条件:有序集合 */



int HalfFind(int *a ,int length,int aim)
{
    int head,tail,mid;
    int count = 0;
    int index = -1;

    head = 0;
    tail = length -1;

    while(head <= tail)
    {
        count++;
        mid = (head + tail)/2;
        if(a[mid] == aim){
            index = mid;
            break;
        }
        else if(aim > a[mid])
            head = mid + 1;
        else if(aim < a[mid])
            tail = mid - 1;
    }
    printf("查找次数:%d\n",count);
    return index;
}



int main()
{
    int a[100] = {0};
    for(int i = 0; i < 100;i++)
        a[i] = i+1;
    printf("下标:%d\n",HalfFind(a,100,10));
    return 0;
}
