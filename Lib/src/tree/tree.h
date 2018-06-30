
#ifndef _TREE_H
#define _TREE_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<assert.h>
#define ValueType char
#define MAXSIZE 50

/* 树的节点 */
typedef struct BTnode
{
    ValueType      value;
    struct BTnode  *lchild;
    struct BTnode  *rchild;
}BTnode;

/* 先序遍历 */
extern void pre_order(BTnode *);

/* 先序遍历 */
extern void in_order(BTnode *);

/* 先序遍历 */
extern void post_order(BTnode *);

/* 层次遍历 */
extern void Transleve(BTnode *,int);

/* 计算树中叶子节点的数目 */
extern int GetLeavesCounts2(BTnode *);
extern int GetLeavesCounts1(BTnode *);

/* 根据先序遍历和中序遍历恢复二叉树 */
void Pre_In_order(const char pred[],const char ind[],\
        int i,int j,int k,int h,BTnode **p);

/* 在二叉树中寻找某个元素 */
extern BTnode *FindData(BTnode *root,unsigned count,ValueType value);


/*
 * 层次遍历需要的函数声明 
 *
 * */
typedef BTnode *DataType;

/* 一个队列的定义 */
typedef struct
{
    int front;
    int rear;
    unsigned capacity;
    unsigned count;
    DataType data[];
}Queue;

/* 创建一个队列 */
extern Queue *CreateQueue(unsigned);
/* 入队 */
extern void EnQueue(Queue *p, DataType data);
/* 出队 */
extern DataType DeQueue(Queue *p);
#endif
