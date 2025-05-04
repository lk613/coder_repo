#ifndef COPY_RANDOM_LIST
#define COPY_RANDOM_LIST
#include <iostream>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head);

#endif