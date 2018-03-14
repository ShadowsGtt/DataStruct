

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5  //线性表最大容量
#define DataType int

typedef struct 
{
    int len;   //线性表最大容量，指向线性表最后一个元素
    DataType data[0];
}SeqList;

//创建一个线性表  传入长度Len
SeqList * CreateSqlList()  
{
    SeqList *p = (SeqList *)malloc(sizeof(SeqList) + sizeof(DataType)*MAXSIZE);
    p->len = 0;
    return p;
}


//向线性表中插入元素 posi 为插入的位置
void Insert(SeqList *p,DataType data,int posi)
{
    
    if(posi > p->len+1 || posi < 1)  //错误的位置
    {
        printf("error position!\n");
        return ;
    }
    if(posi == MAXSIZE-1)
    {
        printf("list has been full\n");
        return ;
    }
    for(int j = p->len + 1;j > posi;j--)
    {
        p->data[j] = p->data[j-1];
    }
    p->data[posi] = data;
    p->len++;
}

//删除第posi个位置的元素
void Delete(SeqList *p,int posi)  
{
    if(posi > p->len || posi < 1)
    {
        printf("error position!\n");
        return ;
    }
    if(p->len == 0)
    {
        printf("empty list!\n");
        return ;
    }
    for(int j = posi;j <= p->len;j++)
    {
        p->data[j] = p->data[j+1];
    }
    p->len--;
}

void TurnRound(SeqList *p)
{
    DataType temp;
    int j = p->len;
    for(int i = 1;i < j;i++,j--)
    {
        temp = p->data[j];
        p->data[j] = p->data[i];
        p->data[i] = temp;
    }
    printf("\n线性表已成功逆置!\n");
}

//查找线性表中的元素，返回该元素下标
int FindData(SeqList *p,DataType data)
{
    for(int i = 1;i <= p->len;i++)
    {
        if(p->data[i] == data)
            return i;
    }
    printf("未查找到该元素!\n");
    return 0;
}

//打印线性表
void Print(SeqList *p)
{
    for(int i = 1;i <= p->len;i++)
        printf("%-3d",p->data[i]);
}
int main()
{
    SeqList *a = CreateSqlList();
    Insert(a,11,1);
    printf("\n插入第1个元素到第一个位置后\n");
    Print(a);
    Insert(a,1,2);
    printf("\n插入第2个元素到第二个位置后\n");
    Print(a);
    Insert(a,2,2);
    printf("\n插入第3个元素到第二个位置后\n");
    Print(a);
    TurnRound(a);
    //Delete(a,1);
    //printf("\n删除第1位置后\n");
    Print(a);
    printf("该元素下标为：%d\n",FindData(a,2));
    return 0;
}
