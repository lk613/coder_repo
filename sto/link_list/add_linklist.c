#include "add_linklist.h"

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * @brief inverse linklist
 * @param head ListNode
 * @return ListNode
 */
static struct ListNode *ReverseLinkList(struct ListNode *head);

static struct ListNode *ReverseLinkList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *pre_node = NULL;
    struct ListNode *cur_node = head;
    struct ListNode *next_node = NULL;

    while (cur_node != NULL)
    {
        next_node = cur_node->next;
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
    }

    return pre_node;
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param head1 ListNode类 
 * @param head2 ListNode类 
 * @return ListNode类
 */
#if 1
struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2)
{
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    dummy->val = 0;

    struct ListNode *cur_node = dummy;
    int carry = 0;
    int sum_two = 0;
    struct ListNode* inverse_head_1 = ReverseLinkList(head1);
    struct ListNode* inverse_head_2 = ReverseLinkList(head2);
    while (inverse_head_1 != NULL || inverse_head_2 != NULL)
    {
        sum_two = ((inverse_head_1 != NULL) ? inverse_head_1->val : 0) + ((inverse_head_2 != NULL) ? inverse_head_2->val : 0) + carry;
        sum_two = (sum_two >= 10) ? (sum_two - 10) : sum_two;
        carry = (sum_two >= 10) ? 1 : 0;

        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        new_node->next = NULL;
        new_node->val = sum_two;

        cur_node->next = new_node;
        cur_node = cur_node->next;

        inverse_head_1 = (inverse_head_1 == NULL) ? NULL : inverse_head_1->next;
        inverse_head_2 = (inverse_head_2 == NULL) ? NULL : inverse_head_2->next;
    }

    if (carry > 0)
    {
        struct ListNode *temp_node = malloc(sizeof(struct ListNode));
        temp_node->next = NULL;
        temp_node->val = carry;
        cur_node->next = temp_node;
    }

    return ReverseLinkList(dummy->next);
}
#else
struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2 ) {
    // write code here
    struct ListNode* inverse_head_1 = ReverseLinkList(head1);
    struct ListNode* inverse_head_2 = ReverseLinkList(head2);

    struct ListNode *ptr1 = inverse_head_1;
    struct ListNode *ptr2 = inverse_head_2;
    int sum_two = 0;
    int carry_num = 0;
    struct ListNode *new_dummy = NULL;
    struct ListNode *cur_node = NULL;
    struct ListNode * remain_node = NULL;
    bool create_new_head = false;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        sum_two = ptr1->val + ptr2->val + carry_num;
        sum_two = (sum_two > 10) ? (sum_two - 10) : sum_two;
        carry_num = (sum_two > 10) ? (sum_two % 10) : 0;

        if (false == create_new_head)
        {
            cur_node = malloc(sizeof(ListNode));
            cur_node->next = NULL;
            cur_node->val = sum_two;

            new_dummy->next = cur_node;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        
        struct ListNode *temp_node = malloc(sizeof(ListNode));
        temp_node->val = sum_two;
        temp_node->next = NULL;
        cur_node->next = temp_node;
        cur_node = cur_node->next;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == NULL && ptr2 == NULL)
    {
        if (carry_num != 0)
        {
            struct ListNode *temp_node = malloc(sizeof(ListNode));
            temp_node->val = carry_num;
            temp_node->next = NULL;
            cur_node->next = temp_node;
        }
    }else
    {
        int carry_num_cpy = carry_num;
        remain_node = (ptr1 != NULL) ? ptr1 : ptr2;

        if (carry_num_cpy != 0)
        {
            sum_two = remain_node->val + carry_num;
            sum_two = (sum_two > 10) ? (sum_two - 10) : sum_two;
            carry_num = (sum_two > 10) ? (sum_two % 10) : 0;

            while (carry_num != 0)
            {

            }

        }else
        {
            cur_node->next = remain_node;
        }
    }
}
#endif