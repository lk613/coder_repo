#ifndef INVERSE_LINKLIST
#define INVERSE_LINKLIST
#include <iostream>

#ifdef RECURSIVE_ALGO
#define RECURSIVE_ALGO
#endif

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head);


#endif