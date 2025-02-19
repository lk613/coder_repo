#include "detect_cycle_linklist.h"

bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = slow->next;

    while (slow != fast)
    {
        if ((fast == NULL) || (fast->next == NULL))
        {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

#ifdef LEETCODE_STYLE
/* deepseek思路*/
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while ((fast != NULL) && (fast->next != NULL))
    {
        fast = fast->next->next;
        slow = slow->next;

        /* 快慢指针相遇 */
        if (fast == slow)
        {
            struct ListNode *ptr1 = head;
            struct ListNode *ptr2 = slow;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
    }

    return NULL;
}

#else
struct ListNode *getNodeInLoop(struct ListNode *head)
{
    if ((head == NULL) || (head->next == NULL))
    {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (slow != fast)
    {
        if ((fast == NULL) || (fast->next == NULL))
        {
            return NULL;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *meet_node = getNodeInLoop(head);
    if (NULL == meet_node)
    {
        return NULL;
    }

    struct ListNode *fast = meet_node;
    struct ListNode *slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
#endif
