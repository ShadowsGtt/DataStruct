#include <stdio.h>
/* 实现pow函数
 * 即求一个数字的n次方*/

int invailed = 0;
double my_pow(double num,int exp)
{
    if(num == 0.0)
    {
        invailed = 1;
        return  0;
    }
    if(num == 1 || exp == 0)
        return 1;
}

double Power(double num,unsigned exp)
{
    if(exp == 1)
        return num;
    if(exp == 0)
        return 1;
    int result = Power(num,exp >> 1);
    if(exp & 0x1)
        return result*num*result;
    return result*result;
}
int main()
{
    printf("3,4:%f\n",my_pow(3,6));
    printf("-3,3:%f\n",my_pow(-3,3));
    printf("-3,0:%f\n",my_pow(-3,0));
    printf("-3,-2:%f\n",my_pow(-3,-2));
}
