#include "BitMap.h"

int main()                                                      
{
    BITMAP a;
    BIT_ZERO(a);


    BIT_SET(a,3);
    BIT_SET(a,2);
    BIT_SET(a,1);

    BIT_CLR(a,2);
    printf("%d\n",a[0]);
#if 0
    for(int i = 0; i < 32;i++)
        //BIT_SET(a,i);
    if(BIT_ISSET(a,4))
        printf("set\n");
    else
        printf("not set\n");
    printf("%u\n",a[0]);
    
#endif
    /*
    
    BIT_CLR(a,110);

    if(BIT_ISSET(a,110))
        printf("set\n");
    else
        printf("not set\n");
    BIT_SET(a,110);

    BIT_ZERO(a);

    if(BIT_ISSET(a,110))
        printf("set\n");
    else
        printf("not set\n");
    */
}

