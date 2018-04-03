
#ifndef _TREE_H
#define _TREE_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define DataType char
#define MAXSIZE 50
typedef struct BTree
{
    DataType      value;
    struct BTree  *lchild;
    struct BTree  *rchild;
}BTree;
extern void pre_order(BTree *,int);
extern void in_order(BTree *,int);
extern void post_order(BTree *,int);

/* 根据先序遍历和中序遍历恢复二叉树 */
void Pre_In_order(const char pred[],const char ind[],\
        int i,int j,int k,int h,BTree **p);
#endif
