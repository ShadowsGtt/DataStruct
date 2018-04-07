#include "tree.h"
/* 
* 根据二叉树的先序遍历和中序遍历恢复二叉树
* */

/* i,j,k,h分别是当前子树先序序列和中序序列的下，上界 */
void Pre_In_order(const char pred[],const char ind[],\
                 int i,int j,int k,int h,BTnode **p)
{
    int m;

    *p = (BTnode *)malloc(sizeof(BTnode));
    (*p)->value = pred[i];
    (*p)->lchild = NULL;
    (*p)->rchild = NULL;
    m = k;
    while(ind[m] != pred[i])
        m++;
    if(m == k)
        (*p)->lchild = NULL;
    else
        Pre_In_order(pred,ind,i+1,i+m-k,k,m-1,&(*p)->lchild);

    if(m == h)
        (*p)->rchild = NULL;
    else
        Pre_In_order(pred,ind,i+m-k+1,j,m+1,h,&(*p)->rchild);
}

int main()
{
    char pred[] = "ACBGDEHFJI";
    char ind[] = "CGBAHEDJFI";
    BTnode *p;
    Pre_In_order(pred,ind,0,9,0,9,&p);

    printf("先序遍历:\n");
    pre_order(p,10);

    printf("中序遍历:\n");
    in_order(p,10);
    
    printf("后序遍历:\n");
    post_order(p,10);

    printf("层次遍历:\n");
    Transleve(p,10);
    BTnode *res = FindData(p,10,'I');
    putchar(10);
    if(NULL == res)
        printf("not found\n");
    else
        printf("found:%c\n",res->value);
    putchar(10);
}

