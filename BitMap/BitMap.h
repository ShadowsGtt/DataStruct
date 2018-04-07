
#ifndef _BITMAP_H
#define _BITMAP_H
 #include <time.h>
 #include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/* 位图四个宏介绍：
 * 
 * @BITMAP:创建一个位图
 * @BIT_ZERO:清空位图所有标记位
*  @BIT_SET:设置位图中标记位
*  @BIT_CLR:清除位图中标记位
*  @BIT_ISSET:检测位图中标记位
*  */
typedef unsigned int BITMAP[100];
#define BIT_ZERO(a)                                     \
        do{                                             \
            for(int i = 0;i < 100;i++)                 \
                *(a+i)=0;                               \
        }while(0)              

#define BIT_SET(a,x)                                    \
        do{                                             \
            *(a+x/32) |= (1<< (x%32) );                 \
        }while(0)              

#define BIT_ISSET(a,x)  ( (*(a+x/32)&(1<< (x%32) )))

#define BIT_CLR(a,x)                                    \
        do{                                             \
            *(a+x/32) &=~(1<<(x%32));                   \
          }while(0)
#endif
