#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#define KeyType int
#define ValueType int
#define MAX_INT 666
#define MIN_INT -666

typedef struct node Node;
typedef struct skip_list skip_list;
void PrintSkipList(skip_list *sl);

//typedef char KeyType[10];
//跳表的每个节点
typedef struct node
{
    KeyType key;            //数据索引
    ValueType value;         //数据值
    struct node *next,*down; //指向平行向后的指针，指向垂直向下的指针
}Node;

//一个跳表的信息 跳表最底层为0层
typedef struct skip_list
{
    unsigned level;    //跳表的总层数
    Node *levelhead[0];  //存放指向每一层头节点指针的可变长数组(使用可变长数组是因为跳表的层数不确定)
}skip_list;

//创建结点的函数
Node *CreateNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = 0;
    //bzero(p->key,sizeof(p->key));
    p->key = 0;
    p->next = NULL;
    p->down = NULL;
    return p;
}

//创建跳表的函数,返回指向跳表结构体的指针
skip_list *CreateSkipList(unsigned level)
{
    //开辟跳表结构体所需的空间
    skip_list *pSL = (skip_list *)malloc(sizeof(skip_list) + level*sizeof(Node*));
    pSL->level =  level;

    Node *tailarry[level];   //存放尾结点的指针数组，函数结束后释放该数组栈空间
    
    //创建每层的头结点和尾节点
    for(int i = level - 1 ;i >= 0;i--)
    {
        pSL->levelhead[i] = CreateNode(); //每层的头结点
        (pSL->levelhead[i])->key = MIN_INT;
        tailarry[i] = CreateNode();   //每层的尾节点
        (tailarry[i])->key = MAX_INT;
    }

    //从最顶层开始，水平连接与竖直连接
    for(int i = level-1;i >= 0;i--)
    {
        pSL->levelhead[i]->next = tailarry[i];
        if(i != 0)
        {
            pSL->levelhead[i]->down = pSL->levelhead[i-1];
            (tailarry[i])->down = tailarry[i-1];
            
        }
    }
    return pSL;
}

//向某跳跃表里插入数据
void Insert(skip_list *sl,int key,ValueType value) 
{
    Node *parry[sl->level];  //存放指向新节点的指针
    srand(time(NULL)+key); //随机化随机函数种子
    int k = rand()%(sl->level); //插入到随机层k
    printf("\nthe level:%d   the key:%d   the value:%d\n",k,key,value);
    //创建k+1个节点，并且填写相关信息
    for(int i = 0;i <= k;i++)
    {
        parry[i] = CreateNode();   
        parry[i]->key = key;
        parry[i]->value = value;
    }
    Node *p;
    for(int i = k; i >= 0;i--)
    {
        p = sl->levelhead[i];  //p指向当前层的头节点
        while( (p->next)->key < key)//将指针移动到第一个大于插入索引节点的前一个结点
            p = p->next;
        if(k != 0)   //非最底层需要横向与纵向连接
        {
            //横向连接
            parry[i]->next = p->next;   
            p->next = parry[i];
            //纵向连接
            parry[i]->down = parry[i-1];
            
        }
        else  //最底层只需要横向连接
        {
            //横向连接
            parry[i]->next = p->next;   
            p->next = parry[i];
        }
        //p指向下一层
        p = p->down;
    }
    printf("after Insert:\n");
    PrintSkipList(sl);
    
}

//根据索引查询，返回数据
ValueType Select(skip_list *sl,KeyType key)
{
    //从最顶层开始查询
    Node *p = sl->levelhead[sl->level-1];
    
    while(1)
    {

        while(p->next->key <= key)
            p = p->next;
        if(p->key == key)
        {
            return p->value;
        }
        else
        {
            if(p->down == NULL)
            {
                //printf("未发现该数据!\n");
                return MAX_INT;
            }
            p = p->down;
        }

    }
}

//删除某节点
void Delete(skip_list *sl,int key)
{
    //如果不存在删除的节点，直接结束
    if(Select(sl,key) == MAX_INT )
    {
        printf("删除错误,不存在该数据!\n");
        return ;
    }
    Node *p = NULL; 
    Node *temp = NULL;   //用来释放要删除节点的空间
    //让p指针指向最高层要删除的节点的前一个节点

    for(int i = sl->level-1; i >= 0;i--)
    {
        Node *p = sl->levelhead[i];
        while(p->next->key < key)
            p = p->next;
        if(p->next->key != key)
            continue;
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
    printf("删除成功!\n");
    
}
//打印某跳跃表
void PrintSkipList(skip_list *sl)
{
    for(int i = (sl->level)-1; i >=0 ;i-- )
    {
        Node *phead = sl->levelhead[i];
        printf("第%d层:",i);
        while(phead != NULL)
        {
            printf("[%d]%d--->",phead->key,phead->value);
            phead = phead->next;
        }
        putchar(10);
    }
}

int main()
{
    skip_list *a = CreateSkipList(4);
    //PrintSkipList(a);
    Insert(a,10,20); 
    Insert(a,18,36); 
    Insert(a,9,18); 
    Insert(a,21,42); 
    Insert(a,3,6); 
    Insert(a,5,10); 
    //PrintSkipList(a);
    printf("查询结果:%d\n",Select(a,5));
    Delete(a,1);
    Delete(a,5);
    PrintSkipList(a);
    return 0;
}
