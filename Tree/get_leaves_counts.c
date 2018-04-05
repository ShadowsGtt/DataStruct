#include "tree.h"

/* 计算树中叶子节点的数目 
* @root:树的根节点
* 返回值：叶子节点的数目*/

/* 递归写法 */
int GetLeavesCounts1(BTree *root)
{
    //assert(NULL != root);
    BTree *cur = root;

    if(NULL == cur)
        return 0;
    if(NULL == cur->lchild && NULL == cur->rchild)
        return 1;
    return GetLeavesCounts1(cur->lchild)+GetLeavesCounts1(cur->rchild);
}

int GetLeavesCounts2(BTree *root)
{
    assert(NULL != root);
    BTree *cur = root;
    BTree *stack[100];
    int i = 0;
    int count = 0;

    do
    {
        if(NULL != cur)
        {
            stack[++i] = cur;
            if(NULL == cur->lchild && NULL == cur->rchild)
                count++;
            cur = cur->lchild;
        }
        else
        {
            cur = stack[i--];
            cur = cur->rchild;
        }
    }while(i > 0);

    return count;
    
}
