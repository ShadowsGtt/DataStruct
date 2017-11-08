/*************************************************************************
	> File Name: List.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月08日 星期三 15时22分15秒
 ************************************************************************/
/*带头结点的单向链表*/
#include<stdio.h>
#include<stdlib.h>
#define DataType int
typedef struct node 
{
    DataType data;
    struct node *next;
}Node,*pNode;
pNode HeadCreate()
{
    pNode p = (pNode)malloc(sizeof(Node));
    p->next = NULL;
    return p;
}
void Insert(pNode list,int num,DataType data) //list为插入链表的头节点地址,num 为插入的位置,data 插入的数据
{
    pNode p = (pNode)malloc(sizeof(Node));
    p->next = NULL;
    p->data = data;
    if(NULL == list->next) //如果该链表为空
    {
        list->next = p;
    }
    else //该链表不为空
    {
        for(int i=0;i < num-1;i++) //将list指针移动到要插入位置的前一个位置
        {
            list = list->next;
        }
        if(NULL == list->next) //如果要插入的位置为最后一个位置
        {
            list->next = p;
        }
        else //在中间插入
        {
            p->next = list->next;
            list->next = p;
        }
        
    }
}
void Delect(pNode list,int num) //list 为链表头节点地址，num是删除元素位置
{
    pNode tmp;
    for(int i = 0;i < num-1;i++)
    {
        list = list->next;
    }
    if(NULL == list->next)
    {
        printf("该位置没有元素可以删除\n");
        return ;
    }
    tmp = list->next;
    list->next = tmp->next;
    free(tmp);
}
void Print(pNode list) 
{
    if(NULL == list->next)
    {
        printf("empty list\n");
        return;
    }
    int i = 0;
    while(NULL != list->next)
    {
        list = list->next;
        printf("%d[%d]\t",list->data,++i);
    }
    putchar(10);
    
}
int main()
{
    pNode a = HeadCreate();
    Print(a);
    Delect(a,1);
    Insert(a,1,11);
    Insert(a,1,12);
    Insert(a,1,13);
    Insert(a,1,14);
    Insert(a,5,15);
    Delect(a,1);
    Print(a);

    return 0;
}
