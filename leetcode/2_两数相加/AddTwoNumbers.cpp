#include "AddTwoNumbers.h"

#if 1
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *new_head = new ListNode(-1);
    ListNode *cur_node = new_head;
    int sum_val = 0;
    int add_bit = 0;
    int quorient = 0;
    int remainder = 0;
    while (l1 || l2)
    {
        int val_1 = (l1 != NULL) ? l1->val : 0;
        int val_2 = (l2 != NULL) ? l2->val : 0;

        sum_val = (val_1 + val_2 + add_bit);
        quorient = sum_val / 10;
        remainder = sum_val % 10;
        add_bit = (quorient == 1) ? 1 : 0;
        cur_node->next = new ListNode(remainder);

        cur_node = cur_node->next;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }

    if (add_bit > 0)
    {
        cur_node->next = new ListNode(add_bit);
    }

    return new_head->next;
}
#else
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *new_head = new ListNode(-1);
    ListNode *cur_node = new_head;
    ListNode *p_node1 = l1;
    ListNode *p_node2 = l2;
    int add_bit_num = 0;
    int quotient = 0;
    int remainder = 0;
    int sum_val = 0;
    while (p_node1 && p_node2)
    {
        sum_val = p_node1->val + p_node2->val + add_bit_num;
        quotient = sum_val / 10;
        remainder = sum_val % 10;

        cur_node->next = new ListNode(remainder);
        add_bit_num = (quotient == 1) ? 1 : 0;
        cur_node = cur_node->next;
        p_node1 = p_node1->next;
        p_node2 = p_node2->next;
    }

    while (p_node1)
    {
        sum_val = p_node1->val + add_bit_num;
        quotient = sum_val / 10;
        remainder = sum_val % 10;

        cur_node->next = new ListNode(remainder);
        add_bit_num = (quotient == 1) ? 1 : 0;
        cur_node = cur_node->next;
        p_node1 = p_node1->next;
    }

    while (p_node2)
    {
        sum_val = p_node2->val + add_bit_num;
        quotient = sum_val / 10;
        remainder = sum_val % 10;

        cur_node->next = new ListNode(remainder);
        add_bit_num = (quotient == 1) ? 1 : 0;
        cur_node = cur_node->next;
        p_node2 = p_node2->next;
    }

    if (add_bit_num == 1)
    {
        cur_node->next = new ListNode(1);
    }

    return new_head->next;
}
#endif

void PrintVector(std::vector<int> &array)
{
    std::cout << "当前数组为： " << std::endl;

    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void PrintLinkList(ListNode *head)
{
    ListNode *temp = head;
    std::cout << "当前链表为: " << std::endl;
    while (temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

ListNode* CreateLinkList(std::vector<int> &array)
{
    ListNode *head = new ListNode(array[0]);
    ListNode *cur_node = head;
    for (int i = 1; i < array.size(); i++)
    {
        cur_node->next = new ListNode(array[i]);
        cur_node = cur_node->next;
    }

    return head;
}

void TestLeetcode2()
{
#if 1
    std::vector<int> vec1 = {9,9,9,9,9,9,9};
    std::vector<int> vec2 = {9,9,9,9};
#else
    std::vector<int> vec1 = {2,4,3};
    std::vector<int> vec2 = {5,6,4};
#endif
    PrintVector(vec1);
    PrintVector(vec2);

    ListNode* l1 = CreateLinkList(vec1); 
    ListNode* l2 = CreateLinkList(vec2);

    ListNode *sum_list = addTwoNumbers(l1, l2);
    PrintLinkList(sum_list);
}