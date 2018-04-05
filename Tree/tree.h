
#ifndef _TREE_H
#define _TREE_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<assert.h>
#define ValueType char
#define MAXSIZE 50
typedef struct BTree
{
    ValueType      value;
    struct BTree  *lchild;
    struct BTree  *rchild;
}BTree;
extern void pre_order(BTree *,int);
extern void in_order(BTree *,int);
extern void post_order(BTree *,int);
extern void Transleve(BTree *,int);
/* 计算树中叶子节点的数目 */
extern int GetLeavesCounts2(BTree *);
extern int GetLeavesCounts1(BTree *);

/* 根据先序遍历和中序遍历恢复二叉树 */
void Pre_In_order(const char pred[],const char ind[],\
        int i,int j,int k,int h,BTree **p);


extern BTree *FindData(BTree *root,unsigned count,ValueType value);
/* 层次遍历需要的函数声明 */

typedef BTree *DataType;
typedef struct
{
    int front;
    int rear;
    unsigned capacity;
    unsigned count;
    DataType data[];
}Queue;
extern Queue *CreateQueue(unsigned);
extern void EnQueue(Queue *p, DataType data);
extern DataType DeQueue(Queue *p);
#endif
