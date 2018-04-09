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
    BTnode *root;        //根节点地址
    unsigned count;     //BST已有节点个数
    unsigned high;      //树的高度
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

    BTnode *cur = bst->root;
    BTnode *pre = NULL;

    while(1) 
    {
        /* 如果BST目前是空 */
        if(NULL == bst->root)
        {
            BTnode *newnode = (BTnode *)malloc((sizeof(BTnode)));   
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
                BTnode *newnode = (BTnode *)malloc((sizeof(BTnode)));   
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
                BTnode *newnode = (BTnode *)malloc((sizeof(BTnode)));   
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

/* 从BST树中删除一个节点 
 * 成功:返回0
 * 失败:返回-1
 * @bst:要操作的BST树
 * @value:要删除的节点值
 *
 * */
int DeleteFromBST(BSTree *bst,ValueType value)
{
    /* 一颗空树 */
    if(NULL == bst)
        return -1;
    BTnode **cur = NULL;
    BTnode *temp = NULL;

    cur = &bst->root;
    
    /* 让*cur先指向删除的节点 */
    while((*cur)->value != value)
    {
        if((*cur)->value > value)
            cur = &(*cur)->lchild;
        if((*cur)->value < value)
            cur = &(*cur)->rchild;
        
        /* 未找到要删除的节点 */
        if(NULL == (*cur) )
            return -1;
    }

    /* 如果要删除的节点没有左孩子,也没有右孩子 */
    if( NULL == (*cur)->lchild && NULL == (*cur)->rchild )
    {
        free(*cur);
        *cur = NULL;
    }

    /* 如果要删除的节点没有左孩子,但有右孩子 */
    else if( NULL == (*cur)->lchild && NULL != (*cur)->rchild )
    {
        temp = *cur;
        *cur = (*cur)->rchild;
        free(temp);
        temp = NULL;
    }

    /* 如果要删除的节点没有右孩子,但有左孩子 */
    else if( NULL == (*cur)->rchild && NULL != (*cur)->lchild )
    {
        temp = *cur;
        *cur = (*cur)->lchild;
        free(temp);
        temp = NULL;
    }

    /* 如果要删除的节点既有左孩子,又有右孩子 */
    else
    {
        BTnode *minNode = NULL;
        minNode = (*cur)->rchild;
        while(minNode->lchild != NULL)
            minNode =  minNode->lchild;
        if(NULL == (*cur)->rchild->lchild && NULL == (*cur)->rchild->rchild )
        {
            minNode->lchild = (*cur)->lchild;
            free(*cur);
            (*cur) = minNode;
        }
        else
        {
            (*cur)->rchild->lchild = minNode->rchild;
            minNode->lchild = (*cur)->lchild;
            minNode->rchild = (*cur)->rchild;
            free(*cur);
            (*cur) = minNode;
        }
    }
    return 0;
}


int main()
{
    BSTree *tree = CreateBST();
    InsertIntoBST(tree,'m');
    InsertIntoBST(tree,'e');
    InsertIntoBST(tree,'d');
    InsertIntoBST(tree,'h');
    InsertIntoBST(tree,'p');
    InsertIntoBST(tree,'f');
    InsertIntoBST(tree,'o');
    printf("count:%d\n",tree->count);

    pre_order(tree->root,tree->count);
    in_order(tree->root,tree->count);
    
    printf("leaf count1:%d\n",GetLeavesCounts1(tree->root));
    printf("leaf count2:%d\n",GetLeavesCounts2(tree->root));


    printf("delete node:'e'\n");
    DeleteFromBST(tree,'e');
    pre_order(tree->root,tree->count);
    in_order(tree->root,tree->count);
    printf("leaf count1:%d\n",GetLeavesCounts1(tree->root));
    printf("leaf count2:%d\n",GetLeavesCounts2(tree->root));
    
    printf("delete node:'h'\n");
    DeleteFromBST(tree,'h');
    pre_order(tree->root,tree->count);
    in_order(tree->root,tree->count);
    printf("leaf count1:%d\n",GetLeavesCounts1(tree->root));
    printf("leaf count2:%d\n",GetLeavesCounts2(tree->root));
}
