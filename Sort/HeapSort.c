 #include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*
* 堆排序(本节的堆是用数组来存储):
*
* (一).堆介绍:
*       <1>.堆是一颗完全二叉树,堆分为两种:
*               1.大根堆:双亲节点值 >= 两个孩子节点值
*               2.小根堆:双亲节点值 <= 两个孩子节点值
*       <2>.双亲节点的下标 = i ,且此堆从数组下标为0的开始位置存储,则： 
*               1.左孩子下标 = 2*i+1 
*               2.右孩子下标 = 2*i+2 
*       <3>.最后一个双亲节点的下表值为n/2 (n为堆的大小,即数组元素个数)
*           下标在[0,n/2-1]区间内的都是非叶子几点
*           下表在[n/2,n]区间内的都是叶子几点
* (二).堆排序实现:
*       (*)最重要的工作:调整堆,将数组调整成堆
*       <1>.
*           
*
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
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


/*
* tail : 最后一个双亲节点的下标值
* n:堆节点的个数
* */
void AdjustToBigHeap(int *a,int tail,int n)  
{
    int key;  //正在调整的元素下表

    /* 从最后一个双亲节点的左孩子开始 */
    for(key = tail*2+1;key <= n;key = 2*key + 1)
    {
        int parent = (key+1)/2 - 1;
        if(key < n)
        {
            if(a[key] > a[key+1])
                key = key + 1;     //左孩子比右孩子大,则右孩子和双亲比较即可
            if(a[key] > a[parent] )  //当孩子比父亲节点大
                break;
            else
                Swap(&a[key],&a[parent]);

        }
    }
}

void AdjustToSmallHeap(int *a,int tail,int n)  
{
    int key;  //正在调整的元素下表

    /* 从最后一个双亲节点的左孩子开始 */
    for(key = tail*2+1;key <= n;key = 2*key + 1)
    {
        int parent = (key+1)/2 - 1;
        if(key < n)
        {
            if(a[key] > a[key+1])
                key = key + 1;     //左孩子比右孩子大,则右孩子和双亲比较即可
            if(a[key] > a[parent] )  //当孩子比父亲节点大
                break;
            else
                Swap(&a[key],&a[parent]);

        }
    }
}

void HeapSort(int *a,int n )
{
    /* 构建初始堆 */
    for(int i = n/2-1;i >= 0 ; i--)
        AdjustToBigHeap(a,i,n);
    printf("\n调整:\n");
    Print(a,n);
    for(int i = n - 1;i > 0;i--)
    {
        Swap(&a[0],&a[i]);
        AdjustToBigHeap(a,0,i-1);
    }
}
int main()
{
    int a[150] = {0};
    for(int i = 0;i < 150;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%500;
    }
    //int a[] = {20,50,10,30,70,20,80};
    int length = sizeof(a) / sizeof(int);
    
    printf("\n原始数组:\n");
    Print(a,length);

    HeapSort(a,length);

    printf("\n最终排序结果:\n");
    Print(a,length);

    return 0;
    
}
