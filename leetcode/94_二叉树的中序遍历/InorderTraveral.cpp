#include "InorderTraveral.h"
#include <stack>

#ifndef RECURSIVE_ALGO
// 迭代算法： iterative algorithm (使用栈数据结构)
std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> result_list;
    TreeNode *cur_node = root;
    std::stack<TreeNode *> stacks;
    // stacks.push(root);

    while (cur_node != NULL || (!stacks.empty()))
    {
        if (cur_node != NULL)
        {
            stacks.push(cur_node);
            cur_node = cur_node->left;
        }else
        {
            cur_node = stacks.top();
            stacks.pop();
            result_list.push_back(cur_node->val);
            cur_node = cur_node->right;
        }
    }

    return result_list;
}
#else
// 递归解法: recursive algorithm
static void Inorder(TreeNode *root, std::vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left, result);
    result.push_back(root->val);
    Inorder(root->right, result);
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> result_list;
    Inorder(root, result_list);
    return result_list;
}
#endif
