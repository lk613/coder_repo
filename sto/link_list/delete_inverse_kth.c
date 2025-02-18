#include "delete_inverse_kth.h"

/**
 * @brief 面试题21： 删除倒数第k个节点 （要求只能遍历一遍链表）
 *        双指针法（前后双指针）
 * @param pHead 
 * @param k 
 * @return struct ListNode* 
 */
#ifdef LEETCODE_STYLE
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *first = head;
    struct ListNode *second = dummy;

    for (int i = 0; i < n; i++)
    {
        first = first->next;
    }

    while (first)
    {
        first = first->next;
        second = second->next;
    }   /* first pointer rear node next node(Null node)*/

    second->next = second->next->next;
    struct ListNode *ret = dummy->next;
    free(dummy);
    return ret;
}
#else
struct ListNode* DeleteInverseKth(ListNode *pHead, int k)
{
    ListNode *guard_node = (ListNode *)malloc(sizeof(ListNode));
    if (NULL == guard_node)
    {
        return NULL;
    }
    guard_node->val = 0;
    guard_node->next = pHead;

    ListNode *front_node = pHead;
    ListNode *after_node = pHead;

    for (int i = 0; i < k; i++)
    {
        front_node = front_node->next;
    }

    while (NULL != front_node->next)
    {
        front_node = front_node->next;
        after_node = after_node->next;
    }

    after_node->next = after_node->next->next;

    return guard_node->next;
}
#endif