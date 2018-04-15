/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 10时09分47秒
 ************************************************************************/

#include<stdio.h>
/* 
* @row:行数
* @column:列数
* @number:寻找的目标数
* */
int Find(int (*a)[4],int row,int column,int number)
{
    if(NULL == a || row <= 0 || column <= 0)
        return -1;
    int r = 0;
    int c = column - 1;
    
    while(r < row && c >= 0)
    {
        if(a[r][c] == number)
            return 0;
        else if(a[r][c] > number)
            c--;
        else if(a[r][c] < number)
            r++;
    }
    return -1;
}
int main()
{
    int a[4][4] = \
    {   {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}
    };
    int b[4][4] = \
    {   {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    //printf("%d\n",(*(p+1)) );
    if( Find(a,4,4,15) == 0 )
        printf("found\n");
    else
        printf("not found\n");
}

