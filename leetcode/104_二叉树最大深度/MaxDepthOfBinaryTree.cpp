#include "MaxDepthOfBinaryTree.h"

TreeNode *CreateBinaryTree(std::vector<int> &vec)
{
    if (vec.empty() || vec[0] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(vec[0]);
    std::queue<TreeNode *> queue;
    queue.push(root);

    int i = 1;
    while (i < vec.size())
    {
        TreeNode *cur = queue.front();
        queue.pop();

        // left tree
        if (i < vec.size() && vec[i] != -1)
        {
            cur->left = new TreeNode(vec[i]);
            queue.push(cur->left);
        }
        i++;

        // right tree
        if (i < vec.size() && vec[i] != -1)
        {
            cur->right = new TreeNode(vec[i]);
            queue.push(cur->right);
        }
        i++;
    }

    return root;
}

int MaxDepthOfBinaryTree(TreeNode *root)
{
    std::queue<TreeNode*> bt_level;
    if (root == nullptr)
    {
        return 0;
    }
    int depth = 0;
    bt_level.push(root);
    
    while (!bt_level.empty())
    {
        int cur_level_size = bt_level.size();
        for (int i = 0; i < cur_level_size; i++)
        {
            TreeNode *cur_node = bt_level.front();
            bt_level.pop();
            
            if (cur_node->left != nullptr)
            {
                bt_level.push(cur_node->left);
            }

            if (cur_node->right != nullptr)
            {
                bt_level.push(cur_node->right);
            }
        }

        depth += 1;
    }

    return depth;
}