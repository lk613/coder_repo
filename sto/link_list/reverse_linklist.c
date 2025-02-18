#include "reverse_linklist.h"

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

