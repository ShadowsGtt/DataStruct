#include "tree.h"

/*

              A
            /    \
           C      D  
            \    /  \ 
             B  E    F
            /  /    / \
           G  H    J   I
*/
           
BTnode *ExampleTree()
{
    char pred[] = "ACBGDEHFJI";
    char ind[] = "CGBAHEDJFI";
    BTnode *p = NULL; 
    Pre_In_order(pred,ind,0,9,0,9,&p);
    return p;
}

