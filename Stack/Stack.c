
#include<stdlib.h>
#include<stdio.h>
#define DataType int 

typedef struct 
{
    int top;
    DataType data[0];
}Stack;

//创建栈
Stack * CreatStack(int n)  
{
    if(n <= 0)
    {
        printf("请输入正确的栈大小!\n");
    }
    Stack *p = (Stack *)malloc(sizeof(Stack) + sizeof(DataType)*n );
    p->top = -1;
    return p;
}

void PushStack(Stack *p,DataType data)
{
    (p->top)++;
    p->data[p->top] = data;
}

DataType PopStack(Stack *p)
{
    return (p->data[(p->top)--]);
}

void LookStackTop(Stack *p)
{
    printf("stack top:%d\n",p->data[p->top]);
}

void Print(Stack *p)
{
    if(p->top == -1)
    {
        printf("empty stack\n");
        return ;
    }
    int i = p->top;
    while(i > -1)
    {
        printf("---->%d\n",p->data[i--]);
    }
}

int main()
{
    Stack *a = CreatStack(5); //创建大小为5的栈
    PushStack(a,5);
    PushStack(a,4);
    PushStack(a,3);
    PushStack(a,2);
    PushStack(a,1);
    Print(a);
    PopStack(a);
    PopStack(a);
    Print(a);
    LookStackTop(a);
    return 0;
}
