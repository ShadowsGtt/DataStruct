
#ifndef _QUEUE_H
#define _QUEUE_H
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include <math.h>
#define DataType int
typedef struct queue
{
    unsigned capacity;      //队列的大小(容量)
    
    /* 循环队列中:front指向队头元素前一个,rear指向队尾*/
    int front,rear;    
    unsigned count;         //队列现存元素 
    DataType data[0];       //动态数组存放队列元素
}Queue;

/* 创建指定大小的循环队列,返回指向该队列结构的指针 */
extern Queue *CreateCircleQueue(int);  

 /* 判断队列是否已满 */
extern int CircleQueueIsFull(Queue *);

/* 判断循环队列是否为空 */
extern int CircleQueueIsEmpty(Queue *);

/* 元素入队 */
extern void EnCircleQueue(Queue *p,DataType data);    

/* 元素出队 */
extern DataType DeCiecleQueue(Queue *p);

/* 删除队列 */
extern void DropQueue(Queue *);

extern Queue *CreateSingalQueue(int);

extern void EnSingalQueue(Queue *,DataType);

extern DataType DeSingalQueue(Queue*);

extern void FreeQueue(Queue *);

#endif
