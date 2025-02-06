#include "reverse_linklist.h"

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode *GenerateList(int *arr, int len);
void PrintList(struct ListNode *phead);
struct ListNode *ReverseList(struct ListNode *head);

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
    while (cur)
    {
        /* code */
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
    return;
}

struct ListNode *ReverseList(struct ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *next = NULL;

    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

