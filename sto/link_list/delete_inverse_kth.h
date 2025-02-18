#include <stdio.h>
#include "list_node.h"
#ifdef LEETCODE_STYLE
struct ListNode *removeNthFromEnd(struct ListNode *head, int n);
#else
extern struct ListNode* DeleteInverseKth(ListNode *pHead, int k);
#endif