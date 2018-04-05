#include "Queue.h"

/* 创建一个单向队列 */
Queue *CreatSingalQueue(int count)
{
    if(0 == count)
        return NULL;
    Queue *p = (Queue *)malloc(sizeof(Queue) + count*sizeof(DataType));
    assert(NULL != p);

    /* init */
    p->capacity = 0;
    p->count = 0;
    p->front = -1;
    p->rear = -1;


    p->capacity = count;
    return p;
}

void EnSingalQueue(Queue *p, DataType data)
{
    p->data[++(p->rear)] = data;
    if(0 == p->count)
        p->front++;
    p->count++;
}

DataType DeSingalQueue(Queue *p)
{
    if(0 == p->count)
    {
        fprintf(stderr,"empty queue\r\n");
        return -2147483648;
    }
    p->count--;
    return (p->data[p->front++]);
}

void FreeQueue(Queue *p)
{
    free(p);
    p = NULL;
}
