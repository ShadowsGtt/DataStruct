#include<stdio.h>

/* @BITMAP:创建一个位图
*  @BIT_SET:设置位图中标记位
*  @BIT_CLR:清除位图中标记位
*  @BIT_ISSET:检测位图中标记位
*  */

typedef int BITMAP[9999];
#define BIT_ZERO(a)                                     \
        do{                                             \
            for(int i = 0;i < 9999;i++)                 \
                *(a+i)=0;                               \
        }while(0)              

#define BIT_SET(a,x)                                    \
        do{                                             \
            *(a+x/32) |= (1<< (x%32) );                 \
        }while(0)              

#define BIT_ISSET(a,x)  ( (*(a+x/32)&=(1<< (x%32) )))

#define BIT_CLR(a,x)                                    \
        do{                                             \
            *(a+x/32) &=~(1<<(x%32));                   \
          }while(0)

int main()                                                      
{
    BITMAP a;
    BIT_ZERO(a);
    BIT_SET(a,110);
    if(BIT_ISSET(a,110))
        printf("set\n");
    else
        printf("not set\n");
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
}                                                                           
