#include "first_common_node.h"

static int GetLinkListLength(struct ListNode *head);

static int GetLinkListLength(struct ListNode *head)
{
    int len = 0;

    if (head == NULL)
    {
        return len;
    }

    struct ListNode *cur_node = head;
    while (NULL != cur_node)
    {
        len = len + 1;
        cur_node = cur_node->next;
    }    

    return len;
}

#if 1
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2)
{
    int count1 = GetLinkListLength(pHead1);
    int count2 = GetLinkListLength(pHead2);

    int diff = abs(count1 - count2);
    struct ListNode *longer_list = (count1 > count2) ? pHead1 : pHead2;
    struct ListNode *shorter_list = (count1 > count2) ? pHead2 : pHead1;

    for (int i = 0; i < diff; i++)
    {
        longer_list = longer_list->next;
    }

    while (longer_list != shorter_list)
    {
        longer_list = longer_list->next;
        shorter_list = shorter_list->next;
    }

    return shorter_list;
}
#else
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2 )
{
    struct ListNode *cur_node_1 = pHead1;
    struct ListNode *cur_node_2 = pHead2;

    int len_linklist_1 = GetLinkListLength(pHead1);
    int len_linklist_2 = GetLinkListLength(pHead2);

    int len_diff = abs(len_linklist_1 - len_linklist_2);
    bool list1_fst = (len_linklist_1 - len_linklist_2 > 0) ? true : false;
    int count = 0;

    if (list1_fst)
    {
        while (count < len_diff)
        {
            cur_node_1 = cur_node_1->next;
            count++;
        }
    }else
    {
        while (count < len_diff)
        {
            cur_node_2 = cur_node_2->next;
            count++;
        }
    }

    while (cur_node_1 != cur_node_2)
    {
        if (cur_node_1 == NULL || cur_node_2 == NULL)
        {
            return NULL;
        }

        cur_node_1 = cur_node_1->next;
        cur_node_2 = cur_node_2->next;
    }

    return cur_node_1;
}
#endif