#include "LinkListSwapPairs.h"

ListNode* swapPairs(ListNode* head) {
    ListNode *pre_head = new ListNode(-1);
    pre_head->next = head;
    ListNode *pre_node = pre_head;

    while (pre_node->next != nullptr && pre_node->next->next != nullptr)
    {
        ListNode *fst_node = pre_node->next;
        ListNode *snd_node = pre_node->next->next;
        pre_node->next = snd_node;
        fst_node->next = snd_node->next;
        snd_node->next = fst_node;
        pre_node = fst_node;
    }

    ListNode *ret =  pre_head->next;
    delete pre_head;
    return ret;
}