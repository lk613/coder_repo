#ifndef INTERSECT_LINKLIST
#define INTERSECT_LINKLIST

#include <stddef.h>

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

#endif