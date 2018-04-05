#include "tree.h"

/* 
 * 在二叉树中查找指定元素
*  成功返回该节点地址
*  失败返回空地值
*  @root:根节点地址
*  @count:二叉树大小
*  @value:要查找的元素值
*
*  */
BTree *FindData(BTree *root,unsigned count,ValueType value)
{
    assert(NULL != root);
    assert(0 != count);

    BTree *stack[count];
    int i = -1;    //栈顶下标
    BTree *cur = root;

    while(NULL != cur || i >= 0)
    {
        if(NULL != cur)
        {
            if(cur->value == value)
                return cur;
            stack[++i] = cur;
            cur = cur->lchild;
        }
        else
        {
            cur = stack[i--];
            cur = cur->rchild;
        }
    }
    return NULL;
}
