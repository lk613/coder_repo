#ifndef DETECT_CYCLE_LINKLIST
#define DETECT_CYCLE_LINKLIST
#include <stdbool.h>
#include <stdlib.h>
#include "list_node.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head);

struct ListNode *detectCycle(struct ListNode *head);

#endif