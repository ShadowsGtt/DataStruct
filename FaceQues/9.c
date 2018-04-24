
/* 两个栈实现一个队列 */
#include<stdio.h>

int stack1[20];
int stack2[20];
int index1;
int index2;

void EnQue(int number)
{
    if( 0 != index2)
    {
        while(index2 > 0)
            stack1[++index1] = stack2[index2--];
    }
        stack1[++index1] = number;
    printf("%d  已入队\n",stack1[index1]);

}
int DeQue()
{
    if(0 == index1 && 0 == index2)
    {
        printf("empty queue\n");
        return -1;
    }
    while(index1 > 0)
        stack2[++index2] = stack1[index1--];
    printf("%d  已出队\n",stack2[index2]);
    return stack2[index2--];
}

void test()
{
    EnQue(6);
    EnQue(4);
    EnQue(2);
    EnQue(5);

    DeQue();
    
    EnQue(7);

    DeQue();
    DeQue();
    DeQue();
    DeQue();
    DeQue();

}


int main()
{
    test();
}
