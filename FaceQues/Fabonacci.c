#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*        fabonacci数列(兔子数列)
 *
 * fabonacci数列简介:第一项第二项值为1
 * 后面每一项都是前两项的和
 *  1  1  2  3  5  8  13  21
 *  问题：编写递归与非递归函数求fabonacci第n项的值
 * 
 * */


/* 递归程序：时间复杂度为O(2^n)  */
 int fabonacci1(int n)
 {
    assert(n > 0);
    if(n == 1 || n == 2)
        return 1;
    return fabonacci1(n-1)+fabonacci1(n-2);
 }

 /* 非递归程序 
  * 时间复杂度为：O(n)
  * */

 int fabonacci2(int n)
 {
    assert(n > 0);

     int pre = 1;
     int cur = 1;
     int next = 0;

     for(int i = 3;i <= n;i++)
     {
         next = pre + cur;
         pre = cur;
         cur = next;
     }
     return next;
 }

 int main()
 {
     printf("fabonacci1[NO.%d]%d\n",6,fabonacci1(6));
     printf("fabonacci1[NO.%d]%d\n",6,fabonacci2(6));
    
 }
