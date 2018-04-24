/* 两个队列实现一个栈 */

/* 想法：出栈时，队列1只留下一个元素
*       其余元素全部移到队列2中
*       出栈的元素即是队列1里的元素
*       */
#include<stdio.h>

typedef struct Queue
{
    //int count;
    int rear;
    int front;
    int queue[100];
}Queue_t;

void Push(Queue_t *q1,Queue_t *q2,int data)
{
    while(q2->rear > q2->front)
        q1->queue[++(q1->rear)] = q2->queue[++(q2->front)];
    q1->queue[++(q1->rear)] = data;
    
    printf("%d  入栈\n",q1->queue[q1->rear]);
}

int Pop(Queue_t *q1,Queue_t *q2)
{
    
    while(q2->rear > q2->front)
        q1->queue[++(q1->rear)] = q2->queue[++(q2->front)];
    while(q1->front+1 < q1->rear)
        q2->queue[++(q2->rear)] = q1->queue[++(q1->front)];
    if(q1->front == q1->rear)
    {
        printf("empty stack\n");
        return -1;
    }

    printf("%d   出栈\n",q1->queue[q1->front + 1]);
    return q1->queue[++(q1->front)];
}

int main()
{
    Queue_t que1,que2;
    que1.rear = que1.front = 0;
    que2.rear = que2.front = 0;

    Push(&que1,&que2,4);
    Push(&que1,&que2,7);
    Push(&que1,&que2,3);
    Push(&que1,&que2,6);

    Pop(&que1,&que2);


    Push(&que1,&que2,9);


    Pop(&que1,&que2);
    Pop(&que1,&que2);
    Pop(&que1,&que2);
    Pop(&que1,&que2);
    Pop(&que1,&que2);
    //que2.count = que1.count = 0;

}
