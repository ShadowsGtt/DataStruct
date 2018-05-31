#include <stdio.h>
#include <stdlib.h>
void Swap(char *p1,char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


/* 全排列递归代码 */
void Perm(char * str,char *pHead)
{
    if(*pHead == '\0')
        printf("%s\n",str);
    else
    {
        for(char *p = pHead; *p != 0 ; p++)
        {
            if(p == pHead ||  *p != *pHead)
            {
                Swap(p,pHead);
                Perm(str,pHead+1);
                Swap(p,pHead);

            }
        }
    }

}
void foo(char *str)
{
    Perm(str,str);
}


int main()
{
    char str[] = "aac";
    foo(str);

}
