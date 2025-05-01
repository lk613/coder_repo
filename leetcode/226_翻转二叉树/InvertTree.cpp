#include "InvertTree.h"

TreeNode* invertTree(TreeNode* root)
{
    if (root == NULL)
    {
        return root;
    }

    TreeNode *left_child = invertTree(root->left);
    TreeNode *right_child = invertTree(root->right);

    root->left = right_child;
    root->right = left_child;

    return root;
}