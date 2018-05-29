#include <stdio.h>
#include <stdlib.h>
void Swap(char *p1,char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Permutation(char *str,char *pBegin)
{
    if(*pBegin == '\0')
        printf("%s\n",str);
    for(char *p = pBegin;*p != '\0';p++)
    {
        Swap(p,pBegin);
        Permutation(str,pBegin+1);
        Swap(p,pBegin);
    }
}

int main()
{
    char str[] = "abc";
    Permutation(str,str);

}
