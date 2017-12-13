 /*
  
 hash函数的开放地址法思想：
    前提：hash 数组大小为lenth 用户输入的数据为 num ,数组下标用key表示
 一.存放数据
    使用hash函数得到存放数据的下标过程:
        1.key = num % lenth;
        2.判断a[key]是否已经存放数据
            <1>如果a[key]已经存放数据,则key = (key+1)%lenth,
               然后继续执行第2步,直到找到一处未存放数据地方,
               或者所有位置都已经满返回失败
            <2>如果a[key]未存放数据,则a[key] = num
二.得到hash函数存放数据的下标(查找数据)
    使用hash函数得到存放数据的下标过程:
        1.key = num % lenth;
        2.判断a[key]是否等于要查询的数据
            <1>如果是,返回key
            <2>如果不是，则key = (key+1)%lenth,继续执行2




  */

#include<stdio.h>
#include<stdlib.h>
int HashFind(int a[],int num,int lenth)
{
    int loop = 0;
    int key = num%lenth;
    if(a[key] == num)
        return key;
    while(a[key] != num )
    {
        if(loop == lenth)
        {
            printf("not find\n");
            return -1;
        }
        key = (key+1)%lenth;
        loop ++;
    }
    return key;


}
void HashSave(int a[],int num,int lenth)
{
    int loop = 0;
    int key = num%lenth;
    while(a[key] != 0)
    {
        key = (key+1)%lenth;
        loop ++;
        if(loop == lenth)
        {
            printf("full!\n");
            exit(0);
        }
    }
    a[key] = num;
}
int main()
{
    int a[10] = {0};
    int lenth = sizeof(a)/sizeof(int);
    return 0;
}
