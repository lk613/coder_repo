#include "CopyRandomList.h"
#include <unordered_map>

#if 1
Node* copyRandomList(Node* head)
{
    std::unordered_map<Node *, Node *> map;
    Node *cur = head;

    // reverse , generate hash table
    while (cur != NULL)
    {
        map[cur] = new Node(cur->val);
        cur = cur->next;
    }

    // link copy node
    cur = head;
    while (cur != NULL)
    {
        map[cur]->next = map[cur->next];
        map[cur]->random = map[cur->random];
        cur = cur->next;
    }

    return map[head];
}
#else
Node* copyRandomList(Node* head)
{
    Node pre_head(-1);
    Node *new_head = &pre_head;
    Node *cur_node = new_head;
    Node *node_t = head;

    while (node_t)
    {
        cur_node->next = &Node(node_t->val);
        node_t = node_t->next;
        cur_node = cur_node->next;
    }

    Node *old_t = head;
    Node *new_t;
    node_t = head;
    cur_node = new_head->next;
    int step = 0;
    while (node_t)
    {
        step = 0;
        new_t = new_head->next;
        Node *temp = node_t->random;
        while (old_t != temp)
        {
            old_t = old_t->next;
            step++;
        }

        for (int i = 0; i < step; i++)
        {
            new_t = new_t->next;
        }

        cur_node->random = new_t;
        cur_node = cur_node->next;
        node_t = node_t->next;
    }

    return new_head->next;
}
#endif