#include<stdio.h>


void ReplaceBlank(char *str)
{
    if(NULL == str)
        return;
    
    char *p1 = str;
    char *p2 = str;
    int count = 0;
    
    while(*p1 != 0)
    {
        if(*p1 == ' ')
            count += 2;
        p1++;
        p2++;
    }
    if(count == 0)
        return;
    p2 += count;
    while(p1 != p2)
    {
        if(*p1 == ' ')
        {
            *p2-- = '0';
            *p2-- = '2';
            *p2-- = '%';
            p1--;
        }
        else
        {
            *p2 = *p1;
            p2--;
            p1--;
        }
    }

}
void test(char *str)
{
    if(NULL == str)
        return;
    ReplaceBlank(str);
    printf("%s\n",str);
}

/* 类似拓展题 */
void MergeTwoSortArry(int *arry1,int *arry2,int n1,int n2)
{
    if(NULL == arry1 || NULL == arry2)
        return;
    if(0 == n1 && 0 == n2)
        return;

    int p1 = n1 - 1;
    int p2 = n1 + n2 - 1;
    int p3 = n2 - 1;

    while(p2 >= 0)
    {
        if(p1 >= 0 && p3 >= 0)
        {
            if(arry1[p1] >= arry2[p3])
            {
                arry1[p2] = arry1[p1];
                p1--;

            }
            else if(arry1[p1] < arry2[p3])
            {
                arry1[p2] = arry2[p3];
                p3--;
            }
        }
        else if(p1 >= 0 && p3 <0)
        {
            break;
        }
        else if(p3 >= 0 && p1 < 0)
        {
            arry1[p2] = arry2[p3];
            p3--;
        }
        p2--;
    }


}


int main()
{
    char str1[50] = "i am a student ";
    char str2[50] = "  ";
    char str3[50] = "    ";
    char str4[50] = "hello";

    test(str1);
    test(str2);
    test(str3);
    test(str4);

    int a[12] = {1,4,7,8,10,11,13};
    int b[5] = {0,5,9,12,13};
    MergeTwoSortArry(a,b,7,5);
    for(int i = 0;i < 12;i++)
        printf("%-4d",a[i]);
    putchar(10);
}
