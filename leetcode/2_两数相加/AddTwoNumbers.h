#ifndef ADD_TWO_NUMBERS
#define ADD_TWO_NUMBERS
#include <iostream>
#include <vector>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

ListNode* CreateLinkList(std::vector<int> &array);

void PrintVector(std::vector<int> &array);

void PrintLinkList(ListNode *head);

void TestLeetcode2();

#endif
