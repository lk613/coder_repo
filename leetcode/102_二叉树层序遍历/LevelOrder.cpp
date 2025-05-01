#include "InorderTraveral.h"
#include <queue>

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> result;
    if (root == NULL)
    {
        return result;
    }
    std::queue<TreeNode *> node_queue;
    TreeNode *cur_node = root;
    node_queue.push(root);

    while (!node_queue.empty())
    {
        int level_size = node_queue.size();
        std::vector<int> level_elem;

        for (int i = 0; i < level_size; i++)
        {
            cur_node = node_queue.front();
            level_elem.push_back(cur_node->val);
            node_queue.pop();

            if (cur_node->left != NULL)
            {
                node_queue.push(cur_node->left);
            }

            if (cur_node->right != NULL)
            {
                node_queue.push(cur_node->right);
            }
        }

        result.push_back(level_elem);
    }

    return result;
}