#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <stdlib.h>             // NULL
#include <stdio.h>              //printf

#ifndef LEETCODE_STYLE
#define LEETCODE_STYLE
#endif
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode *GenerateList(int *arr, int len);
void PrintList(struct ListNode *phead);


#endif

