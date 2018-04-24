/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月13日 星期五 11时16分06秒
 ************************************************************************/

#include<stdio.h>
#include <gtlist.h>

void PrintListTailToHead()
{
    List_t *list = ExampleList();
    printf("初始链表：");
    PrintList(list);

    printf("倒着打印[方法1]:\n");
    
    ListNode_t *stack[20] = {NULL};
    int i = 0;
    ListNode_t *cur = list->head;
    
    while(cur != NULL)
    {
        stack[++i] = cur;
        cur = cur->next;
    }
    while(stack[i] != NULL)
        printf("%-4d",(stack[i--])->value);
    putchar(10);
}
void PrintListTailToHead2(List_t *list,ListNode_t *node)
{
    if(NULL == list)
        return;
    if(NULL == node)
        return;
    PrintListTailToHead2(list,node->next);
    printf("%d-->",node->value);
}

int main()
{
    PrintListTailToHead();
    List_t *list = ExampleList();


    putchar(10);
    putchar(10);
    printf("初始链表：\n");
    PrintList(list);


    printf("倒着打印[方法2]:\n");
    PrintListTailToHead2(list,list->head);
    putchar(10);

}
