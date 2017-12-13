/*************************************************************************
	> File Name: hash_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 11时44分49秒
 ************************************************************************/
/* 
    hash列地址法:
    为了更快的查找数据，所以在存储数据的时候按照一定规则存储。
    本方法使用列地址法
    下面介绍一下本程序的列地址法：
    1.准备5个列表，将5个列表的头节点地址放入指针数组中。
    2.存储数据(这里的数据均为正整数)时,该数据与5取余，假设取余的结果为k，则该数据插入到第k个列表中
  
  
  
  */

#include<stdio.h>
#include<stdlib.h>
#define DataType int
typedef struct node //链表中的结点
{
    DataType data;
    struct node *next;
}Node,*pNode;
//创建一个列表，返回指向头节点的指针,头节点不用来存储数据
pNode HeadCreate() 
{
    pNode p = (pNode)malloc(sizeof(Node));
    p->next = NULL;
    return p;
}
void InsertByHead(pNode list,DataType data)//头插,即插入到头节点的下一个
{
    if(NULL == list)
    {
        printf("不存在该链表!\n");
        return;
    }
    pNode p = (pNode)malloc(sizeof(Node));
    p->next = NULL;
    p->data = data;
    
    p->next = list->next;
    list->next = p;
    
}
//打印某链表
void Print(pNode list) 
{
    if(NULL == list)
    {
        printf("不存在该链表!\n");
        return;
    }
    //assert(NULL != list);
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
// Hash 列地址法存储数据
void* Hash()
{
    pNode arry[5];
    Node *(*p)[] = (Node *(*)[])malloc(sizeof(pNode)*5);
    for(int i = 0;i < 5;i ++)
    {
        arry[i] = HeadCreate();
    }
    int num;
    for(int i = 0;i < 10;i++)
    {
        printf("第%d个:",i+1);
        scanf("%d",&num);
        int key = num%5;
        InsertByHead(arry[key],num);
    }
    for(int i = 0;i < 5; i++)
    {
        printf("第%d个列表：",i+1);
        Print(arry[i]);
        putchar(10);
    }
    return p; //返回指向数组的指针，该数组里存放的是结构体指针

}


int main()
{
    Node *(*p)[] = (Node *(*)[])Hash();
    return 0;
}
