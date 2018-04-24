#include<stdio.h>

void *my_memcpy(void *dst,void *src,unsigned len)
{
    if(dst == src || NULL == dst || NULL == src || 0 == len)
        return NULL;

    void *ret = dst;
    unsigned nblock = len / sizeof(dst);
    unsigned nleft  = len % sizeof(dst);
    unsigned long *d = (unsigned long  *)dst;
    unsigned long *s = (unsigned long  *)src;

    /* 内存重叠
    * 只有当目的内存占据源内存尾的时候才从后往前复制
    * */
    if(dst > src && (char *)src + len > (char *)dst)
    {
        d = (unsigned long *)((char *)dst + len -1);
        s = (unsigned long *)((char *)src + len -1);
        while(nblock--)
            *d-- = *s--;
        dst = (char *)d;
        src = (char *)s;
        while(nleft--)
            *(char *)dst-- = *(char *)src--;
    }
    else
    {
        d = (unsigned long *)(char *)dst;
        s = (unsigned long *)(char *)src;
        while(nblock--)
            *d++ = *s++;
        dst = (char *)d;
        src = (char *)s;
        while(nleft--)
            *(char *)dst++ = *(char *)src++;
    }
    return ret;
}
void test()
{
    char a[100] = "hello,world,hello,world";
    char b[100] = {0};
    
    /* 测试无重叠 */
    if(my_memcpy(b,a,15) != NULL )
        printf("%s\n",b);
    /* 测试有重叠*/
    if(my_memcpy(a+4,a,5) != NULL )
        printf("%s\n",a);
    
}

int main()
{
    test();
}
