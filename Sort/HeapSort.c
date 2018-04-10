 #include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*
* 堆排序:
*
* (一).堆介绍:
*       <1>.堆是一颗完全二叉树,堆分为两种:
*               1.大根堆:双亲节点值 >= 两个孩子节点值
*               2.小根堆:双亲节点值 <= 两个孩子节点值
*       <2>.双亲节点的下标 = i ,且此堆从数组下标为1的开始位置存储,则： 
*               1.左孩子下标 = 2*i 
*               2.右孩子下标 = 2*i+1 
*       <3>.最后一个双亲节点的下标值为n/2 (n为堆的大小,即数组元素个数)
*           下标在[1,n/2]区间内的都是非叶子几点
*           下表在[n/2+1,n]区间内的都是叶子几点
* (二).堆排序实现:
*       大概可以分为两个步骤
*       <1>.建立初始堆 
*       <2>.堆顶元素交换到最后,调整堆顶
*
*       建立初始堆:
*           从最后一个双亲节点开始,对每一个最小堆(即只有三个元素的堆)
*           进行调整,将最小堆中最小的元素交换到根,然后记录因上一次交换
*           而受到影响的元素下标,然后对这个最小堆进行调整,直到遇到没有
*           元素受影响,或者所有最小堆都已经调整.
*           
*
* */
void Print(int *a,int length)
{
    putchar(10);
    int i = 0;
    for(i = 1 ;i <= length;i++)
    {
        printf("%-4d",a[i]);
        if(i%11 == 0)
            putchar(10);
    }
    putchar(10);
    return;
}
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


/* 下标从1开始的数组进行堆排序 
 * @a：数组a
 * @root:要调整的最小堆的根节点下标
 * @n:数组的大小*/
void AdjustToSmallHeap(int *a,int root,int n)
{
    if(NULL == a || 0 == n || root > n)
        return;
    
    int key = -1;
    //沿着关键字较小的孩子继续向下调整
    //开始假定为左孩子
    for(int i = root;i <= n;)
    {
        key = i*2; //从左孩子开始
        if(key <= n)
        {
            if(key + 1 <= n && a[key] > a[key+1])
            {
                key = key + 1;
                if(a[key] < a[i])
                {
                    Swap(&a[key],&a[i]);
                    i = key; 
                    continue;
                }
            }
            if(a[key] < a[i])
            {
                Swap(&a[key],&a[i]);
                i = key;
                continue;
            }
        }
        break;
    }
}
void AdjustToBigHeap(int *a,int root,int n)
{
    if(NULL == a || 0 == n || root > n)
        return;
    
    int key = -1;
    //沿着关键字较大的孩子继续向下调整
    //开始假定为左孩子
    for(int i = root;i <= n;)
    {
        key = i*2; //从左孩子开始
        if(key <= n)
        {
            /* 如果有右孩子并且右孩子>左孩子 */
            if(key + 1 <= n && a[key] < a[key+1])
            {
                key = key + 1;
                if(a[key] > a[i])
                {
                    Swap(&a[key],&a[i]);

                    /* 受影响的节点继续调整 */
                    i = key; 
                    continue;
                }
            }
            if(a[key] > a[i])
            {
                Swap(&a[key],&a[i]);

                /* 受影响的节点继续调整 */
                i = key;
                continue;
            }
        }
        /* 没有节点受影响,则结束 */
        break;
    }
}

/* 调整小根堆 */
void HeapSort1(int *a,int n)
{
    /* 建立初始堆 */
    for(int i = n/2;i >= 1;i--)
        AdjustToSmallHeap(a,i,n);

    printf("\n建立初始堆:");
    Print(a,n);
    /* 交换调整 */
    for(int i = n;i > 1;i-- )
    {
        Swap(&a[i],&a[1]);
        AdjustToSmallHeap(a,1,i-1);
    }
}

/* 调整成大根堆 */
void HeapSort2(int *a,int n)
{
    /* 建立初始堆 */
    for(int i = n/2;i >= 1;i--)
        AdjustToBigHeap(a,i,n);

    printf("\n建立初始堆:");
    Print(a,n);
    
    /* 堆顶元素交换到最后
     * 然后调整堆
     * */
    for(int i = n;i > 1;i-- )
    {
        Swap(&a[i],&a[1]);
        AdjustToBigHeap(a,1,i-1);
    }
}

int main()
{
#if 1
    int a[110] = {0};
    for(int i = 1;i < 110;i++)
    {
        srand(i*time(NULL));
        a[i] = rand()%500;
    }
#endif
    //int a[] = {0,20,50,10,30,70,20,80};
    //int a[] = {0,113,271,335,129,103,206,156,482,376,304};
    int length = sizeof(a) / sizeof(int) - 1;
    //int length = sizeof(a) / sizeof(int) ;
    
    printf("\n原始数组:\n");
    Print(a,length);

    HeapSort1(a,length);

    printf("\n最终排序结果:\n");
    Print(a,length);

    printf("\n原始数组:\n");
    Print(a,length);

    HeapSort2(a,length);

    printf("\n最终排序结果:\n");
    Print(a,length);
    putchar(10);
    return 0;
    
}
