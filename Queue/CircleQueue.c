/*************************************************************************
	> File Name: Queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时24分05秒
 ************************************************************************/
/*
关于循环队列为什么要多余开辟一个队列元素的空间的解释:
回想一下如果没有多余开辟一个空间
那么开始时,rear=0,front=-1 
队列满的情况有两种:
(1) (rear+1)%(队列大小) == front
(2) 当队列顺序填满时,将第一个进入队列的元素出队,如果此时在入队一个元素
那么此时队列也是满的,这时候判断队列满的条件就成了 front ==rear+1 
这与刚创建一个队列时候队列为空(rear == -1 ,front == 0,所以front == rear+1)的条件冲突
所以必须要牺牲一个元素的空间,让front 指向队列第一个元素的前一个位置
*/

#include "Queue.h"
Queue *CreateCircleQueue(int capacity)       //创建队列,返回指向该队列的结构体指针
{
    Queue *p = (Queue *)malloc(sizeof(Queue)+sizeof(DataType)*(capacity+1));  //多余开辟一个元素的空间,由于判断队满和队空会出现冲突
    p->rear = 0;
    p->front = 0;
    p->capacity = capacity+1;      //整个队列的容量也+1
    return p;
}
int CircleQueueIsFull(Queue *p)      //判断队列是否已满
{
    if(((p->front)-1 == p->rear) || (p->rear+1)%(p->capacity) == p->front )
        return 1;
    return 0;
}
int CircleQueueIsEmpty(Queue *p)     //判断队列是否为空 返回1为空
{
    if(p->rear == p->front)  
        return 1;
    return 0;
}
void EnCircleQueue(Queue *p,DataType data)    //向队列中添加元素
{
    if(CircleQueueIsFull(p))      //如果队列已满
    {
        printf("the queue is full!\n");
        return ;
    }
    p->rear = (++(p->rear))%(p->capacity);
    p->data[p->rear] = data;
}
DataType DeCiecleQueue(Queue *p)
{
    if(CircleQueueIsEmpty(p))       //如果队列为空
    {
        printf("the queue is empty!\n");
        return 0;
    }
    p->front = ++(p->front)%(p->capacity);       
    return p->data[p->front];
}

/* 删除队列 */
void DropQueue(Queue *p)
{
    free(p);
    p = NULL;
}
int main()
{

    return 0;
}
