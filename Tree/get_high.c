#include "tree.h"

int GetHigh(BTree *root)
{
    BTree *cur = root;
    
    if(NULL == cur)
        return 0;
    else
    {
        int lhigh = GetHigh(cur->lchild);
        int rhigh = GetHigh(cur->rchild);
        return lhigh>rhigh?lhigh:rhigh;
    }
}

