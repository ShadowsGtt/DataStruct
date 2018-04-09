#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<assert.h>
#define DataType int

typedef struct AVLTnode
{
    int             bf;      //平衡因子(bf = 左树高度 - 右树高度)
    DataType        data;
    struct AVLTnode *lchild;
    struct AVLTnode *rchild;
}AVLTnode;

int main()
{

}
