#include "MergeTwoLists.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
        ListNode *new_head = new ListNode(-1);
        ListNode *cur_node = new_head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur_node->next = new ListNode(list1->val);
                cur_node = cur_node->next;
                list1 = list1->next;
            }else
            {
                cur_node->next = new ListNode(list2->val);
                cur_node = cur_node->next;
                list2 = list2->next;
            }
        }

        if (list1)
        {
            cur_node->next = list1;
        }

        if (list2)
        {
            cur_node->next = list2;
        }

        return new_head->next;
}