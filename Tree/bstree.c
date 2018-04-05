#include "tree.h"

/* BST：binary sort tree,二叉排序树
* 定义：对于每一棵树而言
* (1) 若它的左子树非空，则左子树上所有结点(记录)的值均小于根结点的值。
* (2) 若它的右子树非空，则右子树上所有结点的值均大于或等于根结点的值。
* (3) 左、右子树本身又分别是一棵二叉排序树
*
* */
typedef struct
{
    BTree *root;        //根节点地址
    unsigned count;     //BST已有节点个数
    unsigned high;      //树的高度
    unsigned leaf;      //叶子节点数目
}BSTree;


/* 创建一颗二叉排序树 */
BSTree *CreateBST()
{
    BSTree *bst = (BSTree *)malloc(sizeof(BSTree));
    if(NULL == bst)
        return NULL;

    bst->root  = NULL;
    bst->count = 0;
    bst->high  = 0;
    bst->leaf  = 0;

    return bst;
}

/* 向二叉排序树中新插入一个节点 
*  成功：返回0
*  失败：返回-1
*
*  */
int InsertIntoBST(BSTree *bst,ValueType value)
{
    assert(NULL != bst);

    BTree *cur = bst->root;
    BTree *pre = NULL;

    while(1) 
    {
        /* 如果BST目前是空 */
        if(NULL == bst->root)
        {
            BTree *newnode = (BTree *)malloc((sizeof(BTree)));   
            if(NULL == newnode)
                return -1;
            newnode->value = value;
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            bst->root = newnode;
            bst->count++;
            return 0;
        }
        if(value < cur->value)
        {
            pre = cur;
            cur = cur->lchild;
            if(NULL == cur)
            {
                BTree *newnode = (BTree *)malloc((sizeof(BTree)));   
                if(NULL == newnode)
                    return -1;
                newnode->value = value;
                newnode->lchild = NULL;
                newnode->rchild = NULL;
                pre->lchild = newnode;
                bst->count++;
                return 0;
            }
        }
        else if(value >= cur->value)
        {
            pre = cur;
            cur = cur->rchild;
            if(NULL == cur)
            {
                BTree *newnode = (BTree *)malloc((sizeof(BTree)));   
                if(NULL == newnode)
                    return -1;
                newnode->value = value;
                newnode->lchild = NULL;
                newnode->rchild = NULL;
                pre->rchild = newnode;
                bst->count++;
                return 0;
            }
        }
    }
    return -1;
}

int main()
{
    BSTree *tree = CreateBST();
    InsertIntoBST(tree,'e');
    InsertIntoBST(tree,'a');
    InsertIntoBST(tree,'d');
    InsertIntoBST(tree,'b');
    printf("count:%d\n",tree->count);

    pre_order(tree->root,tree->count);
    in_order(tree->root,tree->count);
    
    printf("leaf count1:%d\n",GetLeavesCounts1(tree->root));

    printf("leaf count2:%d\n",GetLeavesCounts2(tree->root));
    
}
