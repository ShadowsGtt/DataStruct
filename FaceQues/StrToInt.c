#include <stdio.h>
#include <stdlib.h>

/* 全局变量，用来检测返回值为0时
 * 是非法参数还是字符串的值本来就是0
 * status为1:非法参数传入,函数返回0
 * status为0:字符串的值为0  
 * */
enum 
{
    SUCCESS,        /* 错误码默值 */
    NULLSTR,        /* 空str */
    INLEGELSTR,     /* str中含有非数字字符 */
}atio_error = SUCCESS;


int StrToInt(const char *str)
{
    if(NULL == str || '\0' == *str)
    {
        atio_error = NULLSTR;
        return 0;
    }
    
    int flag = 1;
    int number = 0;

    if('-' == *str)
    {
        flag = -1;
        str++;
    }
    if('+' == *str)
        str++;
    while(*str != '\0')
    {
        if(*str <= '9' && *str >= '0')
        {
            number = number*10 + *str - '0';
            str++;
        }
        else
        {
            atio_error = INLEGELSTR;
            return 0;
        }
    }

    return number*flag;
}

int main()
{
    char str1[] = "0123";
    char str2[] = "";
    char str4[] = "-123";
    char str5[] = "+346";
    char *str3 = 0;
    printf("%d\n",    StrToInt(str1));
    printf("%d\n",    StrToInt(str2));
    printf("%d\n",   StrToInt(str3));
    printf("%d\n",  StrToInt(str4));
    printf("%d\n", StrToInt(str5));
    return  0;
}
