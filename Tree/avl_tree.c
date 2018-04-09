#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<assert.h>
#define ValueType int

typedef struct AVLTnode AVLTnode;
typedef struct AVLTree  AVLTree;

/* 创建一颗空AVL树 */
AVLTree *CreateAVLTree();


struct AVLTnode
{
    int             bf;      //平衡因子
    ValueType       value;
    struct AVLTnode *lchild;
    struct AVLTnode *rchild;
};

struct AVLTree
{
    unsigned    count;      //已有节点数目
    AVLTnode    *root;      //根节点地址
    unsigned    high ;      //树的高度
    
};

AVLTree *CreateAVLTree()
{
    AVLTree *p = (AVLTree *)malloc(sizeof(AVLTree));
    if(NULL == p)
        return NULL;
    p->root  = NULL;
    p->count = 0;
    p->high  = 0;
    
    return p;
}

/* 右旋
 * @root:以root为根的节点进行右旋
 * 
 * 右旋即是将根降为根的左孩子的右孩子
 * */
void R_Rotate(AVLTnode **root)
{
    AVLTnode *temp = NULL;

    temp = (*root)->lchild;
    (*root)->lchild = temp->rchild;
    temp->rchild = (*root);
    *root = temp;
}

/* 左旋
 * @root:以root为根的节点进行左旋
 * 
 * 左旋即是将根降为根的右孩子的左孩子
 * */
void L_Rotate(AVLTnode **root)
{
    AVLTnode *temp = NULL;

    temp = (*root)->rchild;
    (*root)->rchild = temp->lchild;
    temp->lchild = (*root);
    *root = temp;
}


int main()
{

}
