#include "InverseLinklist.h"

#ifndef RECURSIVE_ALGO
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *preNode = NULL;
    ListNode *nextNode = NULL;
    ListNode *curNode = head;

    while (curNode != NULL)
    {
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }

    return preNode;
}
#else
ListNode* reverseList(ListNode* head) {
    ListNode *pNode = head;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *newHead = reverseList(pNode->next);
    ListNode *preNode = newHead;
    while (preNode->next != NULL)
    {
        preNode = preNode->next;
    }

    preNode->next = pNode;
    pNode->next = NULL;

    return newHead;
}
#endif