#include "Symmetric.h"
#include <queue>

#ifdef RECURSIVE_ALGO
bool isSymmetric(TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    std::queue<TreeNode *> node_queue;
    TreeNode *fst_node = root->left;
    TreeNode *snd_node = root->right;
    node_queue.push(fst_node);
    node_queue.push(snd_node);

    while (!node_queue.empty())
    {
        fst_node = node_queue.front();
        node_queue.pop();
        snd_node = node_queue.front();
        node_queue.pop();

        if (fst_node == NULL && snd_node == NULL)
        {
            continue;
        }

        if (fst_node == NULL || snd_node == NULL)
        {
            return false;
        }

        if (fst_node->val != snd_node->val)
        {
            return false;
        }

        node_queue.push(fst_node->left);
        node_queue.push(snd_node->right);
        node_queue.push(fst_node->right);
        node_queue.push(snd_node->left);
    }

    return true;
}

#else
bool recursive(TreeNode *left, TreeNode * right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }

    if (left == NULL || right == NULL)
    {
        return false;
    }

    if (left->val != right->val)
    {
        return false;
    }

    return recursive(left->left, right->right) && recursive(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    return recursive(root->left, root->right);
}
#endif