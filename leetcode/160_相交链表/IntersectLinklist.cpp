#include "IntersectLinklist.h"
#include <math.h>
#include <unordered_set>

#if 1
// hash table 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    std::unordered_set<ListNode *> hash_table;
    while (headA)
    {
        hash_table.insert(headA);
        headA = headA->next;
    }

    while (headB)
    {
        if (hash_table.count(headB))
        {
            return headB;
        }
        headB = headB->next;
    }

    return NULL;
}
#else
// two pointer
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    
    ListNode *node_a = headA;
    ListNode *node_b = headB;
    int length1 = 0;
    int length2 = 0;
    while (node_a)
    {
        length1 += 1;
        node_a = node_a->next;
    }
    while (node_b)
    {
        length2 += 1;
        node_b = node_b->next;
    }

    ListNode *fast = (length1 > length2) ? headA : headB;
    ListNode *slow = (length1 > length2) ? headB : headA;

    int len_diff = abs(length1 - length2);
    for (int i = 0; i < len_diff; i++)
    {
        fast = fast->next;
    } 

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
#endif