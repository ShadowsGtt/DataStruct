/*************************************************************************
	> File Name: DLlist.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时21分32秒
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#define DataType int
typedef struct dlnode
{
    DataType data;
    struct dlnode *prior;
    struct dlnode *next;
}DLNode,*pDLNode;

pDLNode Create()
{
    pDLNode p = (pDLNode)malloc(sizeof(DLNode));
    p->next = p;
    p->prior = p;
    return p;
}
void Insert(pDLNode list,int num,DataType data)
{
    pDLNode p = (pDLNode)malloc(sizeof(DLNode));
    p->data = data;
    pDLNode head = list;
    for(int i = 0;i < num-1;i++) //指针移动到要插入位置的前一个位置
        list = list->next;
    if(list->next == head) //插入到链表的尾部
    {
        p->next = head;
        p->prior = list;
        head->prior = p;
        list->next = p;
    }
    else  //插入到链表中间
    {
        p->next = list->next;
        p->prior = list;
        (list->next)->prior = p;
        list->next = p;
    }

}
void Print(pDLNode list)
{
    pDLNode head = list;
    if(list->next == head)
    {
        printf("empty list\n");
        return ;
    }
    while((list->next) != head)
    {
        list = list->next;
        printf("%-4d",list->data);
    }
    putchar(10);
}
void Delete(pDLNode list,int num)
{
    if(list == NULL)
    {
        printf("there is not this list\n");
        return ;
    }
    if(list->next == list)
    {
        printf("the list is empty!\n");
        return;
    }
    for(int i = 0;i < num-1;i++) //指针移动到要删除节点的前一个位置
        list = list->next;
    pDLNode tmp = list->next;  //要删除的节点
    pDLNode head = list;
    if((list->next)->next == head)  //如果要删除的节点是最后一个
    {
        list->next = tmp->next;
        head->prior = list;
        free(tmp);
    }
    else    //删除的节点是中间节点
    {
        list->next = tmp->next;
        (tmp->next)->prior = list;
        free(tmp);
    }
}
int main()
{
    pDLNode a = Create();
    Print(a);
    Delete(a,1);
    Insert(a,1,5);
    Insert(a,1,4);
    Insert(a,1,3);
    Insert(a,2,1);
    Insert(a,4,2);
    Delete(a,1);
    Delete(a,4);
    Delete(a,2);
    Print(a);
    return 0;
}
