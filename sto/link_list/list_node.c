#include "list_node.h"

struct ListNode *GenerateList(int *arr, int len)
{
    if (arr == NULL || (len <= 0))
    {
        return NULL;
    }

    ListNode *pHead = (ListNode *)malloc(sizeof(ListNode));
    if (NULL == pHead)
    {
        return NULL;
    }
    pHead->val = 0;
    pHead->next = NULL;
    ListNode *cur_node = pHead;

    for (int i = 0; i < len; i++)
    {
        ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
        if (NULL == pHead)
        {
            return NULL;
        }

        new_node->val = arr[i];
        new_node->next = NULL;
        cur_node->next = new_node;
        cur_node = cur_node->next;
    }

    return pHead->next;
}


void PrintList(struct ListNode *phead)
{
    if (phead == NULL)
        return;
    
    ListNode *cur = phead;
    while (NULL != cur)
    {
        /* code */
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
    return;
}

