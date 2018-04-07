#include "tree.h"

int GetHigh(BTnode *root)
{
    BTnode *cur = root;
    
    if(NULL == cur)
        return 0;
    else
    {
        int lhigh = GetHigh(cur->lchild);
        int rhigh = GetHigh(cur->rchild);
        return lhigh>rhigh?lhigh:rhigh;
    }
}

