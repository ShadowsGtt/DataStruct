#include <gtlist.h>
/* 创建带头结点的链表 */
List_t *CreatListWithHead()
{
    List_t *list = (List_t *)malloc(sizeof(List_t));
    if(NULL == list)
        return NULL;

    ListNode_t *head = (ListNode_t *)malloc(sizeof(ListNode_t));
    if(NULL == head)
        return NULL;
    head->next = NULL;
    head->value = 0;

    list->head = head;
    list->tail = NULL;
    list->count = 0;
    list->IsHead = 1;

    return list;
}

List_t *CreatListWithoutHead()
{
    List_t *list = (List_t *)malloc(sizeof(List_t));
    if(NULL == list)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->IsHead = 0;

    return list;
}

int InsertIntoNoHeadListByHead(List_t *list,ValueType value)
{
    if(NULL == list)
        return -1;
    if(1 == list->IsHead)
        return -1;
    
    ListNode_t *node = (ListNode_t *)malloc(sizeof(ListNode_t));
    if(NULL == node)
        return -1;
    node->next = NULL;
    node->value = value;

    if(0 == list->count)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->count++;
    return 0;
    
}

int InsertIntoNoHeadListByTail(List_t *list,ValueType value)
{
    if(NULL == list)
        return -1;
    if(1 == list->IsHead)
        return -1;

    ListNode_t *node = (ListNode_t *)malloc(sizeof(ListNode_t));
    if(NULL == node)
        return -1;
    node->next = NULL;
    node->value = value;

    if(0 == list->count)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
    return 0;
    
}
int InsertIntoHeadListByHead(List_t *list,ValueType value)
{
    if(NULL == list)
        return -1;
    if(0 == list->IsHead)
        return -1;
    
    ListNode_t *node = (ListNode_t *)malloc(sizeof(ListNode_t));
    if(NULL == node)
        return -1;
    node->next = NULL;
    node->value = value;

    if(0 == list->count)
    {
        list->head->next = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head->next;
        list->head->next = node;
    }
    list->count++;
    return 0;
}
int InsertIntoHeadListByTail(List_t *list,ValueType value)
{
    if(NULL == list)
        return -1;
    if(0 == list->IsHead)
        return -1;
    
    ListNode_t *node = (ListNode_t *)malloc(sizeof(ListNode_t));
    if(NULL == node)
        return -1;
    node->next = NULL;
    node->value = value;

    if(0 == list->count)
    {
        list->head->next = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
    return 0;
}

void PrintList(List_t *list)
{
    if(NULL == list)
        return;
    if(0 == list->count)
        return;

    putchar(10);
    ListNode_t *cur = NULL;
    if(0 == list->IsHead)
    {
        cur = list->head;
        while(cur != NULL)
        {
            printf("%d-->",cur->value);
            cur = cur->next;
        }
    }
    else
    {
        cur = list->head->next;
        while(cur != NULL)
        {
            printf("%d-->",cur->value);
            cur = cur->next;
        }
    }
    putchar(10);
    return;

}
List_t *ExampleList()
{
    List_t *list = CreatListWithoutHead();
    if(NULL == list)
        return NULL;
    InsertIntoNoHeadListByHead(list,2);
    InsertIntoNoHeadListByHead(list,4);
    InsertIntoNoHeadListByTail(list,5);
    InsertIntoNoHeadListByHead(list,6);

    return list;
}
