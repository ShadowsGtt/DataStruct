#ifndef _LIST_H
#define _LIST_H
#include<stdio.h>
#include <stdlib.h>
#define ValueType int



typedef struct ListNode
{
    ValueType value;
    struct ListNode *next;
}ListNode_t;

typedef struct List
{
    ListNode_t *head;
    ListNode_t *tail;
    int count;
    int IsHead;
}List_t;

List_t *CreatListWithHead();
List_t *CreatListWithoutHead();
int InsertIntoNoHeadListByHead(List_t *list,ValueType value);
int InsertIntoNoHeadListByTail(List_t *list,ValueType value);
int InsertIntoHeadListByHead(List_t *list,ValueType value);
int InsertIntoHeadListByTail(List_t *list,ValueType value);
void PrintList(List_t *list);
List_t *ExampleList();

#endif
